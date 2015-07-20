#include "CArena.hpp"
#include "CPlayer.hpp"
#include "CEnemy.hpp"
#include "CBBGame.hpp"
#include "CMessageBroadcaster.hpp"
#include "CollisionHandler.hpp"

CArena * CArena::smCurrentArena = NULL;

CArena * CArena::Get()
{
    return smCurrentArena;
}

CArena::CArena()
{
    mArenaSize = 1000.0f;
    
    // Set up walls
    float wallThickness = 40.0f;
    CConvexShape verticalWall = CRectangleShape(wallThickness, mArenaSize + 2*wallThickness);
    verticalWall.setFillColor(CColour::Black);
    verticalWall.setPosition((-mArenaSize / 2.0f) - wallThickness, (-mArenaSize / 2.0f) - wallThickness);
    mStaticObjects.push_back(new CStaticGameObject(verticalWall, "Wall"));
    verticalWall.setPosition(mArenaSize / 2.0f, (-mArenaSize / 2.0f) - wallThickness);
    mStaticObjects.push_back(new CStaticGameObject(verticalWall, "Wall"));
    CConvexShape horizontalWall = CRectangleShape(mArenaSize + 2*wallThickness, wallThickness);
    horizontalWall.setFillColor(CColour::Black);
    horizontalWall.setPosition((-mArenaSize / 2.0f) - wallThickness, (-mArenaSize / 2.0f) - wallThickness);
    mStaticObjects.push_back(new CStaticGameObject(horizontalWall, "Wall"));
    horizontalWall.setPosition((-mArenaSize / 2.0f) - wallThickness, mArenaSize / 2.0f);
    mStaticObjects.push_back(new CStaticGameObject(horizontalWall, "Wall"));
    
    
}

CArena::~CArena()
{
    FREE_LIST_CONTENTS(mObjects);
    FREE_LIST_CONTENTS(mStaticObjects);
}

void CArena::Enter()
{
    CBBGame::Get()->RegisterRenderable(this);
    CBBGame::Get()->RegisterUpdateable(this);
    CMessageBroadcaster<CEvent>::Subscribe(this);
    
    StartBattle();
}

void CArena::Exit()
{
    CBBGame::Get()->UnregisterRenderable(this);
    CBBGame::Get()->UnregisterUpdateable(this);
    CMessageBroadcaster<CEvent>::Unsubscribe(this);
}

void CArena::StartBattle()
{
    FREE_LIST_CONTENTS(mObjects);
    
    CPlayer *thePlayer = new CPlayer();
    CEnemy *theEnemy = new CEnemy(thePlayer);
    mObjects.push_back(thePlayer);
    mObjects.push_back(theEnemy);
    
    mPlayer = thePlayer;
    
    smCurrentArena = this;
}

void CArena::Update(CTime elapsedTime)
{
    // Remove and destroy objects which died last frame
    std::list<CGameObject *> deadObjects;
    for (CGameObject *theObject : mObjects)
    {
        if (theObject->IsDead())
        {
            deadObjects.push_back(theObject);
        }
    }
    for (CGameObject *theObject : deadObjects)
    {
        mObjects.remove(theObject);
    }
    FREE_LIST_CONTENTS(deadObjects);
    
    // Update each object
    for (CGameObject *theObject : mObjects)
    {
        theObject->Update(elapsedTime);
    }
    
    // Solve collisions
    for (auto theIt = mObjects.begin(); theIt != mObjects.end(); ++theIt)
    {
        CGameObject *theObject = *theIt;
        
        // Static objects
        for (CGameObject *theStaticObject : mStaticObjects)
        {
            CVector2f cv;
            if (CollisionHandler::AreColliding(theObject->GetShape(),
                                               theStaticObject->GetShape(),
                                               &cv))
            {
                CollisionHandler::Seperate(theObject->GetShape(),
                                           theStaticObject->GetShape(),
                                           cv,
                                           kCRMoveLeft);
                theObject->ReactToCollision(theStaticObject, cv);
                theStaticObject->ReactToCollision(theObject, cv);
            }
        }
        // Dynamic objects
        // Check from this iterator onwards to prevent checking the same pair twice
        for (auto theOtherIt = theIt; theOtherIt != mObjects.end(); ++theOtherIt)
        {
            CGameObject *theOtherObject = *theOtherIt;
            if (theObject == theOtherObject)
            {
                continue;
            }
            
            CVector2f cv;
            if (CollisionHandler::AreColliding(theObject->GetShape(),
                                               theOtherObject->GetShape(),
                                               &cv))
            {
                theObject->ReactToCollision(theOtherObject, cv);
                theOtherObject->ReactToCollision(theObject, cv);
            }
        }
    }
}

void CArena::Draw(CWindow *theWindow)
{
    // Center the view on the player
    CView theOriginalView = CView(theWindow->getView());
    CView theView = theOriginalView;
    
    CVector2f viewSize = theView.getSize();
    CVector2f viewCenter;
    viewCenter.x = mPlayer->GetPosition().x;
    viewCenter.y = mPlayer->GetPosition().y;
    
    float minmaxPixel = (mArenaSize / 2.0f) + 150.0f;
    float rightmostPixel = viewCenter.x + (viewSize.x / 2.0f);
    float leftmostPixel = viewCenter.x - (viewSize.x / 2.0f);
    if (rightmostPixel > minmaxPixel)
    {
        float offset = rightmostPixel - minmaxPixel;
        viewCenter.x -= offset;
    }
    if (leftmostPixel < -minmaxPixel)
    {
        float offset = -minmaxPixel - leftmostPixel;
        viewCenter.x += offset;
    }
    float topmostPixel = viewCenter.y - (viewSize.y / 2.0f);
    float bottommostPixel = viewCenter.y + (viewSize.y / 2.0f);
    if (bottommostPixel > minmaxPixel)
    {
        float offset = bottommostPixel - minmaxPixel;
        viewCenter.y -= offset;
    }
    if (topmostPixel < -minmaxPixel)
    {
        float offset = -minmaxPixel - topmostPixel;
        viewCenter.y += offset;
    }
    
    theView.setCenter(viewCenter);
    theWindow->setView(theView);
    
    // Draw static objects
    for (CGameObject *theObject : mStaticObjects)
    {
        theObject->Draw(theWindow);
    }
    
    // Draw floor pattern
    int interval = 50;
    for (int xy = interval - 500; xy < 500; xy += interval)
    {
        CLine theHorizontalLine = CLine(CVector2f(-500, xy), CVector2f(500, xy));
        CLine theVerticalLine = CLine(CVector2f(xy, -500), CVector2f(xy, 500));
        theWindow->DrawLine(theHorizontalLine, CColour::Black);
        theWindow->DrawLine(theVerticalLine, CColour::Black);
    }
    
    // Draw dynamic objects
    for (CGameObject *theObject : mObjects)
    {
        theObject->Draw(theWindow);
    }
    
    theWindow->setView(theOriginalView);
}

bool CArena::HandleMessage(CEvent e)
{
    bool eaten = false;
    
    if (e.type == CEvent::KeyPressed)
    {
        if (e.key.code == CKeyboard::R)
        {
            StartBattle();
            eaten = true;
        }
    }
    
    return eaten;
}

void CArena::AddObject(CGameObject *theObject)
{
    mObjects.push_back(theObject);
}
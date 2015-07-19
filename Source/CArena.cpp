#include "CArena.hpp"
#include "CPlayer.hpp"
#include "CEnemy.hpp"
#include "CBBGame.hpp"
#include "CMessageBroadcaster.hpp"

CArena * CArena::smCurrentArena = NULL;

CArena::CArena()
{

}

CArena::~CArena()
{
    FREE_LIST_CONTENTS(mObjects);
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

void CArena::Update(CTime elapsedTime)
{
    // Update each object
    for (CGameObject *theObject : mObjects)
    {
        theObject->Update(elapsedTime);
    }
    
    // Solve collisions
    // TODO
    
    // Remove and destroy dead objects
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
}

void CArena::Draw(CWindow *theWindow)
{
    for (CGameObject *theObject : mObjects)
    {
        theObject->Draw(theWindow);
    }
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

void CArena::StartBattle()
{
    FREE_LIST_CONTENTS(mObjects);
    
    CPlayer *thePlayer = new CPlayer();
    CEnemy *theEnemy = new CEnemy(thePlayer);
    mObjects.push_back(thePlayer);
    mObjects.push_back(theEnemy);
    
    smCurrentArena = this;
}

void CArena::AddObject(CGameObject *theObject)
{
    mObjects.push_back(theObject);
}

CArena * CArena::Get()
{
    return smCurrentArena;
}
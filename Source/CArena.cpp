#include "CArena.hpp"
#include "CPlayer.hpp"
#include "CEnemy.hpp"
#include "CBBGame.hpp"

CArena::CArena()
{
    CPlayer *thePlayer = new CPlayer();
    CEnemy *theEnemy = new CEnemy(thePlayer);
    
    mObjects.push_back(thePlayer);
    mObjects.push_back(theEnemy);
}

CArena::~CArena()
{
    FREE_LIST_CONTENTS(mObjects);
}

void CArena::Enter()
{
    CBBGame::Get()->RegisterRenderable(this);
    CBBGame::Get()->RegisterUpdateable(this);
}

void CArena::Exit()
{
    CBBGame::Get()->UnregisterRenderable(this);
    CBBGame::Get()->UnregisterUpdateable(this);
}

void CArena::Update(CTime elapsedTime)
{
    for (CGameObject *theObject : mObjects)
    {
        theObject->Update(elapsedTime);
    }
}

void CArena::Draw(CWindow *theWindow)
{
    for (CGameObject *theObject : mObjects)
    {
        theObject->Draw(theWindow);
    }
}
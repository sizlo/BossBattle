#include "CEnemy.hpp"

CEnemy::CEnemy(CPlayer *theTarget)
{
    mShape = CCircleShape(50);
    mShape.setFillColor(CColour::Red);
    mShape.setPosition(GameOptions::windowWidth / 2.0f, GameOptions::windowHeight / 2.0f);
    
    mTarget = theTarget;
}

CEnemy::~CEnemy()
{
    
}

void CEnemy::Update(CTime elapsedTime)
{
    
}

void CEnemy::Draw(CWindow *theWindow)
{
    theWindow->DrawShape(mShape);
}
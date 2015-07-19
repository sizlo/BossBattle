#include "CProjectile.hpp"

CProjectile::CProjectile(CVector2f startPos, CVector2f velocity)
{
    mVelocity = velocity;
    
    mShape = CCircleShape(10.0f);
    mShape.setFillColor(CColour::Yellow);
    mShape.setPosition(startPos);
}

CProjectile::~CProjectile()
{
    
}

void CProjectile::Update(CTime elapsedTime)
{
    mShape.move(mVelocity * elapsedTime.asSeconds());
}

void CProjectile::Draw(CWindow *theWindow)
{
    theWindow->DrawShape(mShape);
}
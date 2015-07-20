#include "CProjectile.hpp"

CProjectile::CProjectile(CVector2f startPos, CVector2f velocity) : CGameObject("Projectile")
{
    mVelocity = velocity;
    
    mShape = CCircleShape(10.0f);
    mShape.setFillColor(CColour::Yellow);
    mShape.setPosition(startPos);
    
    mDeathTime = CTime::Zero;
    mActive = true;
}

CProjectile::~CProjectile()
{
    
}

void CProjectile::Update(CTime elapsedTime)
{
    mShape.move(mVelocity * elapsedTime.asSeconds());
    
    if (!IsActive())
    {
        mDeathTime -= elapsedTime;
        if (mDeathTime <= CTime::Zero)
        {
            MarkAsDead();
        }
    }
}

void CProjectile::Draw(CWindow *theWindow)
{
    theWindow->DrawShape(mShape);
}

void CProjectile::ReactToCollision(CGameObject *theOtherObject)
{
    if (theOtherObject->IsA("Wall"))
    {
        if (IsActive())
        {
            KillAfterTime(CTime::Seconds(2.0f));
            mVelocity = CVector2f(0.0f, 0.0f);
        }
    }
}

void CProjectile::KillAfterTime(CTime theTime)
{
    mDeathTime = theTime;
    mActive = false;
}

bool CProjectile::IsActive()
{
    return mActive;
}
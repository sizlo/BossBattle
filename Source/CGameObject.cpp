#include "CGameObject.hpp"

CGameObject::CGameObject()
{
    mDead = false;
}

void CGameObject::SetShape(CConvexShape theShape)
{
    mShape = theShape;
}

CConvexShape & CGameObject::GetShape()
{
    return mShape;
}

CVector2f CGameObject::GetPosition()
{
    return mShape.getPosition();
}

bool CGameObject::IsDead()
{
    return mDead;
}

void CGameObject::MarkAsDead()
{
    mDead = true;
}
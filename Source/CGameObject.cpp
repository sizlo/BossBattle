#include "CGameObject.hpp"

CGameObject::CGameObject()
{
    mDead = false;
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
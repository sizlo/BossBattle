#include "CGameObject.hpp"

CGameObject::CGameObject(std::string theTag)
{
    mDead = false;
    mTag = theTag;
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

std::string CGameObject::GetTag()
{
    return mTag;
}

bool CGameObject::IsA(std::string theTagToCheckFor)
{
    return mTag.compare(theTagToCheckFor) == 0;
}

void CGameObject::ReactToCollision(CGameObject *theOtherObject, CVector2f correctionVector)
{
    // Do nothing by default
}

bool CGameObject::IsDead()
{
    return mDead;
}

void CGameObject::MarkAsDead()
{
    mDead = true;
}
#include "CStaticGameObject.hpp"

CStaticGameObject::CStaticGameObject(CConvexShape theShape, std::string theTag) : CGameObject(theTag)
{
    SetShape(theShape);
}

CStaticGameObject::~CStaticGameObject()
{
    
}

void CStaticGameObject::Update(CTime elapsedTime)
{
    // Do nothing
}

void CStaticGameObject::Draw(CWindow *theWindow)
{
    theWindow->DrawShape(mShape);
}
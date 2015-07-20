#include "CWave.hpp"

CWave::CWave(CVector2f center, float startRadius, float endRadius, float growSpeed)
{
    mCenter = center;
    mRadius = startRadius;
    mMaxRadius = endRadius;
    mGrowSpeed = growSpeed;
}

CWave::~CWave()
{
    
}

void CWave::Update(CTime elapsedTime)
{
    mRadius += mGrowSpeed * elapsedTime.asSeconds();
    
    if (mRadius > mMaxRadius)
    {
        MarkAsDead();
    }
}

void CWave::Draw(CWindow *theWindow)
{
    CConvexShape theShape = CCircleShape(mRadius);
    theShape.setOutlineThickness(1.0f);
    theShape.setOutlineColor(CColour::Black);
    theShape.setFillColor(CColour(0, 0, 0, 0));
    theWindow->DrawShape(theShape);
}
#include "CWave.hpp"

CWave::CWave(CVector2f center, float startRadius, float endRadius, float growSpeed) : CGameObject("Wave")
{
    mActive = true;
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
    
    SetShape(CCircleShape(mRadius));
    mShape.setOutlineThickness(1.0f);
    mShape.setOutlineColor(CColour::Black);
    mShape.setFillColor(CColour(0, 0, 0, 0));
    
    if (mRadius > mMaxRadius)
    {
        MarkAsDead();
    }
}

void CWave::Draw(CWindow *theWindow)
{
    theWindow->DrawShape(mShape);
}

bool CWave::IsActive()
{
    return mActive;
}

void CWave::Deactivate()
{
    mActive = false;
}
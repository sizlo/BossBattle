#include "CPlayer.hpp"

CPlayer::CPlayer() : CGameObject("Player")
{
    mShape = CCircleShape(30);
    mShape.setFillColor(CColour::Blue);
    mShape.setPosition(0.0f, 200.0f);
    
    mSpeed = 500.0f;
}

CPlayer::~CPlayer()
{
    
}

void CPlayer::Update(CTime elapsedTime)
{
    CVector2f up = CVector2f(0.0f, -1.0f);
    CVector2f left = CVector2f(-1.0f, 0.0f);
    CVector2f down = -up;
    CVector2f right = -left;
    
    CVector2f direction = CVector2f(0.0f, 0.0f);
    if (CKeyboard::isKeyPressed(CKeyboard::W))
    {
        direction += up;
    }
    if (CKeyboard::isKeyPressed(CKeyboard::S))
    {
        direction += down;
    }
    if (CKeyboard::isKeyPressed(CKeyboard::A))
    {
        direction += left;
    }
    if (CKeyboard::isKeyPressed(CKeyboard::D))
    {
        direction += right;
    }
    
    direction.Normalise();
    mShape.move(direction * elapsedTime.asSeconds() * mSpeed);
    
    if (mFlashing)
    {
        mFlashTime -= elapsedTime;
        if (mFlashTime <= CTime::Zero)
        {
            StopFlashing();
        }
    }
}

void CPlayer::Draw(CWindow *theWindow)
{
    theWindow->DrawShape(mShape);
}

void CPlayer::ReactToCollision(CGameObject *theOtherObject)
{
    if (theOtherObject->IsA("Projectile"))
    {
        FlashForTime(CTime::Seconds(0.5f));
    }
}

void CPlayer::FlashForTime(CTime theTime)
{
    mFlashing = true;
    mFlashTime = theTime;
    mShape.setFillColor(CColour::Green);
}

void CPlayer::StopFlashing()
{
    mFlashing = 0;
    mShape.setFillColor(CColour::Blue);
}
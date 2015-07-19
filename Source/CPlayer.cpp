#include "CPlayer.hpp"

CPlayer::CPlayer()
{
    mShape = CCircleShape(30);
    mShape.setFillColor(CColour::Blue);
    mShape.setPosition(GameOptions::windowWidth / 2.0f, GameOptions::windowHeight / 4.0f);
    
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
}

void CPlayer::Draw(CWindow *theWindow)
{
    theWindow->DrawShape(mShape);
}
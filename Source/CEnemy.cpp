#include "CEnemy.hpp"
#include "CEAProjectile.hpp"

CEnemy::CEnemy(CGameObject *theTarget)
{
    mShape = CCircleShape(50);
    mShape.setFillColor(CColour::Red);
    mShape.setPosition(0.0f, 0.0f);
    
    mTarget = theTarget;
    
    mAttacks.push_back(new CEAProjectile(CTime::Seconds(1.0f)));
}

CEnemy::~CEnemy()
{
    FREE_LIST_CONTENTS(mAttacks);
}

void CEnemy::Update(CTime elapsedTime)
{
    for (CEnemyAttack *attack : mAttacks)
    {
        if (attack->CanAttack(elapsedTime))
        {
            attack->Attack(this, mTarget);
        }
    }
}

void CEnemy::Draw(CWindow *theWindow)
{
    theWindow->DrawShape(mShape);
}
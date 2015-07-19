#include "CEnemyAttack.hpp"

CEnemyAttack::CEnemyAttack(CTime theCooldown)
{
    mCooldown = theCooldown;
    mCurrentCooldownTime = theCooldown;
}

bool CEnemyAttack::CanAttack(CTime elapsedTime)
{
    bool canAttack = false;
    
    mCurrentCooldownTime -= elapsedTime;
    if (mCurrentCooldownTime < CTime::Zero)
    {
        mCurrentCooldownTime += mCooldown;
        canAttack = true;
    }
    
    return canAttack;
}
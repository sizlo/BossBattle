#include "CEAProjectile.hpp"
#include "CProjectile.hpp"
#include "CArena.hpp"

CEAProjectile::CEAProjectile(CTime theCooldown) : CEnemyAttack(theCooldown)
{
    
}

CEAProjectile::~CEAProjectile()
{
    
}

void CEAProjectile::Attack(CGameObject *theSource, CGameObject *theTarget)
{
    CVector2f sourceToTarget = theTarget->GetPosition() - theSource->GetPosition();
    sourceToTarget.Normalise();
    // Set the speed
    CVector2f velocity = sourceToTarget * 1000.0f;
    
    CProjectile *theProjectile = new CProjectile(theSource->GetPosition(), velocity);
    CArena::Get()->AddObject(theProjectile);
}
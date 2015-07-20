#include "CEAWave.hpp"
#include "CWave.hpp"
#include "CArena.hpp"

CEAWave::CEAWave(CTime theCooldown) : CEnemyAttack(theCooldown)
{
    
}

CEAWave::~CEAWave()
{
    
}

void CEAWave::Attack(CGameObject *theSource, CGameObject *theTarget)
{
    CWave *theWave = new CWave(theSource->GetPosition(),
                               50.0f,
                               300.0f,
                               200.0f);
    CArena::Get()->AddObject(theWave);
}
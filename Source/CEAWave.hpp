#ifndef __BossBattle__CEAWave__
#define __BossBattle__CEAWave__

#include "CEnemyAttack.hpp"

class CEAWave : public CEnemyAttack
{
public:
    CEAWave(CTime theCooldown);
    ~CEAWave();
    
    void Attack(CGameObject *theSource, CGameObject *theTarget);
};

#endif // __BossBattle__CEAWave__

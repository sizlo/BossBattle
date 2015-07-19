#ifndef __BossBattle__CEAProjectile__
#define __BossBattle__CEAProjectile__

#include "CEnemyAttack.hpp"

class CEAProjectile : public CEnemyAttack
{
public:
    CEAProjectile(CTime theCooldown);
    ~CEAProjectile();
    
    void Attack(CGameObject *theSource, CGameObject *theTarget);
};

#endif // __BossBattle__CEAProjectile__

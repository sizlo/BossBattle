#ifndef __BossBattle__CEnemyAttack__
#define __BossBattle__CEnemyAttack__

#include "SFMLIntegration/SFMLIntegration.hpp"
#include "CGameObject.hpp"

class CEnemyAttack
{
public:
    CEnemyAttack(CTime theCooldown);
    virtual ~CEnemyAttack(){};
    
    virtual bool CanAttack(CTime elapsedTime);
    virtual void Attack(CGameObject *theSource, CGameObject *theTarget) = 0;
    
private:
    CTime mCooldown;
    CTime mCurrentCooldownTime;
};

#endif // __BossBattle__CEnemyAttack__

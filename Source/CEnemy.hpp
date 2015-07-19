#ifndef __BossBattle__CEnemy__
#define __BossBattle__CEnemy__

#include "CGameObject.hpp"
#include "CEnemyAttack.hpp"

class CPlayer;

class CEnemy : public CGameObject
{
public:
    CEnemy(CGameObject *theTarget);
    ~CEnemy();
    
    void Update(CTime elapsedTime);
    void Draw(CWindow *theWindow);
    
private:
    CGameObject *mTarget;
    
    std::list<CEnemyAttack *> mAttacks;
};

#endif // __BossBattle__CEnemy__
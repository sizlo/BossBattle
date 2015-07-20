#ifndef __BossBattle__CProjectile__
#define __BossBattle__CProjectile__

#include "CGameObject.hpp"

class CProjectile : public CGameObject
{
public:
    CProjectile(CVector2f startPos, CVector2f velocity);
    ~CProjectile();
    
    void Update(CTime elapsedTime);
    void Draw(CWindow *theWindow);
    
    void ReactToCollision(CGameObject *theOtherObject);
    
private:
    void KillAfterTime(CTime theTime);
    bool IsActive();
    
    bool mActive;
    CVector2f mVelocity;
    CTime mDeathTime;
};

#endif // __BossBattle__CProjectile__

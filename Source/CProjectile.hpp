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
    
private:
    CVector2f mVelocity;
};

#endif // __BossBattle__CProjectile__

#ifndef __BossBattle__CEnemy__
#define __BossBattle__CEnemy__

#include "CGameObject.hpp"

class CPlayer;

class CEnemy : public CGameObject
{
public:
    CEnemy(CPlayer *theTarget);
    ~CEnemy();
    
    void Update(CTime elapsedTime);
    void Draw(CWindow *theWindow);
    
private:
    CConvexShape mShape;
    CPlayer *mTarget;
};

#endif // __BossBattle__CEnemy__
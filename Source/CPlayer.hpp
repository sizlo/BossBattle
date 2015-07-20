#ifndef __BossBattle__CPlayer__
#define __BossBattle__CPlayer__

#include "CGameObject.hpp"

class CPlayer : public CGameObject
{
public:
    CPlayer();
    ~CPlayer();
    
    void Update(CTime elapsedTime);
    void Draw(CWindow *theWindow);
    
    void ReactToCollision(CGameObject *theOtherObject);
    
private:
    void FlashForTime(CTime theTime);
    void StopFlashing();
    
    float mSpeed;
    bool mFlashing;
    CTime mFlashTime;
};

#endif // __BossBattle__CPlayer__
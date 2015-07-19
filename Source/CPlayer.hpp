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
    
private:
    float mSpeed;
};

#endif // __BossBattle__CPlayer__
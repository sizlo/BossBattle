#ifndef __BossBattle__CWave__
#define __BossBattle__CWave__

#include "CGameObject.hpp"

class CWave : public CGameObject
{
public:
    CWave(CVector2f center, float startRadius, float endRadius, float growSpeed);
    ~CWave();
    
    void Update(CTime elapsedTime);
    void Draw(CWindow *theWindow);
    
    bool IsActive();
    void Deactivate();
    
private:
    bool mActive;
    CVector2f mCenter;
    float mRadius;
    float mMaxRadius;
    float mGrowSpeed;
};

#endif // __BossBattle__CWave__

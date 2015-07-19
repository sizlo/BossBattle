#ifndef __BossBattle__CGameObject__
#define __BossBattle__CGameObject__

#include "CUpdateable.hpp"
#include "CRenderable.hpp"

class CGameObject : public CUpdateable, public CRenderable
{
public:
    CGameObject();
    
    void Update(CTime elapsedTime) = 0;
    void Draw(CWindow *theWindow) = 0;

    void SetShape(CConvexShape theShape);
    CConvexShape & GetShape();
    CVector2f GetPosition();
    
    bool IsDead();
    void MarkAsDead();
    
protected:
    CConvexShape mShape;
    
private:
    bool mDead;
};

#endif // __BossBattle__CGameObject__
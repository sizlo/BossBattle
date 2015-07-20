#ifndef __BossBattle__CGameObject__
#define __BossBattle__CGameObject__

#include "CUpdateable.hpp"
#include "CRenderable.hpp"

class CGameObject : public CUpdateable, public CRenderable
{
public:
    CGameObject(std::string theTag);
    
    virtual void Update(CTime elapsedTime) = 0;
    virtual void Draw(CWindow *theWindow) = 0;

    void SetShape(CConvexShape theShape);
    CConvexShape & GetShape();
    CVector2f GetPosition();
    std::string GetTag();
    bool IsA(std::string theTagToCheckFor);
    
    virtual void ReactToCollision(CGameObject *theOtherObject, CVector2f correctionVector);
    
    bool IsDead();
    void MarkAsDead();
    
protected:
    CConvexShape mShape;
    
private:
    bool mDead;
    std::string mTag;
};

#endif // __BossBattle__CGameObject__
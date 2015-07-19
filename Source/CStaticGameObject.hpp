#ifndef __BossBattle__CStaticGameObject__
#define __BossBattle__CStaticGameObject__

#include "CGameObject.hpp"

class CStaticGameObject : public CGameObject
{
public:
    CStaticGameObject(CConvexShape theShape);
    ~CStaticGameObject();
    
    void Update(CTime elapsedTime);
    void Draw(CWindow *theWindow);
};

#endif // __BossBattle__CStaticGameObject__

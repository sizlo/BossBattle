#ifndef __BossBattle__CStaticGameObject__
#define __BossBattle__CStaticGameObject__

#include "CGameObject.hpp"

class CStaticGameObject : public CGameObject
{
public:
    CStaticGameObject(CConvexShape theShape, std::string theTag);
    ~CStaticGameObject();
    
    void Update(CTime elapsedTime);
    void Draw(CWindow *theWindow);
};

#endif // __BossBattle__CStaticGameObject__

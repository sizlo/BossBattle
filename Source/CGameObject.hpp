#ifndef __BossBattle__CGameObject__
#define __BossBattle__CGameObject__

#include "CUpdateable.hpp"
#include "CRenderable.hpp"

class CGameObject : public CUpdateable, public CRenderable
{
public:
    void Update(CTime elapsedTime) = 0;
    void Draw(CWindow *theWindow) = 0;
};

#endif // __BossBattle__CGameObject__
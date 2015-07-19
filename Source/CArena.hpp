#ifndef __BossBattle__CArena__
#define __BossBattle__CArena__

#include "CGameLocation.hpp"
#include "CUpdateable.hpp"
#include "CRenderable.hpp"
#include "CGameObject.hpp"

class CPlayer;
class CEnemy;

class CArena : public CGameLocation, public CUpdateable, public CRenderable
{
public:
    CArena();
    ~CArena();
    
    void Enter();
    void Exit();
    
    void Update(CTime elapsedTime);
    void Draw(CWindow *theWindow);
    
private:
    std::list<CGameObject *> mObjects;
};

#endif // __BossBattle__CArena__
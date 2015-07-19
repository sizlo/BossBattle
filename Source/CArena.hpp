#ifndef __BossBattle__CArena__
#define __BossBattle__CArena__

#include "CGameLocation.hpp"
#include "CUpdateable.hpp"
#include "CRenderable.hpp"
#include "CGameObject.hpp"
#include "CMessageListener.hpp"

class CPlayer;
class CEnemy;

class CArena : public CGameLocation,
               public CUpdateable,
               public CRenderable,
               public CMessageListener<CEvent>
{
public:
    CArena();
    ~CArena();
    
    void Enter();
    void Exit();
    
    void Update(CTime elapsedTime);
    void Draw(CWindow *theWindow);
    
    bool HandleMessage(CEvent e);
    
    void StartBattle();
    
    void AddObject(CGameObject *theObject);
    
    static CArena * Get();
    
private:    
    std::list<CGameObject *> mObjects;
    
    static CArena *smCurrentArena;
};

#endif // __BossBattle__CArena__
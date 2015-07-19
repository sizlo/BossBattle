//
//  CDMGame.hpp
//  DeathMatchPrototype
//
//  Created by Tim Brier on 19/07/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

#ifndef __BossBattle__CBBGame__
#define __BossBattle__CBBGame__

#include "CGame.hpp"

enum EBBGameLocation
{
    kGameLocationArena = kGameLocationDummy + 1
};

class CBBGame : public CGame
{
public:
    static CBBGame * Get();
    
    CBBGame();
    
    void InitialiseOptions();
    void GoToLocation(int theLocation, std::string filename);
};

#endif /* defined(__BossBattle__CBBGame__) */

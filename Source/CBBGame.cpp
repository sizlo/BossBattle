//
//  CBBGame.cpp
//  BossBattle
//
//  Created by Tim Brier on 19/07/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

#include "CBBGame.hpp"
#include "CArena.hpp"

CBBGame * CBBGame::Get()
{
    return static_cast<CBBGame *>(CGame::Get());
}

CBBGame::CBBGame() : CGame("BossBattle")
{
    mClearColour = CColour::White;
}

void CBBGame::InitialiseOptions()
{
    GameOptions::viewHeight = GameOptions::windowHeight;
    GameOptions::viewWidth = GameOptions::windowWidth;
}

void CBBGame::GoToLocation(int theLocation, std::string filename)
{
    switch (theLocation)
    {
        case kGameLocationArena:
            mNextLocation = new CArena();
            break;
            
        default:
            DEBUG_LOG("Unimplemented game location - going to dummy location");
            mNextLocation = new CDummyGameLocation();
            break;
    }
}
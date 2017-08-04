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

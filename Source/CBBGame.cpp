//
//  CBBGame.cpp
//  BossBattle
//
//  Created by Tim Brier on 19/07/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

#include "CBBGame.hpp"

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
    // If we're already in a location leave it
    if (mCurrentLocation != NULL)
    {
        mCurrentLocation->Exit();
        SAFE_DELETE(mCurrentLocation);
    }
    
    switch (theLocation)
    {            
        default:
            DEBUG_LOG("Unimplemented game location - going to dummy location");
            mCurrentLocation = new CDummyGameLocation();
            break;
    }
    
    mCurrentLocation->Enter();
}
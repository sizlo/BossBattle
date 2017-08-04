//
//  Main.cpp
//  BossBattle
//
//  Created by Tim Brier on 19/07/2015.
//  Copyright (c) 2015 tbrier. All rights reserved.
//

#include "CBBGame.hpp"
#include "CArena.hpp"

int main(int argc, char **argv)
{
    CBBGame theGame;
    theGame.Init(new CArena());
    int returnCode = theGame.Run();
    theGame.Cleanup();
    
    return returnCode;
}

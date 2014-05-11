//
//  AutoPlayer.cpp
//  cross_circle
//
//  Created by Atsushi Yoshida on 2014/05/09.
//
//

#include "AutoPlayer.h"

AutoPlayer& AutoPlayer::getInstance() {
    static AutoPlayer instance;
    return instance;
}

void AutoPlayer::run()
{
    auto* game = GameScene::getInstance();
    auto &grids = game->getGrids();
    for(Grid* grid: grids){
        if(grid->canTouch()){
            grid->touch(Color3B::RED);
            return;
        }
    }
}
static AutoPlayer &autoPlayer = AutoPlayer::getInstance();
//
//  GameScene.h
//  cross_circle
//
//  Created by Atsushi Yoshida on 2014/05/03.
//
//

#ifndef __cross_circle__GameScene__
#define __cross_circle__GameScene__

#include "cocos2d.h"
#include "Grid.h"
#include "AutoPlayer.h"

using namespace cocos2d;
class Grid;
class GameScene
: public Layer
{
public:
    GameScene();
    enum Turn{Player = 0, Cpu = 1};
    static Scene* createScene();
    static GameScene* getInstance();
    void nextTurn();
    bool isPlayerTurn();
    const std::vector<Grid*> &getGrids();
private:
    std::vector<Grid*> _grids;
    int _currentTurn;
    bool init();
    void initField();
    CREATE_FUNC(GameScene);
};

#endif /* defined(__cross_circle__GameScene__) */

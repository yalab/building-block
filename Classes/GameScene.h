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

using namespace cocos2d;

class GameScene
: public Layer
{
public:
    static Scene* createScene();
    bool init();
    void initField();
    CREATE_FUNC(GameScene);
};

#endif /* defined(__cross_circle__GameScene__) */

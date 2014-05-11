//
//  AutoPlayer.h
//  cross_circle
//
//  Created by Atsushi Yoshida on 2014/05/09.
//
//

#ifndef __cross_circle__AutoPlayer__
#define __cross_circle__AutoPlayer__

#include "cocos2d.h"
#include "GameScene.h"
using namespace cocos2d;

class AutoPlayer : public Ref
{
public:
    static AutoPlayer &getInstance();
    void run();
private:
    AutoPlayer(){}
    AutoPlayer(const AutoPlayer &other){}
    AutoPlayer &operator=(const AutoPlayer& other){};
};

#endif /* defined(__cross_circle__AutoPlayer__) */

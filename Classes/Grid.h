//
//  Grid.h
//  cross_circle
//
//  Created by Atsushi Yoshida on 2014/05/03.
//
//

#ifndef __cross_circle__Grid__
#define __cross_circle__Grid__

#include "cocos2d.h"
#include "GameScene.h"
using namespace cocos2d;

class Grid
: public LayerColor
{
public:
    Grid();
    enum {SIZE = 60,
          COLS = 10,
          ROWS = 15,
          MARGIN = 5    
    };
    static Grid* create(int x, int y);
    bool init(int x, int y);
    bool isTouched();
    bool touch(Color3B);
    const int getX();
    const int getY();
    bool canTouch();
private:
    void initPosition(int x, int y);
    void enableTouch();
    
    bool _touched;
    int _x;
    int _y;
};

#endif /* defined(__cross_circle__Grid__) */

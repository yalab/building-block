//
//  Grid.cpp
//  cross_circle
//
//  Created by Atsushi Yoshida on 2014/05/03.
//
//

#include "Grid.h"

Grid::Grid():
_x(0),
_y(0)
{
}

Grid* Grid::create(int x, int y)
{
    Grid* ret = new Grid();
    if (ret && ret->init(x, y))
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

bool Grid::init(int x, int y){
    if( ! LayerColor::initWithColor(Color4B::WHITE) ){
        return false;
    }
    initPosition(x, y);
    return true;
}

void Grid::initPosition(int x, int y)
{
    this->_x = x;
    this->_y = y;
    this->setContentSize(Size(Grid::SIZE, Grid::SIZE));
    this->setPosition((x * Grid::SIZE) + (x * Grid::MARGIN),
                      (y * Grid::SIZE) + (y * Grid::MARGIN));

}
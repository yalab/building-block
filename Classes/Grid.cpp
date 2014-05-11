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
_y(0),
_touched(false)
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
    enableTouch();
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

void Grid::enableTouch()
{
    auto* listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = [=](Touch* touch, Event* event){
        auto locationInNode = this->convertToNodeSpace(touch->getLocation());
        Size s = this->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode) && this->canTouch())
        {
            return this->touch(Color3B::BLUE);
        }
        return false;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

}

bool Grid::touch(Color3B color)
{
    auto game = GameScene::getInstance();
    this->_touched = true;
    std::string colorName;
    if(color == Color3B::RED){
        colorName = std::string("red");
    } else {
        colorName = std::string("blue");
    }
    log("Grid::touch %i %i %s", this->_x, this->_y, colorName.c_str());
    this->setColor(color);


    game->nextTurn();
    return true;
}

bool Grid::isTouched()
{
    return this->_touched;
}

bool Grid::canTouch()
{
    if(this->_touched){
        return false;
    }
    if(this->_y == 0){
        return true;
    }
    auto game = GameScene::getInstance();
    auto grids = game->getGrids();
    auto itr = std::find_if(grids.begin(), grids.end(), [&](Grid* grid){
        return getX() == grid->getX() && getY() - 1 == grid->getY();
    });
    auto base = static_cast<Grid*>(*itr);
    return base->isTouched();
}

const int Grid::getX()
{
    return this->_x;
}

const int Grid::getY()
{
    return this->_y;
}

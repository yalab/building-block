//
//  GameScene.cpp
//  cross_circle
//
//  Created by Atsushi Yoshida on 2014/05/03.
//
//

#include "GameScene.h"

Scene* GameScene::createScene()
{
    auto* scene = Scene::create();
    auto* layer = GameScene::create();
    
    scene->addChild(layer);
    return scene;
}

bool GameScene::init()
{
    if( !Layer::init() ){
        return false;
    }
    initField();
    return true;
}


void GameScene::initField()
{
    for(int row = 0; row < Grid::ROWS; row++){
        for(int col = 0; col < Grid::COLS; col++){
            auto* grid = Grid::create(col, row);
            grid->setColor(Color3B::WHITE);
            this->addChild(grid);
        }
    }
}
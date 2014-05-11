//
//  GameScene.cpp
//  cross_circle
//
//  Created by Atsushi Yoshida on 2014/05/03.
//
//

#include "GameScene.h"

//int GameScene::currentTurn = GameScene::Turn::Player;

GameScene::GameScene()
: _currentTurn(GameScene::Turn::Player)
, _grids()
{
}

Scene* GameScene::createScene()
{
    auto* scene = Scene::create();
    auto* layer = GameScene::getInstance();
    scene->addChild(layer);
    return scene;
}

GameScene* GameScene::getInstance()
{
    static GameScene* gamescene = GameScene::create();
    return gamescene;
}

void GameScene::nextTurn()
{
    if(this->isPlayerTurn()){
        log("CPU turn");
        _currentTurn = GameScene::Turn::Cpu;
        AutoPlayer& player = AutoPlayer::getInstance();
        player.run();
    }else{
        log("Player turn");
        _currentTurn = GameScene::Turn::Player;
    }
}

bool GameScene::init()
{
    if( !Layer::init() ){
        return false;
    }
    initField();
    return true;
}

bool GameScene::isPlayerTurn()
{
    return this->_currentTurn == GameScene::Turn::Player;
}

void GameScene::initField()
{
    for(int row = 0; row < Grid::ROWS; row++){
        for(int col = 0; col < Grid::COLS; col++){
            auto* grid = Grid::create(col, row);
            grid->setColor(Color3B::WHITE);
            this->addChild(grid);
            this->_grids.push_back(grid);
        }
    }
}

const std::vector<Grid*> &GameScene::getGrids()
{
    return this->_grids;
}
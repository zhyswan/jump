//
//  MainScene.cpp
//  jump
//
//  Created by nova on 14-8-19.
//
//

#include "GameScene.h"
#include "VisibleRect.h"

USING_NS_CC;

Scene * GameScene::createScene(){
    Scene * scene = Scene::create();
    Layer * layer = GameScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool GameScene::init(){
    if(!Layer::init()){
        return false;
    }
    
    auto sprite = Sprite::create("HelloWorld.png");
    CCLOG("Sprite Defaule Anchor Point: %.0f,%.0f.",sprite->getAnchorPoint().x,sprite->getAnchorPoint().y);
    // position the sprite on the center of the screen
    sprite->setPosition(VisibleRect::center());
    
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    return true;
}
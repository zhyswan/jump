//
//  MenuScene.cpp
//  jump
//
//  Created by nova on 14-8-21.
//
//

#include "MenuScene.h"
#include "GameScene.h"
#include "VisibleRect.h"
USING_NS_CC;

Scene * MenuScene::createScene(){
    Scene * scene = Scene::create();
    Layer * layer = MenuScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool MenuScene::init(){
    if(!Layer::init()){
        return false;
    }
    
    
    float bc = 120;
    float gao = sqrt(3) * bc / 2;//等边三角形高为 bc / 2 * 根号3
    Vec2 star[] = {
        Vec2(-gao / 2,bc / 2), Vec2(gao / 2, 0),Vec2(-gao / 2, -bc / 2)
    };
    
    DrawNode *draw = DrawNode::create();
    draw->drawPolygon(star, sizeof(star)/sizeof(star[0]), Color4F(1,0,0,0),1, Color4F(1,0,0,1));
    //draw->setPosition(VisibleRect::center());
    
    Layer * startBtn = Layer::create();
    startBtn->addChild(draw);
    startBtn->setPosition(VisibleRect::center());
 
    
    /*MenuItemSprite默认锚点为Vec2(0.5,0.5)*/
    auto * startItem = MenuItemSprite::create(startBtn, startBtn, CC_CALLBACK_1(MenuScene::startCallback, this));
    //startItem->ignoreAnchorPointForPosition(false);
    //startItem->setAnchorPoint(Vec2(0,0));
    //startItem->setPosition(Vec2::ZERO);
    
    auto * menu = Menu::create(startItem,NULL);
    //menu->setPosition(Vec2::ZERO);
    /*Menu默认position为中心点，MenuItemSprite的锚点为Vec2(0.5,0.5),则默认情况下MenuItem正好全部在画面里*/
    CCLOG("positoin:%.0f,%.0f",menu->getPosition().x,menu->getPosition().y);
    this->addChild(menu,1);
    
    
    return true;
}

void MenuScene::startCallback(Ref * pSender){
    CCLOG("startCallback");
    Scene * scene = GameScene::createScene();
    Director::getInstance()->replaceScene(scene);
}
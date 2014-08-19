//
//  LoadScene.cpp
//  jump
//
//  Created by nova on 14-8-14.
//
//

#include "LoadScene.h"
//#include "RoleSprite.h"
#include "RoleLayer.h"
#include "ProgressLayer.h"
#include "HorizontalProgressLayer.h"

USING_NS_CC;

Scene * Load::createScene(){
    auto scene = Scene::create();
    
    auto layer = Load::create();
    
    scene->addChild(layer);
    return scene;
}

void Load::loading(float f){
    float p = progressLayer->getProgress() + 0.4;
    progressLayer->setProgress(p);
    if(p>=100.0f){
        
        //删除计划任务
        //切换到菜单场景
        Scene * scene = Scene::create();
        RoleLayer * role = RoleLayer::create();
        scene->addChild(role);
        Director::getInstance()->replaceScene(scene);
    }
}

bool Load::init(){
    if(!Layer::init()){
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    center = Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
    
    progressLayer = HorizontalProgressLayer::create();
    progressLayer->setPosition(center);
    this->addChild(progressLayer);
    
    this->schedule(schedule_selector(Load::loading));
    
    //role = RoleSprite::create();
    //role->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
    
    //role = RoleLayer::create();
    
    //role->setPosition(origin.x, origin.y);
    //role->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
    //role->setContentSize(Size(42, 42));
    //role->setPosition(role->getContentSize().width / 2, role->getContentSize().height / 2);
    //this->addChild(role);
    return true;
}

void Load::loadedCallback(){
    
}
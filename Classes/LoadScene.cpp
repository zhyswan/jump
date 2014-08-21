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
#include "MenuScene.h"
#include "HorizontalProgressLayer.h"
#include "VisibleRect.h"
#include "ToString.h"

USING_NS_CC;

Scene * LoadScene::createScene(){
    auto scene = Scene::create();
    
    auto layer = LoadScene::create();
    
    scene->addChild(layer);
    return scene;
}

void LoadScene::loading(float f){
    float p = progressLayer->getProgress() + 0.01;
    progressLayer->setProgress(p);
    if(p>=1.0f){
      
        //删除计划任务
        //切换到菜单场景
        Scene * scene = MenuScene::createScene();
        Director::getInstance()->replaceScene(scene);
    }
}

bool LoadScene::init(){
    if(!Layer::init()){
        return false;
    }
    
    progressLayer = HorizontalProgressLayer::create();
    progressLayer->setPosition(VisibleRect::center());
    this->addChild(progressLayer);
    
    this->schedule(schedule_selector(LoadScene::loading));
    
    CCLOG("width:%.0f",VisibleRect::getVisibleRect().size.width);
    
    return true;
}

void LoadScene::loadedCallback(){
    
}
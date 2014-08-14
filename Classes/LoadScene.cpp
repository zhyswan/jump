//
//  LoadScene.cpp
//  jump
//
//  Created by nova on 14-8-14.
//
//

#include "LoadScene.h"

USING_NS_CC;

Scene * Load::createScene(){
    auto scene = Scene::create();
    
    auto layer = Load::create();
    
    scene->addChild(layer);
    return scene;
}

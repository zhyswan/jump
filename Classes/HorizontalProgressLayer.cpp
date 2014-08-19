//
//  HorizontalProgressLayer.cpp
//  jump
//
//  Created by nova on 14-8-19.
//
//

#include "HorizontalProgressLayer.h"

USING_NS_CC;

bool HorizontalProgressLayer::init(){
    if(!Layer::init()){
        return false;
    }
    
    Director * director = Director::getInstance();
    Size visibleSize = director->getVisibleSize();
    
    width = visibleSize.width * 0.6;
    height = 2;
    
    DrawNode *draw = DrawNode::create();
    draw->drawSegment(Vec2(-width / 2,0), Vec2(width / 2,0), height / 2, Color4F(0.3, 0.3, 0.3, 1));
    this->addChild(draw);
    
    pDraw = DrawNode::create();
    this->addChild(pDraw);
    
    _contentSize = Size(width,height);
    return true;
}

void HorizontalProgressLayer::setProgress(float p){
    if(p>total){
        p = total;
    }
    pDraw->clear();//不擦除可以产生渐变
    pDraw->drawSegment(Vec2(-width / 2,0), Vec2(-width / 2 + p / total * width,0), height / 2, Color4F(0.2,0.7,0.2,1));
    progress = p;
    
}

float HorizontalProgressLayer::getProgress(){
    return progress;
}
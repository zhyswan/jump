//
//  HorizontalProgressLayer.cpp
//  jump
//
//  Created by nova on 14-8-19.
//
//

#include "HorizontalProgressLayer.h"
#include "ToString.h"

USING_NS_CC;

bool HorizontalProgressLayer::init(){
    if(!Layer::init()){
        return false;
    }
    
    Director * director = Director::getInstance();
    Size visibleSize = director->getVisibleSize();
    
    proWidth = visibleSize.width * 0.6;
    //proHeight = 2;
    
    DrawNode *draw = DrawNode::create();
    draw->drawSegment(Vec2(-proWidth / 2,0), Vec2(proWidth / 2,0), proHeight / 2, Color4F(0.3, 0.3, 0.3, 1));
    this->addChild(draw);
    
    //进度条
    pDraw = DrawNode::create();
    this->addChild(pDraw);
    
    //进度文本
    label = LabelTTF::create("0%", "Arial", 32);
    this->addChild(label);
    
    
    float labelWidth = label->getContentSize().width;
    float labelHeight = label->getContentSize().height;
    float space = 20.0f;
    float totalHeight = proHeight + space + labelHeight;
    
    draw->setPosition(0,-space / 2 - labelHeight / 2);
    pDraw->setPosition(draw->getPosition());
    label->setPosition(0,space / 2 + proHeight / 2);
    
    _contentSize = Size(MAX(labelWidth,proWidth),totalHeight);
    return true;
}

void HorizontalProgressLayer::setProgress(float p){
    if(p>total){
        p = total;
    }
    std::string s = ToString::from(int(p*100));
    if(p<0.3){
        label->setColor(Color3B(0xFF * 0.3, 0xff * 0.3, 0xFF * 0.3));
    }else{
        label->setColor(Color3B(0xFF * 0.3, 0xFF * p * 0.8, 0xFF * 0.3));
    }
    label->setString(s+std::string("%"));
    
    pDraw->clear();//不擦除可以产生渐变
    pDraw->drawSegment(Vec2(-proWidth / 2,0), Vec2(-proWidth / 2 + p / total * proWidth,0), proHeight / 2, Color4F(0.3,0.8,0.3,1));
    progress = p;
    
}

float HorizontalProgressLayer::getProgress(){
    return progress;
}
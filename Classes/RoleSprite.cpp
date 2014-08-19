//
//  RoleSprite.cpp
//  jump
//
//  Created by nova on 14-8-18.
//
//

#include "RoleSprite.h"

USING_NS_CC;

bool RoleSprite::init(){
    if(!DrawNode::init()){
        return false;
    }
    
    DrawNode *role = DrawNode::create();
    role->cocos2d::Node::draw();
    role->onDraw(Mat4(), 1);
    //画线段，
    //参数：起点，终点，粗细，颜色
    //role->drawSegment(Vec2(-100,-100), Vec2(200,200), 10, Color4F(0.1, 0.2, 0.3, 1));
    
    //二次贝塞尔曲线
    //参数：起点，控制点，终点，segments(曲线使用的线段数量，越多越平滑)，颜色
    //role->drawQuadraticBezier(Vec2(-200,-100), Vec2(100,200), Vec2(200,-100), 10, Color4F(0.2, 0.3, 0.4, 1));
    
    //三次贝塞尔曲线
    //http://zh.wikipedia.org/wiki/%E8%B2%9D%E8%8C%B2%E6%9B%B2%E7%B7%9A#.E5.AF.A6.E4.BE.8B.E8.AA.AA.E6.98.8E
    //参数：起点，控制点1，控制点2，终点，segments(曲线使用的线段数量，越多越平滑)，颜色
    //role->drawCubicBezier();
    
    //画三角形
    //参数：端点1，端点2，端点3，颜色
    //role->drawTriangle(Vec2(-100,-100), Vec2(0,100), Vec2(100,-100), Color4F(0.4, 0.5, 0.5, 1));
    
    //多边形，将参数一的各个点，按顺序连接起来，首尾也连接组成多边形
    //参数：多边形的各个顶点，边数，填充色，边框粗细，边框色
    {
        Vec2 star[] = {
            Vec2(-100,-100), Vec2(-100, 100),Vec2(0,-150),
            Vec2(100, 100), Vec2(100, -100),
        };
        
        role->drawPolygon(star, sizeof(star)/sizeof(star[0]), Color4F(1,0,0,0.5),2, Color4F(0,0,1,1));
    }
    
    
    //画实心圆,圆心，半径，颜色
    role->drawDot(Vec2(0,0),36,Color4F(1,1,1,1));
    
    //清除已经绘制的图形
    //role->clear();
    
    
    this->addChild(role);

    return true;
}


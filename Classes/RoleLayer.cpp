//
//  RoleLayer.cpp
//  jump
//
//  Created by nova on 14-8-19.
//
//

#include "RoleLayer.h"
#include "VisibleRect.h"

USING_NS_CC;

bool RoleLayer::init(){
    if(!Layer::init()){
        return false;
    }
    _contentSize = Size(80.0f,80.0f);
    return true;
}

void RoleLayer::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags){
    CCLOG("RoleLayer::draw");
    _customCommand.init(1);
    _customCommand.func = CC_CALLBACK_0(RoleLayer::onDraw, this,transform,flags);
    renderer->addCommand(&_customCommand);
}

void RoleLayer::onDraw(const cocos2d::Mat4& transform, uint32_t flags){
    CCLOG("RoleLayer::onDraw");
    Director* director = Director::getInstance();
    director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, transform);
    
    //glLineWidth( 5.0f );
    /*
    //画点
    DrawPrimitives::setPointSize(20);
    DrawPrimitives::setDrawColor4B(255,0,0,255);
    DrawPrimitives::drawPoint(VisibleRect::center());
    
    //画多个点
    Vec2 points[] = { Vec2(60,60), Vec2(70,70), Vec2(60,70), Vec2(70,60) };
    DrawPrimitives::setPointSize(4);
    DrawPrimitives::setDrawColor4B(0,255,255,255);
    DrawPrimitives::drawPoints( points, 4);
    */
    
    
    
    /*
    //画线，
    //参数：起点，终点
    DrawPrimitives::drawLine( VisibleRect::leftBottom(), VisibleRect::rightTop() );
    DrawPrimitives::drawLine(Vec2(0,0), Vec2(100,100));
    */
    
    
    /*
    //花多边形直至圆
    glLineWidth(1.0f);
    DrawPrimitives::setDrawColor4B(0, 255, 0, 255);
    //参数：圆心，半径，起始弧度（逆时针为正），线段数，是否画半径，x轴缩放，y轴缩放
    DrawPrimitives::drawCircle( VisibleRect::center(), 100, CC_DEGREES_TO_RADIANS(90), 1000,true,1,1);
    DrawPrimitives::setDrawColor4B(255, 255, 0, 255);
    DrawPrimitives::drawCircle( VisibleRect::center(), 120, 0, 10,false);
    //画实心多边形直至圆
    glLineWidth(2);
    DrawPrimitives::setDrawColor4B(0, 0, 255, 255);
    DrawPrimitives::drawSolidCircle( VisibleRect::center() + Vec2(140,0), 40, CC_DEGREES_TO_RADIANS(90), 50, 1.0f, 1.0f);
    */
    
    /*
    // open yellow poly
    //用点连线
    DrawPrimitives::setDrawColor4B(255, 255, 0, 255);
    glLineWidth(10);
    Vec2 vertices[] = { Vec2(0,0), Vec2(50,50), Vec2(100,50), Vec2(100,100), Vec2(50,100) };
    //参数：点集合，点数量，是否封闭（首尾相连）
    DrawPrimitives::drawPoly( vertices, 5, false);
    
    DrawPrimitives::setDrawColor4B(255, 0, 255, 255);
    glLineWidth(2);
    Vec2 vertices2[] = { Vec2(30,130), Vec2(30,230), Vec2(50,200) };
    DrawPrimitives::drawPoly( vertices2, 3, true);

    //用点连线并填充成面
    glLineWidth(1);
    DrawPrimitives::setDrawColor4B(255, 0, 255, 255);
    Vec2 filledVertices[] = { Vec2(0,120), Vec2(50,120), Vec2(50,170), Vec2(25,200), Vec2(0,170) };
    DrawPrimitives::drawSolidPoly(filledVertices, 5, Color4F(0.5f, 0.5f, 1, 1 ) );
    */

    /*
    //画矩形
    //参数：左下点，右下点
    DrawPrimitives::setDrawColor4B(255, 0, 255, 255);
    DrawPrimitives::drawRect(Vec2(1,1), Vec2(100,200));
    DrawPrimitives::drawSolidRect(Vec2(200,200), Vec2(300, 300), Color4F(1,0.5,0,1));
    */
    
    /*
    //二次贝塞尔曲线
    //参数：起点，控制点，终点，线段数
    DrawPrimitives::drawQuadBezier(VisibleRect::leftTop(), VisibleRect::center(), VisibleRect::rightTop(), 50);
    
    //三次贝塞尔曲线
    //参数：起点，控制点1，控制点2，终点 ，线段数
    DrawPrimitives::drawCubicBezier(VisibleRect::center(), Vec2(VisibleRect::center().x+130,VisibleRect::center().y+150), Vec2(VisibleRect::center().x+60,VisibleRect::center().y-50),VisibleRect::right(),100);
    */
    
    
    glLineWidth(2);
    DrawPrimitives::setDrawColor4B(0,255,255,255);
    DrawPrimitives::drawCircle(Vec2(0,0), 38, 0, 50, false);
    
    
    // restore original values
    glLineWidth(1);
    DrawPrimitives::setDrawColor4B(255,255,255,255);
    DrawPrimitives::setPointSize(1);
    //end draw
    director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    
}
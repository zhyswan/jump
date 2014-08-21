//
//  ProgressLayer.h
//  jump
//
//  Created by nova on 14-8-19.
//
//

#ifndef __jump__ProgressLayer__
#define __jump__ProgressLayer__

#include "cocos2d.h"
/*抽象基类*/
class ProgressLayer : public cocos2d::Layer{
public:
    //纯虚函数
    virtual void setProgress(float) = 0;
    virtual float getProgress() = 0;
    
protected:
    float progress{0};//0-1
    float total{1};
};

#endif /* defined(__jump__ProgressLayer__) */

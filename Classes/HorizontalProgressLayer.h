//
//  HorizontalProgressLayer.h
//  jump
//
//  Created by nova on 14-8-19.
//
//

#ifndef __jump__HorizontalProgressLayer__
#define __jump__HorizontalProgressLayer__

#include "cocos2d.h"
#include "ProgressLayer.h"

class HorizontalProgressLayer : public ProgressLayer{
public:
    CREATE_FUNC(HorizontalProgressLayer);
    
    virtual bool init() override;
    
    virtual void setProgress(float);
    virtual float getProgress();
    
private:
    cocos2d::DrawNode * pDraw;
    cocos2d::LabelTTF* label;
    float proWidth;
    float proHeight{2};
};

#endif /* defined(__jump__HorizontalProgressLayer__) */

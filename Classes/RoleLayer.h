//
//  RoleLayer.h
//  jump
//
//  Created by nova on 14-8-19.
//
//

#ifndef __jump__RoleLayer__
#define __jump__RoleLayer__

#include "cocos2d.h"

class RoleLayer : public cocos2d::Layer{
public:
    CREATE_FUNC(RoleLayer);
    virtual bool init() override;
    virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags) override;
protected:
    void onDraw(const cocos2d::Mat4& transform, uint32_t flags);
    cocos2d::CustomCommand _customCommand;
};

#endif /* defined(__jump__RoleLayer__) */

//
//  RoleSprite.h
//  jump
//
//  Created by nova on 14-8-18.
//
//

#ifndef __jump__RoleSprite__
#define __jump__RoleSprite__

#include "cocos2d.h"

class RoleSprite :public cocos2d::DrawNode{
public:
    CREATE_FUNC(RoleSprite);
    
    virtual bool init() override;
};

#endif /* defined(__jump__RoleSprite__) */

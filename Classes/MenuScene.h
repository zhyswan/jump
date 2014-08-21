//
//  MenuScene.h
//  jump
//
//  Created by nova on 14-8-21.
//
//

#ifndef __jump__MenuScene__
#define __jump__MenuScene__

#include "cocos2d.h"

class MenuScene : public cocos2d::Layer{
public:
    static cocos2d::Scene * createScene();
    
    virtual bool init() override;
    
    void startCallback(Ref * pSender);
    
    CREATE_FUNC(MenuScene);
};

#endif /* defined(__jump__MenuScene__) */

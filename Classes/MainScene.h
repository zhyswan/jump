//
//  MainScene.h
//  jump
//
//  Created by nova on 14-8-19.
//
//

#ifndef __jump__MainScene__
#define __jump__MainScene__

#include "cocos2d.h"

class MainScene : public cocos2d::Layer{
public:
    static cocos2d::Scene * createScene();
    
    CREATE_FUNC(MainScene);
    
    virtual bool init() override;
    
    //返回到菜单scene
    void toMenuCallback(cocos2d::Ref * pSender);
    
    //暂停
    void pauseCallback(cocos2d::Ref * pSender);
    
    //开始
    void startCallback(cocos2d::Ref * pSender);
    
    //继续
    //void continueCallback(cocos2d::Ref * pSender);
};

#endif /* defined(__jump__MainScene__) */

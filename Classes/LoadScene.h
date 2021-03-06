//
//  LoadScene.h
//  jump
//
//  Created by nova on 14-8-14.
//
//

#ifndef __jump__LoadScene__
#define __jump__LoadScene__

#include "cocos2d.h"
#include "ProgressLayer.h"

class LoadScene : public cocos2d::Layer{
public:
    //创建场景，并将当前layer添加到场景
    static cocos2d::Scene * createScene();
    
    
    //初始化场景
    virtual bool init() override;
    
    //加载资源进度
    void loading(float f);
    //游戏资源加载完成，回调此方法
    void loadedCallback();
    
    
    //定义create静态方法
    CREATE_FUNC(LoadScene);
    //CREATE_FUNC在此作用同下
    /*
    static Load * create()
    {
        Load *pRet = new Load();
        if (pRet && pRet->init())
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    }*/
    
private:
    //Node *role{nullptr};
    ProgressLayer* progressLayer;
};

#endif /* defined(__jump__LoadScene__) */


#ifndef __PAUSE_SCENE_H__
#define __PAUSE_SCENE_H__
#include "cocos2d.h"  
#include "cocos-ext.h" //使用按钮事件，必须要需要的头文件  
USING_NS_CC_EXT;//使用按钮事件，必须要需要的命名空间    
using namespace cocos2d;
class PauseScene :public CCLayer {
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void menuCloseCallback(cocos2d::Ref* pSender);
    CREATE_FUNC(PauseScene);
    void back(CCObject* pSender);//返回场景  
}; 
#endif // __SECOND_SCENE_H__#pragma once
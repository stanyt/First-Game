#ifndef __DEATH_SCENE_H__
#define __DEATH_SCENE_H__
#include "cocos2d.h"  
#include "cocos-ext.h" //ʹ�ð�ť�¼�������Ҫ��Ҫ��ͷ�ļ�  
#include <HelloWorldScene.h>
#include <SecondScene.h>
USING_NS_CC_EXT;//ʹ�ð�ť�¼�������Ҫ��Ҫ�������ռ�    
using namespace cocos2d;
class DeathScene :public CCLayer {
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void menuCloseCallback(cocos2d::Ref* pSender);
    CREATE_FUNC(DeathScene);
    void back(CCObject* pSender);//���س���  
};
#endif // __DEATH_SCENE_H__#pragma once

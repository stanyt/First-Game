#ifndef __SUCCESS_SCENE_H__
#define __SUCCESS_SCENE_H__
#include "cocos2d.h"  
#include "cocos-ext.h" //ʹ�ð�ť�¼�������Ҫ��Ҫ��ͷ�ļ�  
USING_NS_CC_EXT;//ʹ�ð�ť�¼�������Ҫ��Ҫ�������ռ�    
using namespace cocos2d;
class SuccessScene :public CCLayer {
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(SuccessScene);

};
#endif // __SUCCESS_SCENE_H__#pragma once#pragma once

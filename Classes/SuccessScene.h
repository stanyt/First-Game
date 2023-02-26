#ifndef __SUCCESS_SCENE_H__
#define __SUCCESS_SCENE_H__
#include "cocos2d.h"  
#include "cocos-ext.h" //使用按钮事件，必须要需要的头文件  
USING_NS_CC_EXT;//使用按钮事件，必须要需要的命名空间    
using namespace cocos2d;
class SuccessScene :public CCLayer {
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(SuccessScene);

};
#endif // __SUCCESS_SCENE_H__#pragma once#pragma once

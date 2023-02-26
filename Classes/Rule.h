#ifndef __RULE_H__
#define __RULE_H__
#include "cocos2d.h"  
#include "cocos-ext.h" //使用按钮事件，必须要需要的头文件  
#include <SuccessScene.h>
USING_NS_CC_EXT;//使用按钮事件，必须要需要的命名空间    
using namespace cocos2d;
class Rule :public CCLayer {
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(Rule);

};
#endif // __RULE_H__#pragma once#pragma once
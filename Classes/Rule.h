#ifndef __RULE_H__
#define __RULE_H__
#include "cocos2d.h"  
#include "cocos-ext.h" //ʹ�ð�ť�¼�������Ҫ��Ҫ��ͷ�ļ�  
#include <SuccessScene.h>
USING_NS_CC_EXT;//ʹ�ð�ť�¼�������Ҫ��Ҫ�������ռ�    
using namespace cocos2d;
class Rule :public CCLayer {
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(Rule);

};
#endif // __RULE_H__#pragma once#pragma once
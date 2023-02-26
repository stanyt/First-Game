#ifndef __FLOWWORD_H__
#define __FLOWWORD_H__
#include "cocos2d.h"

USING_NS_CC;

class FlowWord :public CCNode {
public:
    void showWord(const char* text, CCPoint pos);//飘字方法，text为飘字的内容，pos为飘字的位置  
private:
    CCLabelTTF* label;//类成员  
    void flowEnd();//飘字结束时的回调（处理）函数，主要用于删除自己      
};
#endif// #pragma once

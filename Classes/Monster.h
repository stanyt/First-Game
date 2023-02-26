#ifndef __MONSTER_H__
#define __MONSTER_H__
#include "cocos2d.h"
USING_NS_CC;//用到了CCxx，比如CCNode

class Monster :public CCNode {//由于用到了this->addChild(sprite);必须继承CCNode
public:
	Monster();//构造函数
	CCSprite* sprite;
	bool isEmerge;//是否处于屏幕的标识
}; 
#endif
// #pragma once
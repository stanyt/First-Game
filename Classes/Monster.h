#ifndef __MONSTER_H__
#define __MONSTER_H__
#include "cocos2d.h"
USING_NS_CC;//�õ���CCxx������CCNode

class Monster :public CCNode {//�����õ���this->addChild(sprite);����̳�CCNode
public:
	Monster();//���캯��
	CCSprite* sprite;
	bool isEmerge;//�Ƿ�����Ļ�ı�ʶ
}; 
#endif
// #pragma once
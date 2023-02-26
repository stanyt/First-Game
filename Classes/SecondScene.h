#ifndef __SECOND_SCENE_H__
#define __SECOND_SCENE_H__
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include<Monster.h>
#include <cocos/ui/UISlider.h>
class SecondScene : public cocos2d::Layer {
public:
	
  static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(SecondScene);
	void menuCloseCallback(cocos2d::Ref* pSender);
	void CloseCallback();
	Monster* monster_arr[10];
	Monster* monster;
	Sprite* tp;
	float score = 0;
	int hp = 100;
	Label* label_upper_right = Label::create(CCString::createWithFormat("SCORE:%.1f/500", score)->getCString(), "arial", 12);
	Label* label_upper_left = Label::create(CCString::createWithFormat("HP:%d/100",hp)->getCString(), "arial", 12);
	ui::Slider * slider = ui::Slider::create();
	CCSprite* bgSprite1;
	CCSprite* bgSprite2;
	virtual void update(float delta);
	//暂时不需要回调函数
};

#endif // __SECOND_SCENE_H__#pragma once

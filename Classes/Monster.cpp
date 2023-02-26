#include "Monster.h"
Monster::Monster() {
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();//获取屏幕的尺寸、位置信息等
	sprite = CCSprite::create();//使用CloseSelected.png这张图片
	Animation* animation = Animation::create();
	animation->addSpriteFrameWithFileName("fire1.png");
	animation->addSpriteFrameWithFileName("fire2.png");
	animation->addSpriteFrameWithFileName("fire3.png");
	animation->addSpriteFrameWithFileName("fire4.png");
	animation->addSpriteFrameWithFileName("fire5.png");
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.5 / 3.0);
	animation->setRestoreOriginalFrame(true);
	Animate* animate = Animate::create(animation);
	sprite->runAction(RepeatForever::create(animate));
	sprite->setScale(0.5f); 
	sprite->setPosition(ccp(4 * visibleSize.width / 5 + CCRANDOM_0_1() * visibleSize.width / 2, 4 * visibleSize.height / 5 + CCRANDOM_0_1() * visibleSize.height / 2));
	this->addChild(sprite);//添加到舞台
	isEmerge = true;//开始为已经出现状态
	
}
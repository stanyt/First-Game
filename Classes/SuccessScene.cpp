#include "SuccessScene.h"  
#include<SecondScene.h>
#include<HelloWorldScene.h>
#include <cocos/ui/UITextField.h>

USING_NS_CC;
#define menu_selector(_SELECTOR) CC_MENU_SELECTOR(_SELECTOR)

CCScene* SuccessScene::createScene()
{
	CCScene* scene = CCScene::create();
	SuccessScene* SuccessScene = SuccessScene::create();
	scene->addChild(SuccessScene);
	return scene;
}

bool SuccessScene::init()
{
	//获取屏幕的尺寸、位置信息等      
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//创建背景
	auto Successbk = Sprite::create("Successbk.png");
	Successbk->setPosition(visibleSize.width / 2+22, visibleSize.height / 2);
	this->addChild(Successbk, 0);
	//以下按钮
	auto reitem = MenuItemImage::create(
		"restart1.png",
		"restart2.png", this,
		menu_selector(HelloWorld::menuCloseCallback));
	float rx = origin.x + visibleSize.width - reitem->getContentSize().width / 2;
	float ry = origin.y + reitem->getContentSize().height / 2;
	reitem->setPosition(rx, ry);

	// create menu, it's an autorelease object
	auto menu1 = Menu::create(reitem, NULL);
	menu1->setPosition(Vec2::ZERO);
	this->addChild(menu1, 2);//以上菜单*/

 //退出
	auto closeitem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png", this,
		menu_selector(HelloWorld::CloseCallback));
	float cx = origin.x + closeitem->getContentSize().width / 2;
	float cy = origin.y + closeitem->getContentSize().height / 2;
	// create menu, it's an autorelease object
	auto menu2 = Menu::create(closeitem, NULL);
	menu2->setPosition(Vec2::ZERO);
	addChild(menu2, 3);//以上菜单*/

	closeitem->setPosition(
		Vec2(
			cx, cy
		)
	);



	return true;
}
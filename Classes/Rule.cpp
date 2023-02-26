#include "SuccessScene.h"  
#include<Rule.h>
#include<HelloWorldScene.h>
#include<SecondScene.h>
USING_NS_CC;
#define menu_selector(_SELECTOR) CC_MENU_SELECTOR(_SELECTOR)

CCScene* Rule::createScene()
{
	CCScene* scene = CCScene::create();
	Rule* Rule = Rule::create();
	scene->addChild(Rule);
	return scene;
}

bool Rule::init()
{
	//获取屏幕的尺寸、位置信息等      
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//创建背景
	auto rule = Sprite::create("gz.png");
	rule->setPosition(visibleSize.width / 2 + 22, visibleSize.height / 2);
	this->addChild(rule, 0);
	auto backitem = MenuItemImage::create(
		"back1.png",
		"back2.png", this,
		menu_selector(SecondScene::menuCloseCallback));
	float x = visibleSize.width -backitem->getContentSize().width/2;
	float y = origin.y+backitem->getContentSize().height/2;
	backitem->setPosition(Vec2(x, y));

	// create menu, it's an autorelease object
	auto menu = Menu::create(backitem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 2);//以上菜单
	return true;
}
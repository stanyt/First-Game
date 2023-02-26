#include "DeathScene.h"  
#include<SecondScene.h>
#include<HelloWorldScene.h>
#include <cocos/ui/UITextField.h>
#include "SimpleAudioEngine.h"

USING_NS_CC;
#define menu_selector(_SELECTOR) CC_MENU_SELECTOR(_SELECTOR)

CCScene* DeathScene::createScene()
{
	CCScene* scene = CCScene::create();
	DeathScene* DeathScene = DeathScene::create();
	scene->addChild(DeathScene);
	return scene;
}

bool DeathScene::init()
{
	using namespace CocosDenshion;

	auto audio = SimpleAudioEngine::getInstance();

	// set the background music and continuously play it.
	audio->playBackgroundMusic("fail.mp3", true);
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	//创建背景
	auto dbk = Sprite::create("dbk.png");
	dbk->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(dbk, 0);
	//标签
	auto faillabel = Label::createWithTTF("YOU FAILED", "fonts/ZIHUN43HAO.ttf",55);
	faillabel->setPosition(visibleSize.width / 2+22, visibleSize.height / 2);
	faillabel->setColor(Color3B::RED);
	this->addChild(faillabel,2);
	//以下放入死亡场景中
   auto reitem = MenuItemImage::create(
	   "restart1.png",
	   "restart2.png", this,
	   menu_selector(HelloWorld::menuCloseCallback));
   float rx = origin.x + visibleSize.width - reitem->getContentSize().width / 2;
   float ry = origin.y + reitem->getContentSize().height / 2;
   reitem->setPosition(rx,ry);

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
		 cx,cy
	   )
   );

	return true;
}


void DeathScene::back(CCObject* pSender)
{//本场景出栈  
	CCDirector::sharedDirector()->popScene();
}
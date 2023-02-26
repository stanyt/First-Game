#include "PauseScene.h"  
#include<SecondScene.h>
#include<HelloWorldScene.h>
#include <cocos/ui/UITextField.h>

USING_NS_CC;
#define menu_selector(_SELECTOR) CC_MENU_SELECTOR(_SELECTOR)

CCScene* PauseScene::createScene()
{
	CCScene* scene = CCScene::create();
	PauseScene* pauseScene = PauseScene::create();
	scene->addChild(pauseScene);
	return scene;
}

bool PauseScene::init()
{
	//��ȡ��Ļ�ĳߴ硢λ����Ϣ��      
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	auto textField = ui::TextField::create("<enter>", "Arial", 30);

	textField->setPasswordEnabled(true);

	// set the maximum number of characters the user can enter for this TextField
	textField->setMaxLength(10);

	textField->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		log( "editing a TextField" );
		});

	textField->setColor(Color3B::GREEN);

	textField->setPosition(
		Vec2(
			visibleSize.width / 2, visibleSize.height / 2
		)
	);

	this->addChild(textField,0);
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto backitem = MenuItemImage::create(
		"psback.png",
		"psback1.png", this,
		menu_selector(PauseScene::back));
	float x = visibleSize.width/2+11;
	float y = visibleSize.height / 2;
	backitem->setPosition(Vec2(x, y));

	// create menu, it's an autorelease object
	auto menu = Menu::create(backitem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 2);//���ϲ˵�


	//��������
	auto psbk = Sprite::create("psbk.png");
	psbk->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(psbk,0);
	return true;
}


void PauseScene::back(CCObject* pSender)
{
	//��������ջ  
	CCDirector::sharedDirector()->popScene();
}
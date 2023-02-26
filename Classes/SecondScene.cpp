#include<SecondScene.h>
#include<HelloWorldScene.h>
#include "ui/CocosGUI.h"
#include<Monster.h>
#include <iostream>
#include <FlowWord.h>
#include "SimpleAudioEngine.h"
#include <PauseScene.h>
#include <DeathScene.h>
#include <SuccessScene.h>
#define MAX_MONSTER_NUM 3
#define menu_selector(_SELECTOR) CC_MENU_SELECTOR(_SELECTOR)
//CCPoint  tileCoordForPosition(CCPoint pos, CCTMXTiledMap* map);
bool is_collision(CCSprite* sprite1, CCSprite* sprite2);

using namespace cocos2d;
Scene* SecondScene::createScene() {
	//����һ��Scene��Ķ���scene
	auto scene = Scene::create();
	//����һ��SecondScene��Ķ���layer
	auto SecondScene = SecondScene::create();
	//��layer��ӵ�scene��
	scene->addChild(SecondScene);

	//����scene
	return scene;
}
bool SecondScene::init() {
	/*�¼�����*/
	this->setTouchEnabled(true);//������������Ǵ��ڴ����¼���
	this->scheduleUpdate();//������������Ǵ��ڼ�ʹ�����¼���

	using namespace CocosDenshion;

	auto audio = SimpleAudioEngine::getInstance();

	// set the background music and continuously play it.
	audio->playBackgroundMusic("bgmusic.mp3", true);
auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Label* label = Label::create("PLAY", "fonts/Marker Felt.ttf",36);
	label->setPosition(
		Vec2(
			origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - label->getContentSize().height
		)
	);
	label->setColor(Color3B::YELLOW);
	
	auto backitem = MenuItemImage::create(
		"back.png",
		"back2.png",this,
		menu_selector(SecondScene::menuCloseCallback));
		float x = origin.x + visibleSize.width - backitem->getContentSize().width / 2;
		float y = origin.y + backitem->getContentSize().height / 2;
		backitem->setPosition(Vec2(x, y));

	// create menu, it's an autorelease object
	auto menu = Menu::create(backitem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu,2);//���ϲ˵�
	
	auto button = ui::Button::create("normal_image.png", "selected_image.png", "disabled_image.png");
	button->setTitleFontName("fonts/ZIHUN43HAO.ttf");
	button->setTitleText("PAUSE");
	button->setTitleColor(Color3B::BLUE);
	button->setTitleFontSize(8);

	button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			CCDirector::sharedDirector()->pushScene(PauseScene::createScene());
			break;
		case ui::Widget::TouchEventType::ENDED:
			std::cout << "Button 1 clicked" << std::endl;
			break;
		default:
			break;
		}
		});


	button->setPosition(
		Vec2(
			origin.x + button->getContentSize().width /2,
			origin.y +button->getContentSize().height/2
		)
	);
	this->addChild(button,2);
	//�����ǰ�ť



	auto checkbox =ui::CheckBox::create("check_box_normal.png",
		"check_box_normal_press.png",
		"check_box_active.png",
		"check_box_normal_disable.png",
		"check_box_active_disable.png");

	checkbox->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			std::cout << "checkbox 1 clicked" << std::endl;
			break;
		default:
			break;
		}
		});
	checkbox->setPosition(
		Vec2(
			origin.x + visibleSize.width/1.2,
			origin.y + visibleSize.height - 11 * checkbox->getContentSize().height
		)
	);

auto loadingBar = ui::LoadingBar::create("LoadingBarFile.png");
loadingBar->setPosition(Vec2(visibleSize.width/2 , visibleSize.height  + 20 * loadingBar->getContentSize().height));
	// set the direction of the loading bars progress
	loadingBar->setDirection(ui::LoadingBar::Direction::RIGHT);

	// something happened, change the percentage of the loading bar
	loadingBar->setPercent(25);
	loadingBar->setColor(Color3B::RED);
	// more things happened, change the percentage again.
	loadingBar->setPercent(55);

	this->addChild(loadingBar);
	this->addChild(checkbox);
	this->addChild(label);	// Ĭ��z-order=0

	//Ѫ��
	label_upper_right->setPosition(ccp(visibleSize.width-label_upper_right->getContentSize().width/3, visibleSize.height - 20));
	addChild(label_upper_right, 3);
	label_upper_left->setColor(Color3B::GREEN);
	label_upper_left->setPosition(ccp(label_upper_left->getContentSize().width, visibleSize.height -10));//�����ĵ������Ļ�����Ͻ�
	addChild(label_upper_left, 5);
	slider->loadBarTexture("Slider_Back.png"); // what the slider looks like
	slider->loadSlidBallTextures("SliderNode_Normal.png", "SliderNode_Press.png", "SliderNode_Disable.png");
	slider->loadProgressBarTexture("Slider_PressBar.png");
	slider->setTouchEnabled(false);
	slider->setMaxPercent(100);
	slider->setPercent(100);
	/*slider->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {//������ť
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			std::cout << "slider moved" << std::endl;
			break;
		default:
			break;
		}
		});*/

	this->addChild(slider,3);
	slider->setPosition(
		Vec2(
			origin.x + visibleSize.width /8,
			origin.y + visibleSize.height - 3 * slider->getContentSize().height
		)
	);



	/*TextFieldTTF* text = TextFieldTTF::textFieldWithPlaceHolder("<enter>", "Arial", 30);

	text->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(text);*/

	

	// create by plist file
	/*auto particleSystem = ParticleSystem::create("tx1.plist");
	
	addChild(particleSystem,11);*/

	/*auto emitter = ParticleFireworks::create();

	addChild(emitter, 10);*/
	//��ͼ
	// how to get a specific layer
/*����*/
	bgSprite1 = CCSprite::create("background.png");
	bgSprite1->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(bgSprite1, 0);//���˿ؼ���ӵ����������Ϊ0����ײ� 

	bgSprite2 = CCSprite::create("background.png");
	bgSprite2->setPosition(ccp(visibleSize.width + visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(bgSprite2, 0);//���˿ؼ���ӵ����������Ϊ0����ײ�
	/*auto background = map->getLayer("background");
	auto barrier = map->getLayer("barrier");

	// create ParallaxNode
	auto paraNode = ParallaxNode::create();

	// background image is moved at a ratio of 0.4x, 0.5y
	paraNode->addChild(background, -1, Vec2(0.4f, 0.5f), Vec2::ZERO);

	// tiles are moved at a ratio of 2.2x, 1.0y
	paraNode->addChild(barrier, 1, Vec2(2.2f, 1.0f), Vec2(0, -200));
	*/

/*auto tp1 = Sprite::create("Tp2.png");
tp1->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
addChild(tp1,2);*/

//�ᶯ�ľ���
auto tp1 = Sprite::create();
SecondScene:: tp = &*tp1;
Animation* animation = Animation::create();
animation->addSpriteFrameWithFileName("tc1.png");
animation->addSpriteFrameWithFileName("tc2.png");
animation->addSpriteFrameWithFileName("tc3.png");
animation->setLoops(-1);
animation->setDelayPerUnit(0.5 / 3.0);
animation->setRestoreOriginalFrame(true);
Animate* animate = Animate::create(animation);
tp1->runAction(RepeatForever::create(animate));
tp1->setPosition(Vec2(visibleSize.width / 12, visibleSize.height / 2));
addChild(tp1,3);



auto listener = EventListenerKeyboard::create();
listener->onKeyPressed = [tp1](EventKeyboard::KeyCode code, Event*) {
	log("Key with keycode %d pressed", code);

	int offsetX = 0, offsetY = 0;
	 switch (code) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            offsetX = -5;
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            offsetX = 5;
            break;
		case EventKeyboard::KeyCode::KEY_UP_ARROW:
			offsetY = 5;
			break;
        default:
            offsetY = offsetX = 0;
            break;
    }
    // 0.3s�����Ŷ����ӿ�ʼ���������õ�ʱ�䣬�Ӷ��Եò�����ô��е��
	 if (offsetY != 0) {
		 auto jump = JumpBy::create(0.5, Vec2(offsetX, 0), 50, 1);
		 tp1->runAction(jump);
	 }
	 else {
		 if(offsetX<0){
			 tp1->setFlippedX(true);
		 }
		 else {
			 tp1->setFlippedX(false);
		 }
		 auto moveTo = MoveTo::create(0.3, Vec2(tp1->getPositionX() + offsetX, tp1->getPositionY() + offsetY));
		 tp1->runAction(moveTo);
	 }

	 
};

listener->onKeyReleased = [](EventKeyboard::KeyCode code, Event*) {
	log("Key with keycode %d released", code);
};

_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

/*����Ĳ���*/
for (int i = 0; i < MAX_MONSTER_NUM; i++) {
	
	monster = new Monster();
	this->addChild(monster, 2);//���˿ؼ���ӵ����������Ϊ2
	monster_arr[i] = monster;//������������ָ���У�����ʱ�����¼�update�д���
	log("monster");
}


return true;
}
void SecondScene::menuCloseCallback(cocos2d::Ref* pSender)
{

	//Close the cocos2d-x game scene and quit the application
   // Director::getInstance()->end();
	Director::getInstance()->replaceScene(
		TransitionSlideInT::create(
			3.0f, HelloWorld::createScene()
		)
	);
}
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
/*CCPoint  tileCoordForPosition(CCPoint pos, CCTMXTiledMap* map)
{

	CCSize   mapTiledNum = map->getMapSize();

	CCSize   tiledSize = map->getTileSize();



	float x = pos.x / tiledSize.width;

	float y = pos.y / tiledSize.height;



	/*   Cocos2d-x��Ĭ��Y�������������ϵģ�����Ҫ��һ��������� */

	/*y = mapTiledNum.height - y;

	return ccp(x, y);
}*/
/* auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(KeyboardTest::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(KeyboardTest::onKeyReleased, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	// Implementation of the keyboard event callback function prototype
	void Keyblog("Key with keycode %d pressed", keyCode);oardTest::onKeyPressed(EventKeyboard::KeyCode keyCode, Event * event)
	{
		
	}

	void KeyboardTest::onKeyReleased(EventKeyboard::KeyCode keyCode, Event * event)
	{
		log("Key with keycode %d released", keyCode);
	}*///�������飬���̿���
/*bool init()
{
	//create a static PhysicsBody
	auto sprite = addSpriteAtPosition(s_centre, 1);
	sprite->setTag(10);
	sprite->getPhysicsBody()->setContactTestBitmask(0xFFFFFFFF);
	sprite->getPhysicsBody()->setDynamic(false);

	//adds contact event listener
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(PhysicsDemoCollisionProcessing::onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	schedule(CC_SCHEDULE_SELECTOR(PhysicsDemoCollisionProcessing::tick), 0.3f);
	return true;

	return false;
}

void tick(float dt)
{
	auto sprite1 = addSpriteAtPosition(Vec2(s_centre.x + cocos2d::random(-300, 300),
		s_centre.y + cocos2d::random(-300, 300)));
	auto physicsBody = sprite1->getPhysicsBody();
	physicsBody->setVelocity(Vec2(cocos2d::random(-500, 500), cocos2d::random(-500, 500)));
	physicsBody->setContactTestBitmask(0xFFFFFFFF);
}

bool onContactBegin(PhysicsContact& contact)
{
	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();

	if (nodeA && nodeB)
	{
		if (nodeA->getTag() == 10)
		{
			nodeB->removeFromParentAndCleanup(true);
		}
		else if (nodeB->getTag() == 10)
		{
			nodeA->removeFromParentAndCleanup(true);
		}
	}

	//bodies can collide
	return true;
}*/





//��������
/*auto listen = EventListenerPhysicsContact::create();
listen->onContactBegin = [](PhysicsContact& contact)							
{
	auto spriteA = (Sprite*)contact.getShapeA()->getBody()->getNode();				
	auto spriteB = (Sprite*)contact.getShapeB()->getBody()->getNode();				

	if (spriteA && spriteA->getTag() == 10
			|| spriteB && spriteB->getTag() == 10) 								
	{
		if(spriteA)
		spriteA->setColor(Color3B::YELLOW);
		spriteB->setColor(Color3B::YELLOW);
	}

	log("onContactBegin");
	return true;
};*/


// Implementation of the keyboard event callback function prototype
/*tp1->setTag(10);

auto melta = map->layerNamed("melta");
CCPoint   tiledPos = tileCoordForPosition(ccp(x, y), map);//������������λ��
int tiledGid = melta->tileGIDAt(tiledPos);/*   ��ȡ��ͼ���ӵ�Ψһ��ʶ */
//if (tiledGid != 0) {
	/*
11
			  ��ȡ�õ�ͼ���ӵ��������ԣ�Ŀǰ����ֻ��һ��Collidable����,
12
			  ����������meta��ģ���ͬʱҲ������������ͼ�ģ������ڻ�ȡ���ӵ���������ʱ��
13
			  ͨ������Ψһ��ʶ�ڵ�ͼ��ȡ�á�
14
		  */


	//auto propertiesDict = map->getPropertiesForGID(tiledGid).asValueMap();

	/*   ȡ�ø��ӵ�Collidable����ֵ */


	//auto prop = propertiesDict["Collidable"].asString();

	/*   �ж�Collidable�����Ƿ�Ϊtrue,�ǵĻ�����������ƶ� */

	/*if (prop == "true") {
		log("�ϰ���");
		return 0;

	}

}
*/
/*��ײ��⣬�ж���ֻ�����Ƿ��ཻ�ĺ���*/
bool is_collision(CCSprite* sprite1, CCSprite* sprite2) {

	//��������1�ľ���  
	CCSize sprite_size1 = sprite1->getContentSize();//����ĳߴ�  
	CCPoint sprite_position1 = sprite1->getPosition();//��������ĵ�����  
	CCRect sprite_rect1 = CCRectMake(//�Ծ�������ĵ�Ϊ���ĵ㡢�Ծ���ĳߴ�Ϊ����ߣ�����һ�����Ρ�  
		sprite_position1.x - sprite_size1.width / 2,
		sprite_position1.y - sprite_size1.height / 2,
		sprite_size1.width,
		sprite_size1.height);
	//��������2�ľ��Σ�ͬ��  
	CCSize sprite_size2 = sprite2->getContentSize();
	CCPoint sprite_position2 = sprite2->getPosition();
	CCRect sprite_rect2 = CCRectMake(
		sprite_position2.x - sprite_size2.width / 2,
		sprite_position2.y - sprite_size2.height / 2,
		sprite_size2.width,
		sprite_size2.height);
	return sprite_rect1.intersectsRect(sprite_rect2);//������жϾ�����һ�����ص�����Rectʵ��.containsPoint(���ص�);�������ж����������Ƿ��ཻ  


}


/*��ʱ�����¼�*/
void SecondScene::update(float delta) {
	
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();//��ȡ��Ļ�ĳߴ硢λ����Ϣ��
	//ÿһ֡��ͼ�����ƶ�2������
	bgSprite1->setPositionX(bgSprite1->getPositionX() - 2);
	bgSprite2->setPositionX(bgSprite2->getPositionX() - 2);

	//����һ�ŵ�ͼ�����Ҷ˺ʹ��ڵ�������غ�ʱ
	if (bgSprite1->getPositionX() + bgSprite1->getContentSize().width/2 <= 0)
	{
		//����һ�ŵ�ͼ��ӵ��ڶ��ŵ�ͼ����
		//��һ�ŵ�ͼ�ĺ����� = �ڶ��ŵ�ͼ�ĺ����� + �ڶ��ŵ�ͼ�Ŀ��
		bgSprite1->setPositionX(bgSprite2->getPositionX() + bgSprite2->getContentSize().width);
	}

	//���ڶ��ŵ�ͼ�����Ҷ˺ʹ��ڵ�������غ�ʱ
	//���ڶ��ŵ�ͼ��ӵ���һ�ŵ�ͼ����
	if (bgSprite2->getPositionX() + bgSprite2->getContentSize().width/2 <= 0)
	{
		//���ڶ��ŵ�ͼ��ӵ���һ�ŵ�ͼ����
		//�ڶ��ŵ�ͼ�ĺ����� = ��һ�ŵ�ͼ�ĺ����� + ��һ�ŵ�ͼ�Ŀ��
		bgSprite2->setPositionX(bgSprite1->getPositionX() + bgSprite1->getContentSize().width);
	}
	if ((tp->getPositionX())>= visibleSize.width/4&& (tp->getPositionX())<=(9*visibleSize.width/10)) {
		score += 0.1;
		label_upper_right->setString(CCString::createWithFormat("SCORE:%.1f/500", score)->getCString());//�ı����Ͻǵı�ǩ�ı�
	}
	if (score>500) {
		CCDirector::sharedDirector()->replaceScene(SuccessScene::createScene());//��Ϸͨ��
	}

	for (int i = 0; i < MAX_MONSTER_NUM; i++) {//ʱ�̱����������ָ������
		monster = monster_arr[i];
		if (monster->isEmerge) {//������ﴦ����Ļ��	
			monster->sprite->setPosition(ccp(monster->sprite->getPositionX() - visibleSize.width / 100,
				monster->sprite->getPositionY() - visibleSize.height / 100));//��ô���ǵ�λ�ý����ƶ���ǰ��Ļ�����߶ȵ�1/100
			if (monster->sprite->getPositionX() < 0 || monster->sprite->getPositionY() < 0) {
				//�������x����С��0�����ʾ�Ѿ�������Ļ��Χ�����ع���
				monster->sprite->setVisible(false);//��������
				monster->isEmerge = false;//����Ϊ������Ļ��
			}//һ������������
			if (is_collision(tp, monster->sprite)) {//�жϹ����Ƿ���ײ���
				monster->sprite->setVisible(false);//��������
	
				FlowWord* flowWord = new FlowWord();//��ʼ��FlowWord  
				this->addChild(flowWord);//��FlowWordƮ����Ч������̨������Ʈ����Ч��һ���Ǿ��飬����showWord��ͬ���н����������̨�Ĵ��룬Ȼ��û����һ�䣬HelloWorldScene�����������������FlowWord��ϵ������Ҳ����FlowWord����ӵ�Label�����޷���HelloWorldScene����ʾ��  
				flowWord->showWord("-5", tp->getPosition());//ִ��Ʈ��-10��λ�ô�����λ�ÿ�ʼ�� //���ִ�б�ײ������
				monster->isEmerge = false;//����Ϊ������Ļ��	
				hp -= 5;
				slider->setPercent(hp);//�ı����ϲ�Ѫ����ǰ��ֵ
				log("%d",hp);
				label_upper_left->setString(CCString::createWithFormat("HP:%d/100",hp)->getCString());//���Ͻǵ�����
				/*if (hp < 1) {//�����ұ��۵�0
					CCDirector::sharedDirector()->replaceScene(HelloWorld::createScene());//��Ϸ���¿�ʼ*/
				if (hp < 70) {//�����ұ��۵�60,�ı�������ɫΪ��
					label_upper_left->setColor(Color3B::BLUE);
				}
				if (hp < 40) {//�����ұ��۵�30,�ı�������ɫΪ��
					label_upper_left->setColor(Color3B::RED);
				}
				if (hp < 1) {//�����ұ��۵�0
					CCDirector::sharedDirector()->replaceScene(DeathScene::createScene());//��Ϸ���¿�ʼ*/
				}
			}
		}
		else {
			monster->sprite->setPosition(ccp(4 * visibleSize.width / 5 + CCRANDOM_0_1() * visibleSize.width / 2, 4 * visibleSize.height / 5 + CCRANDOM_0_1() * visibleSize.height / 2));//����Ļ�����Ϸ����������ʸ
			monster->sprite->setVisible(true);
			monster->isEmerge = true;
		}
	}
}






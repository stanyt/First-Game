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
	//创建一个Scene类的对象scene
	auto scene = Scene::create();
	//创建一个SecondScene类的对象layer
	auto SecondScene = SecondScene::create();
	//把layer添加到scene里
	scene->addChild(SecondScene);

	//返回scene
	return scene;
}
bool SecondScene::init() {
	/*事件声明*/
	this->setTouchEnabled(true);//声明这个场景是存在触摸事件的
	this->scheduleUpdate();//声明这个场景是存在即使更新事件的

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
	this->addChild(menu,2);//以上菜单
	
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
	//以上是按钮



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
	this->addChild(label);	// 默认z-order=0

	//血条
	label_upper_right->setPosition(ccp(visibleSize.width-label_upper_right->getContentSize().width/3, visibleSize.height - 20));
	addChild(label_upper_right, 3);
	label_upper_left->setColor(Color3B::GREEN);
	label_upper_left->setPosition(ccp(label_upper_left->getContentSize().width, visibleSize.height -10));//把中心点摆在屏幕的左上角
	addChild(label_upper_left, 5);
	slider->loadBarTexture("Slider_Back.png"); // what the slider looks like
	slider->loadSlidBallTextures("SliderNode_Normal.png", "SliderNode_Press.png", "SliderNode_Disable.png");
	slider->loadProgressBarTexture("Slider_PressBar.png");
	slider->setTouchEnabled(false);
	slider->setMaxPercent(100);
	slider->setPercent(100);
	/*slider->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {//触摸按钮
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
	//地图
	// how to get a specific layer
/*背景*/
	bgSprite1 = CCSprite::create("background.png");
	bgSprite1->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(bgSprite1, 0);//将此控件添加到场景，层次为0，最底部 

	bgSprite2 = CCSprite::create("background.png");
	bgSprite2->setPosition(ccp(visibleSize.width + visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(bgSprite2, 0);//将此控件添加到场景，层次为0，最底部
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

//会动的精灵
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
    // 0.3s代表着动作从开始到结束所用的时间，从而显得不会那么机械。
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

/*怪物的产生*/
for (int i = 0; i < MAX_MONSTER_NUM; i++) {
	
	monster = new Monster();
	this->addChild(monster, 2);//将此控件添加到场景，层次为2
	monster_arr[i] = monster;//保存怪物对象到类指针中，给即时更新事件update中处理。
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



	/*   Cocos2d-x的默认Y坐标是由下至上的，所以要做一个相减操作 */

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
	}*///创建精灵，键盘控制
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





//物理引擎
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
CCPoint   tiledPos = tileCoordForPosition(ccp(x, y), map);//人物所在像素位置
int tiledGid = melta->tileGIDAt(tiledPos);/*   获取地图格子的唯一标识 */
//if (tiledGid != 0) {
	/*
11
			  获取该地图格子的所有属性，目前我们只有一个Collidable属性,
12
			  格子是属于meta层的，但同时也是属于整个地图的，所以在获取格子的所有属性时，
13
			  通过格子唯一标识在地图中取得。
14
		  */


	//auto propertiesDict = map->getPropertiesForGID(tiledGid).asValueMap();

	/*   取得格子的Collidable属性值 */


	//auto prop = propertiesDict["Collidable"].asString();

	/*   判断Collidable属性是否为true,是的话，不让玩家移动 */

	/*if (prop == "true") {
		log("障碍物");
		return 0;

	}

}
*/
/*碰撞检测，判断两只精灵是否相交的函数*/
bool is_collision(CCSprite* sprite1, CCSprite* sprite2) {

	//建立精灵1的矩形  
	CCSize sprite_size1 = sprite1->getContentSize();//求精灵的尺寸  
	CCPoint sprite_position1 = sprite1->getPosition();//求精灵的中心点坐标  
	CCRect sprite_rect1 = CCRectMake(//以精灵的中心点为中心点、以精灵的尺寸为宽与高，建立一个矩形。  
		sprite_position1.x - sprite_size1.width / 2,
		sprite_position1.y - sprite_size1.height / 2,
		sprite_size1.width,
		sprite_size1.height);
	//建立精灵2的矩形，同理  
	CCSize sprite_size2 = sprite2->getContentSize();
	CCPoint sprite_position2 = sprite2->getPosition();
	CCRect sprite_rect2 = CCRectMake(
		sprite_position2.x - sprite_size2.width / 2,
		sprite_position2.y - sprite_size2.height / 2,
		sprite_size2.width,
		sprite_size2.height);
	return sprite_rect1.intersectsRect(sprite_rect2);//如果是判断矩形与一个像素点则用Rect实例.containsPoint(像素点);这里是判断两个矩形是否相交  


}


/*即时更新事件*/
void SecondScene::update(float delta) {
	
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();//获取屏幕的尺寸、位置信息等
	//每一帧地图向左移动2个像素
	bgSprite1->setPositionX(bgSprite1->getPositionX() - 2);
	bgSprite2->setPositionX(bgSprite2->getPositionX() - 2);

	//当第一张地图的最右端和窗口的最左端重合时
	if (bgSprite1->getPositionX() + bgSprite1->getContentSize().width/2 <= 0)
	{
		//将第一张地图添加到第二张地图后面
		//第一张地图的横坐标 = 第二张地图的横坐标 + 第二张地图的宽度
		bgSprite1->setPositionX(bgSprite2->getPositionX() + bgSprite2->getContentSize().width);
	}

	//当第二张地图的最右端和窗口的最左端重合时
	//将第二张地图添加到第一张地图后面
	if (bgSprite2->getPositionX() + bgSprite2->getContentSize().width/2 <= 0)
	{
		//将第二张地图添加到第一张地图后面
		//第二张地图的横坐标 = 第一张地图的横坐标 + 第一张地图的宽度
		bgSprite2->setPositionX(bgSprite1->getPositionX() + bgSprite1->getContentSize().width);
	}
	if ((tp->getPositionX())>= visibleSize.width/4&& (tp->getPositionX())<=(9*visibleSize.width/10)) {
		score += 0.1;
		label_upper_right->setString(CCString::createWithFormat("SCORE:%.1f/500", score)->getCString());//改变右上角的标签文本
	}
	if (score>500) {
		CCDirector::sharedDirector()->replaceScene(SuccessScene::createScene());//游戏通关
	}

	for (int i = 0; i < MAX_MONSTER_NUM; i++) {//时刻遍历怪物的类指针数组
		monster = monster_arr[i];
		if (monster->isEmerge) {//如果怪物处于屏幕内	
			monster->sprite->setPosition(ccp(monster->sprite->getPositionX() - visibleSize.width / 100,
				monster->sprite->getPositionY() - visibleSize.height / 100));//那么他们的位置将会移动当前屏幕宽度与高度的1/100
			if (monster->sprite->getPositionX() < 0 || monster->sprite->getPositionY() < 0) {
				//如果怪物x坐标小于0，则表示已经超出屏幕范围，隐藏怪物
				monster->sprite->setVisible(false);//将其隐藏
				monster->isEmerge = false;//设置为不在屏幕内
			}//一下有两个函数
			if (is_collision(tp, monster->sprite)) {//判断怪物是否碰撞玩家
				monster->sprite->setVisible(false);//将其隐藏
	
				FlowWord* flowWord = new FlowWord();//初始化FlowWord  
				this->addChild(flowWord);//将FlowWord飘字特效放上舞台，尽管飘字特效，一不是精灵，二在showWord中同样有将字体放上舞台的代码，然而没有这一句，HelloWorldScene这个场景根本不会与FlowWord联系起来，也就是FlowWord中添加的Label根本无法在HelloWorldScene中显示。  
				flowWord->showWord("-5", tp->getPosition());//执行飘字-10，位置从自身位置开始。 //玩家执行被撞击函数
				monster->isEmerge = false;//设置为不在屏幕内	
				hp -= 5;
				slider->setPercent(hp);//改变中上部血条当前的值
				log("%d",hp);
				label_upper_left->setString(CCString::createWithFormat("HP:%d/100",hp)->getCString());//左上角的文字
				/*if (hp < 1) {//如果玩家被扣到0
					CCDirector::sharedDirector()->replaceScene(HelloWorld::createScene());//游戏重新开始*/
				if (hp < 70) {//如果玩家被扣到60,改变字体颜色为蓝
					label_upper_left->setColor(Color3B::BLUE);
				}
				if (hp < 40) {//如果玩家被扣到30,改变字体颜色为红
					label_upper_left->setColor(Color3B::RED);
				}
				if (hp < 1) {//如果玩家被扣到0
					CCDirector::sharedDirector()->replaceScene(DeathScene::createScene());//游戏重新开始*/
				}
			}
		}
		else {
			monster->sprite->setPosition(ccp(4 * visibleSize.width / 5 + CCRANDOM_0_1() * visibleSize.width / 2, 4 * visibleSize.height / 5 + CCRANDOM_0_1() * visibleSize.height / 2));//在屏幕的右上方区域产生箭矢
			monster->sprite->setVisible(true);
			monster->isEmerge = true;
		}
	}
}






bool init()
{
    //create a static PhysicsBody
    auto sprite = addSpriteAtPosition(s_centre,1);
    sprite->setTag(10);//设置节点标识，为接下来的操作提供指示 
    sprite->getPhysicsBody()->setContactTestBitmask(0xFFFFFFFF);//设置编码为-1 
    sprite->getPhysicsBody()->setDynamic(false);

    //adds contact event listener
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(PhysicsDemoCollisionProcessing::onContactBegin, this);//设置接触回调函数 
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);//结束的回调函数 

    schedule(CC_SCHEDULE_SELECTOR(PhysicsDemoCollisionProcessing::tick), 0.3f);
    return true;

    return false;
}

void tick(float dt)
{
    auto sprite1 = addSpriteAtPosition(Vec2(s_centre.x + cocos2d::random(-300,300),
      s_centre.y + cocos2d::random(-300,300)));//设置精灵随机位置 
    auto physicsBody = sprite1->getPhysicsBody();//获得精灵形状 
    physicsBody->setVelocity(Vec2(cocos2d::random(-500,500),cocos2d::random(-500,500)));//方向速度 
    physicsBody->setContactTestBitmask(0xFFFFFFFF);//编码为-1 
}

bool onContactBegin(PhysicsContact& contact)
{
    auto nodeA = contact.getShapeA()->getBody()->getNode();
    auto nodeB = contact.getShapeB()->getBody()->getNode();//获取两个相撞物体节点 

    if (nodeA && nodeB)
    {
        if (nodeA->getTag() == 10)
        {
            nodeB->removeFromParentAndCleanup(true);
        }
        else if (nodeB->getTag() == 10)
        {
            nodeA->removeFromParentAndCleanup(true);//销毁节点标识为10的数 
        }
    }

    //bodies can collide
    return true;
}
if ((shapeA->getCategoryBitmask() & shapeB->getCollisionBitmask()) == 0
   || (shapeB->getCategoryBitmask() & shapeA->getCollisionBitmask()) == 0)//假如这两个物体碰撞发生执行接触回调函数 
{
//一个body的ContactTestBitmask和另一个body的ContactTestBitmask的逻辑与的结果不等于0时，接触事件将被发出，否则不发送。

//一个body的CategoryBitmask和另一个body的CollisionBitmask的逻辑与结果不等于0时，他们碰撞，否则不碰撞
   // shapes can't collide
   ret = false;
}

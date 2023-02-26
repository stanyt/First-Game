bool init()
{
    //create a static PhysicsBody
    auto sprite = addSpriteAtPosition(s_centre,1);
    sprite->setTag(10);//���ýڵ��ʶ��Ϊ�������Ĳ����ṩָʾ 
    sprite->getPhysicsBody()->setContactTestBitmask(0xFFFFFFFF);//���ñ���Ϊ-1 
    sprite->getPhysicsBody()->setDynamic(false);

    //adds contact event listener
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(PhysicsDemoCollisionProcessing::onContactBegin, this);//���ýӴ��ص����� 
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);//�����Ļص����� 

    schedule(CC_SCHEDULE_SELECTOR(PhysicsDemoCollisionProcessing::tick), 0.3f);
    return true;

    return false;
}

void tick(float dt)
{
    auto sprite1 = addSpriteAtPosition(Vec2(s_centre.x + cocos2d::random(-300,300),
      s_centre.y + cocos2d::random(-300,300)));//���þ������λ�� 
    auto physicsBody = sprite1->getPhysicsBody();//��þ�����״ 
    physicsBody->setVelocity(Vec2(cocos2d::random(-500,500),cocos2d::random(-500,500)));//�����ٶ� 
    physicsBody->setContactTestBitmask(0xFFFFFFFF);//����Ϊ-1 
}

bool onContactBegin(PhysicsContact& contact)
{
    auto nodeA = contact.getShapeA()->getBody()->getNode();
    auto nodeB = contact.getShapeB()->getBody()->getNode();//��ȡ������ײ����ڵ� 

    if (nodeA && nodeB)
    {
        if (nodeA->getTag() == 10)
        {
            nodeB->removeFromParentAndCleanup(true);
        }
        else if (nodeB->getTag() == 10)
        {
            nodeA->removeFromParentAndCleanup(true);//���ٽڵ��ʶΪ10���� 
        }
    }

    //bodies can collide
    return true;
}
if ((shapeA->getCategoryBitmask() & shapeB->getCollisionBitmask()) == 0
   || (shapeB->getCategoryBitmask() & shapeA->getCollisionBitmask()) == 0)//����������������ײ����ִ�нӴ��ص����� 
{
//һ��body��ContactTestBitmask����һ��body��ContactTestBitmask���߼���Ľ��������0ʱ���Ӵ��¼��������������򲻷��͡�

//һ��body��CategoryBitmask����һ��body��CollisionBitmask���߼�����������0ʱ��������ײ��������ײ
   // shapes can't collide
   ret = false;
}

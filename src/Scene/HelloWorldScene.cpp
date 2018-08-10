#include "HelloWorldScene.h"


HelloWorld::HelloWorld()
{
}


HelloWorld::~HelloWorld()
{
}


void HelloWorld::tagJudgeWithGameIndex(int tag, GameController* gameIndex)
{
	switch (tag)
	{
	case BlockTag: gameIndex->physicsContactEvent(normalAction); break;

	case PowerBlockTag: gameIndex->physicsContactEvent(greatAction); break;

	default:
		break;
	}
}

Scene* HelloWorld::createScene()
{
	auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0, -800));

	auto layer = HelloWorld::create();
	scene->addChild(layer);
	return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init())
    {
        return false;
    }

	//add gameIndex
	auto gameIndex = GameController::create(this, 80);
	addChild(gameIndex);
	
	//////////////////////////////////////////////////////////////////////////

	//add ContactEvent
	auto listener = EventListenerPhysicsContact::create();//������ײ�¼�
	
	//��ײǰ
	listener->onContactBegin = [=](PhysicsContact& contact)
	{
		return true;

		
	};
	
	//��ײ��
	listener->onContactPreSolve = [=](PhysicsContact& contact, PhysicsContactPreSolve& solve)
	{
		auto spriteA = (Sprite*)contact.getShapeA()->getBody()->getNode();

		auto spriteB = (Sprite*)contact.getShapeB()->getBody()->getNode();

		if (spriteA->getTag() == HeroTag)
		{
			tagJudgeWithGameIndex(spriteB->getTag(), gameIndex);
		}
		else if (spriteB->getTag() == HeroTag)
		{
			tagJudgeWithGameIndex(spriteA->getTag(), gameIndex);
		}

		return false;
	};

	//��ײ��
	listener->onContactSeparate = [=](PhysicsContact& contact)
	{
		return true;
	};

	//�ύ��ײ�¼����ַ���
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	//////////////////////////////////////////////////////////////////////////

	auto touchListener = EventListenerTouchOneByOne::create();//���������¼�
	
	//����ǰ
	touchListener->onTouchBegan = [=](Touch* t, Event* e)
	{
			if (gameIndex->hitTestPoint(t->getLocation()) )//ȡ����Ϸ�����������꣬ hitTesePointΪbool���ͣ� �������Ƿ���edge��
			{
				
				//��ȡ��ǰ����ľ���
				Sprite* target = static_cast<Sprite*>(e->getCurrentTarget());
				if (target->getBoundingBox().containsPoint(t->getLocation()))
				{
					return true;//�������
				}
				
			}

		return false;
	};

	//������
	touchListener->onTouchMoved = [=](Touch* t, Event* e)
	{
			
			Sprite* target = gameIndex->hero;
			target->setPositionX(target->getPositionX() + t->getDelta().x);//x���ƶ�
		
	};

	touchListener->onTouchEnded = [this](Touch* t, Event* e)
	{
	};

	//�ύ�����¼����ַ���
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this); 


    return true;
}


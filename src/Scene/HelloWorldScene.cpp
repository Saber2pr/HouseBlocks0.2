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
	auto listener = EventListenerPhysicsContact::create();//创建碰撞事件
	
	//碰撞前
	listener->onContactBegin = [=](PhysicsContact& contact)
	{
		return true;

		
	};
	
	//碰撞中
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

	//碰撞后
	listener->onContactSeparate = [=](PhysicsContact& contact)
	{
		return true;
	};

	//提交碰撞事件到分发器
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	//////////////////////////////////////////////////////////////////////////

	auto touchListener = EventListenerTouchOneByOne::create();//创建触摸事件
	
	//触摸前
	touchListener->onTouchBegan = [=](Touch* t, Event* e)
	{
			if (gameIndex->hitTestPoint(t->getLocation()) )//取出游戏，传入点击坐标， hitTesePoint为bool类型， 这里检测是否点击edge。
			{
				
				//获取当前点击的精灵
				Sprite* target = static_cast<Sprite*>(e->getCurrentTarget());
				if (target->getBoundingBox().containsPoint(t->getLocation()))
				{
					return true;//点击到了
				}
				
			}

		return false;
	};

	//触摸中
	touchListener->onTouchMoved = [=](Touch* t, Event* e)
	{
			
			Sprite* target = gameIndex->hero;
			target->setPositionX(target->getPositionX() + t->getDelta().x);//x轴移动
		
	};

	touchListener->onTouchEnded = [this](Touch* t, Event* e)
	{
	};

	//提交触摸事件到分发器
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this); 


    return true;
}


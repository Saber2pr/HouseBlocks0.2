#include "AtlasScene.h"
#include "SceneMediator.h"


AtlasScene::AtlasScene()
{
}


AtlasScene::~AtlasScene()
{
}

bool AtlasScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto sp = Sprite::create("AtlasMap.png");
	sp->setPosition(visibleSize / 2);
	addChild(sp);

	//add btns
	//add buttons
	_backToMenuBtn = ui::Button::create("BackToMenuBtn.png");
	_backToMenuBtn->setPosition(Vec2(visibleSize.width / 2 + 100, visibleSize.height / 4 - 110));
	addChild(_backToMenuBtn);
	_backToMenuBtn->addClickEventListener(
		[](Ref* ref)
	{
		SceneMediator::getInstance()->backtoStartScene();
	}
	);

	//add touchEvent
	auto touchListener = EventListenerTouchOneByOne::create();

	touchListener->onTouchBegan = [=](Touch* touch, Event* event)
	{
		Sprite* target = static_cast<Sprite*>(event->getCurrentTarget());
		if (target->getBoundingBox().containsPoint(touch->getLocation()))
		{
			return true;//点击到了
		}
		return false;//没点击到
	};

	touchListener->onTouchMoved = [=](Touch* touch, Event* event)
	{
		Sprite* target = sp;
		target->setPositionX(target->getPositionX() + touch->getDelta().x);//x轴移动
		return false;
	};

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

	return true;
}

Scene * AtlasScene::createScene()
{
	auto scene = Scene::create();
	auto layer = AtlasScene::create();
	scene->addChild(layer);
	return scene;
}

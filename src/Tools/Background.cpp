#include "Background.h"


Background::Background()
{
}


Background::~Background()
{
	this->unscheduleUpdate();//析构时停止该类的update更新。
}


bool Background::init()
{
	Sprite::init();

	//add updating background map
	auto background = Sprite::create("UpdateMap.png");
	this->addChild(background);//把sprite添加到Background中，外部把Background添加到Layer中。

	//锚点， 在类内部的精灵设置坐标是相对于类对象的。
	background->setPosition(background->getContentSize().width / 2, background->getContentSize().height / 2);
	this->setContentSize(Size(480, 2400));
	this->setPosition(visibleSize.width / 2, visibleSize.height / 2);

	scheduleUpdate();//在初始化时，加入每一帧进行update更新的操作。

	return true;
}

void Background::update(float dt)
{	
	//if you want it is auto, set it true
	autoMove(false);
}

void Background::dealWithMoveCommand()
{
	switch (_front)
	{
	case up:
	{
		if (this->getPositionY() > (visibleSize.height / 2 + this->getContentSize().height / 3))
		{
			this->setPosition(visibleSize.width / 2, visibleSize.height / 2);
		}
		else
		{
			this->setPositionY(this->getPositionY() + 20);//背景上升速度
			log("back is up, hero is down");
		}
	}; break;

	case down:
	{
		if (this->getPositionY() < (visibleSize.height / 2 - this->getContentSize().height / 3))
		{
			this->setPosition(visibleSize.width / 2, visibleSize.height / 2);
		}
		else
		{
			this->setPositionY(this->getPositionY() - 5);//背景下降移动速度
			log("back is down, hero is up");
		}
	}; break;

	case betterDown : 
	{
		if (this->getPositionY() < (visibleSize.height / 2 - this->getContentSize().height / 3))
		{
			this->setPosition(visibleSize.width / 2, visibleSize.height / 2);
		}
		else
		{
			this->setPositionY(this->getPositionY() - 10);//背景下降移动速度
			log("back is betterDown, hero is up");
		}
	}; break;

	default:
		break;
	}
}

void Background::autoMove(bool lock)
{
	if (lock)
	{
		if (this->getPosition() > Vec2::ZERO)
		{
			this->setPosition(this->getPosition() - Vec2(1, 1));
		}
		else
		{
			this->setPosition(visibleSize.width / 2, visibleSize.height / 2);
		}
	}
	
}

void Background::moveCommand(int front)
{
	_front = front;
}

Background* Background::create()
{
	auto background = new Background();
	background->init();
	background->autorelease();
	return background;
}


#include "Background.h"


Background::Background()
{
}


Background::~Background()
{
	this->unscheduleUpdate();//����ʱֹͣ�����update���¡�
}


bool Background::init()
{
	Sprite::init();

	//add updating background map
	auto background = Sprite::create("UpdateMap.png");
	this->addChild(background);//��sprite��ӵ�Background�У��ⲿ��Background��ӵ�Layer�С�

	//ê�㣬 �����ڲ��ľ�����������������������ġ�
	background->setPosition(background->getContentSize().width / 2, background->getContentSize().height / 2);
	this->setContentSize(Size(480, 2400));
	this->setPosition(visibleSize.width / 2, visibleSize.height / 2);

	scheduleUpdate();//�ڳ�ʼ��ʱ������ÿһ֡����update���µĲ�����

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
			this->setPositionY(this->getPositionY() + 20);//���������ٶ�
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
			this->setPositionY(this->getPositionY() - 5);//�����½��ƶ��ٶ�
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
			this->setPositionY(this->getPositionY() - 10);//�����½��ƶ��ٶ�
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


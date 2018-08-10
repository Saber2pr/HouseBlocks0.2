#include "Hero.h"


Hero::Hero()
{
}


Hero::~Hero()
{
	this->unscheduleUpdate();//析构时停止该类的update更新。
}


bool Hero::init(Layer* layer, std::string plist, std::string png)
{
	_plist = plist;
	_png = png;
	_layer = layer;
	height = 0;

	if (!Sprite::init())
	{
		return false;
	}

	//初始化身体
	if (!_bodyInit())
	{
		return false;
	}
	
	//初始化精灵
	if (!_spriteInit())
	{
		return false;
	}
	
	scheduleUpdate();//注册更新函数

	return true;
}

void Hero::update(float dt)//更新函数，使角色处于应激状态。
{
	_dealWithMessage();
	if (!overHeight)
	{
		autoJump();
	}
}

int Hero::getMessage()
{
	return _message;
}

bool Hero::_bodyInit()
{//设置身体属性

	Size s = Size(50, 45);

	setContentSize(s);//设置显示大小

	setPhysicsBody(PhysicsBody::createBox(s));

	getPhysicsBody()->setRotationEnable(false);

	getPhysicsBody()->setContactTestBitmask(1);
	
	setPosition(50, getContentSize().height + 80);

	setTag(HeroTag);

	_pointRecord =getPosition();//记录器初始化

	_actMessage = stay;//初始状态为stay

	return true;
}

bool Hero::_spriteInit()
{
	// 首先读取plist
	SpriteFrameCache* sfc = SpriteFrameCache::getInstance();
	sfc->addSpriteFramesWithFile(_plist, _png);

	upIng = Sprite::createWithSpriteFrameName("Uping.png");
	downIng = Sprite::createWithSpriteFrameName("Downing.png");
	leftIng = Sprite::createWithSpriteFrameName("Lefting.png");
	rightIng = Sprite::createWithSpriteFrameName("Righting.png");
	stayIng = Sprite::createWithSpriteFrameName("Staying.png");
	sleepIng = Sprite::createWithSpriteFrameName("Sleeping.png");
	overIng = Sprite::createWithSpriteFrameName("Overing.png");

	_layer->addChild(upIng);
	_layer->addChild(downIng);
	_layer->addChild(leftIng);
	_layer->addChild(rightIng);
	_layer->addChild(stayIng);
	_layer->addChild(sleepIng);
	_layer->addChild(overIng);

	return true;
}

void Hero::_dealWithMessage()//处理消息
{//分发消息
	if (_message == up || _message == down || _message == left || _message == right || _message == stay || _message == sleep || _message == over)
	{//如果是动作消息
		_actMessage = _message;//存储动作消息，并调用动作消息处理器
		_dealWithActionMessage();
	}
}

void Hero::_dealWithActionMessage()
{//处理动作消息
 //GirlAction0000 - 0006
	switch (_actMessage)
	{
	case up: upIng->setPosition(this->getPosition());
		downIng->setPosition(Point::ZERO);
		leftIng->setPosition(Point::ZERO);
		rightIng->setPosition(Point::ZERO);
		stayIng->setPosition(Point::ZERO);
		sleepIng->setPosition(Point::ZERO);
		overIng->setPosition(Point::ZERO);
		log("I am up");//正常
		break;

	case down: downIng->setPosition(this->getPosition());
		upIng->setPosition(Point::ZERO);
		leftIng->setPosition(Point::ZERO);
		rightIng->setPosition(Point::ZERO);
		stayIng->setPosition(Point::ZERO);
		sleepIng->setPosition(Point::ZERO);
		overIng->setPosition(Point::ZERO);
		log("I am down");
		break;

	case left:  leftIng->setPosition(this->getPosition());
		downIng->setPosition(Point::ZERO);
		upIng->setPosition(Point::ZERO);
		rightIng->setPosition(Point::ZERO);
		stayIng->setPosition(Point::ZERO);
		sleepIng->setPosition(Point::ZERO);
		overIng->setPosition(Point::ZERO);
		log("I go left");
		break;

	case right:  rightIng->setPosition(this->getPosition());
		downIng->setPosition(Point::ZERO);
		leftIng->setPosition(Point::ZERO);
		upIng->setPosition(Point::ZERO);
		stayIng->setPosition(Point::ZERO);
		sleepIng->setPosition(Point::ZERO);
		overIng->setPosition(Point::ZERO);
		log("I go right");
		break;

	case stay:  stayIng->setPosition(this->getPosition());
		downIng->setPosition(Point::ZERO);
		leftIng->setPosition(Point::ZERO);
		rightIng->setPosition(Point::ZERO);
		upIng->setPosition(Point::ZERO);
		sleepIng->setPosition(Point::ZERO);
		overIng->setPosition(Point::ZERO);
		log("I am staying");
		break;

	case sleep:  sleepIng->setPosition(this->getPosition());
		downIng->setPosition(Point::ZERO);
		leftIng->setPosition(Point::ZERO);
		rightIng->setPosition(Point::ZERO);
		stayIng->setPosition(Point::ZERO);
		upIng->setPosition(Point::ZERO);
		overIng->setPosition(Point::ZERO);
		log("I am sleeping");
		break;

	case over:  overIng->setPosition(this->getPosition());
		downIng->setPosition(Point::ZERO);
		leftIng->setPosition(Point::ZERO);
		rightIng->setPosition(Point::ZERO);
		stayIng->setPosition(Point::ZERO);
		sleepIng->setPosition(Point::ZERO);
		upIng->setPosition(Point::ZERO);
		log("I am over");
		break;

	default:
		break;
	}
	
}

void Hero::autoJump()
{
	if (_message == stay)
	{
		jump();
	}

}

void Hero::jump()
{
	this->getPhysicsBody()->setVelocity(Vec2(0, 500));
}

void Hero::actionCommander(int message)
{
	_message = message;//已收到强制命令。
}

Hero * Hero::create(Layer* layer, std::string plist, std::string png)
{
	auto hero = new Hero();
	hero->init(layer, plist, png);
	hero->autorelease();
	return hero;
}

void Hero::heroListener(float positionY)
{
	if (this->getPosition() == _pointRecord)
	{//静止状态
		_message = stay;
		if (overHeight && this->getPosition().y <= this->getContentSize().height)
		{
			_message = over;
		}
	}
	else
	{//移动状态
		if (this->getPosition().y <= this->getContentSize().height + positionY)//考虑地板高度
		{//如果在地上
			if (this->getPosition().x < _pointRecord.x)
			{///如果往左走
				_message = left;
			}
			else
			{///如果往右走
				_message = right;
			}
		}
		else
		{//如果在空中
			if (this->getPosition().y > _pointRecord.y)
			{///如果上升
				_message = up;
			}
			else
			{///如果下降
				_message = down;
			}
		}
	}
	_pointRecord = this->getPosition();//判断完毕，更新位置

}
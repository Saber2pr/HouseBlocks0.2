#include "Hero.h"


Hero::Hero()
{
}


Hero::~Hero()
{
	this->unscheduleUpdate();//����ʱֹͣ�����update���¡�
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

	//��ʼ������
	if (!_bodyInit())
	{
		return false;
	}
	
	//��ʼ������
	if (!_spriteInit())
	{
		return false;
	}
	
	scheduleUpdate();//ע����º���

	return true;
}

void Hero::update(float dt)//���º�����ʹ��ɫ����Ӧ��״̬��
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
{//������������

	Size s = Size(50, 45);

	setContentSize(s);//������ʾ��С

	setPhysicsBody(PhysicsBody::createBox(s));

	getPhysicsBody()->setRotationEnable(false);

	getPhysicsBody()->setContactTestBitmask(1);
	
	setPosition(50, getContentSize().height + 80);

	setTag(HeroTag);

	_pointRecord =getPosition();//��¼����ʼ��

	_actMessage = stay;//��ʼ״̬Ϊstay

	return true;
}

bool Hero::_spriteInit()
{
	// ���ȶ�ȡplist
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

void Hero::_dealWithMessage()//������Ϣ
{//�ַ���Ϣ
	if (_message == up || _message == down || _message == left || _message == right || _message == stay || _message == sleep || _message == over)
	{//����Ƕ�����Ϣ
		_actMessage = _message;//�洢������Ϣ�������ö�����Ϣ������
		_dealWithActionMessage();
	}
}

void Hero::_dealWithActionMessage()
{//��������Ϣ
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
		log("I am up");//����
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
	_message = message;//���յ�ǿ�����
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
	{//��ֹ״̬
		_message = stay;
		if (overHeight && this->getPosition().y <= this->getContentSize().height)
		{
			_message = over;
		}
	}
	else
	{//�ƶ�״̬
		if (this->getPosition().y <= this->getContentSize().height + positionY)//���ǵذ�߶�
		{//����ڵ���
			if (this->getPosition().x < _pointRecord.x)
			{///���������
				_message = left;
			}
			else
			{///���������
				_message = right;
			}
		}
		else
		{//����ڿ���
			if (this->getPosition().y > _pointRecord.y)
			{///�������
				_message = up;
			}
			else
			{///����½�
				_message = down;
			}
		}
	}
	_pointRecord = this->getPosition();//�ж���ϣ�����λ��

}
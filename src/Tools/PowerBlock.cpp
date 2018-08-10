#include "PowerBlock.h"



PowerBlock::PowerBlock()
{
}


PowerBlock::~PowerBlock()
{
	
}

bool PowerBlock::init()
{
	Sprite::init();

	Size size = Size(45, 45);

	auto spBlock = Sprite::create("Food.png");

	spBlock->setAnchorPoint(Vec2(0, 0));

	addChild(spBlock);

	setContentSize(size);

	setPhysicsBody(PhysicsBody::createCircle(15, PHYSICSBODY_MATERIAL_DEFAULT, Vec2(0, 0)));

	getPhysicsBody()->setDynamic(false);

	getPhysicsBody()->setContactTestBitmask(1);

	setTag(PowerBlockTag);

	psSun = ParticleSun::create();
	psSun->setTexture(Director::getInstance()->getTextureCache()->addImage("Star.png"));
	psSun->setPosition(this->getContentSize().width / 2, this->getContentSize().height / 2);
	addChild(psSun, 10);

	A = 0;

	scheduleUpdate();

	return true;
}

void PowerBlock::update(float dt)
{
	A = A + 0.05f;
	if (A >= 2 * 3.14)
	{
		A = 0;
	}
	setPositionY(getPositionY() - 10);
	setPositionX(getPositionX() + 5 * sin(A));

	if (getPositionY() < -50)
	{
		unscheduleUpdate();
		removeFromParent();
	}

}
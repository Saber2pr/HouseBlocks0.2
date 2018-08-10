#include "Block.h"


Block::Block()
{
}


Block::~Block()
{
	this->unscheduleUpdate();
}

bool Block::init()
{
	Sprite::init();

	Size size = Size(110, 35);

	auto spBlock = Sprite::create("Cola.png");

	spBlock->setAnchorPoint(Vec2(0, 0));

	addChild(spBlock);

	setContentSize(size);

	setPhysicsBody(PhysicsBody::createBox(size));

	getPhysicsBody()->setDynamic(false);

	getPhysicsBody()->setContactTestBitmask(1);

	setTag(BlockTag);

	scheduleUpdate();

	return true;
}


void Block::update(float dt)
{
	if (this->getPositionY() < 100)
	{
		this->setPosition(getRandPointInforY(visibleSize.height));

	}
}

Point Block::getRandPointInforY(int y)
{
	int sand = visibleSize.width;
	int x = rand() % (sand);
	return Point(x, y);
}


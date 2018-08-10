#include "OppoBlock.h"
#include "AnimateTool.h"


bool OppoBlock::init()
{
	Sprite::init();

	Size size = Size(30, 30);

	auto bird = AnimateTool::getSpriteAction("bird.plist", "bird.png", 8, 0.05f);
	runAction(RepeatForever::create(bird));

	setContentSize(size);//要在设置Box前初始化，不然内容和框脱离

	setPhysicsBody(PhysicsBody::createCircle( 15, PHYSICSBODY_MATERIAL_DEFAULT, Vec2(0, 0)));//设置物理box

	scheduleUpdate();

	getPhysicsBody()->setDynamic(false);//设置浮空状态

	getPhysicsBody()->setContactTestBitmask(1);

	A = 0;

	return true;
}

void OppoBlock::update(float dt)
{
	A = A + 0.05f;
	p.x = visibleSize.width / 3 + 100 * cos(A);
	p.y = visibleSize.height / 3 + 100 * sin(A);
	if (A >= 2 * 3.14)
	{
		A = 0;
	}
	
	this->setPosition(p);
}


OppoBlock::OppoBlock()
{
}


OppoBlock::~OppoBlock()
{
	this->unscheduleUpdate();//析构时停止该类的update更新。
}

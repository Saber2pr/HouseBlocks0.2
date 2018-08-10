#include "Load.h"
#include "AnimateTool.h"


Load::Load()
{
}


Load::~Load()
{
}


bool Load::init()
{
	Sprite::init();
	
	//add animates
	//ע���schedule_selectorʹ��ʱ��֡���ص����ܵ��¶�����ʧ��0.053f
	auto load = AnimateTool::getSpriteAction("load.plist", "load.png", 13, 0.053f);
	this->runAction(RepeatForever::create(load));

	return true;
}

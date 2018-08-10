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
	//注意和schedule_selector使用时，帧率重叠可能导致动画消失。0.053f
	auto load = AnimateTool::getSpriteAction("load.plist", "load.png", 13, 0.053f);
	this->runAction(RepeatForever::create(load));

	return true;
}

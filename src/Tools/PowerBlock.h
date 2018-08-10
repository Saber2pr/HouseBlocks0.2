#ifndef _POWERBLOCK_H_
#define _POWERBLOCK_H_

#include "cocos2d.h"

USING_NS_CC;

class PowerBlock : public Sprite
{
public:
	PowerBlock();
	~PowerBlock();
	virtual bool init();
	virtual void update(float dt);
	CREATE_FUNC(PowerBlock);

private:
	Size visibleSize = Director::getInstance()->getVisibleSize();
	float A;
	enum Tag { HeroTag, BlockTag, PowerBlockTag };

private:
	ParticleSun* psSun;

};
#endif
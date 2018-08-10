#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "cocos2d.h"

USING_NS_CC;

class Block : public Sprite
{
public:
	Block();
	~Block();
	virtual bool init();
	virtual void update(float dt);
	CREATE_FUNC(Block);

private:
	Size visibleSize = Director::getInstance()->getVisibleSize();
	enum Tag { HeroTag, BlockTag, PowerBlockTag };

private:
	Point getRandPointInforY(int y);

};
#endif
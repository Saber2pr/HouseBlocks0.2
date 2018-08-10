#ifndef _OppoBLOCK_H_
#define _OppoBLOCK_H_

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class OppoBlock : public Sprite
{
public:
	OppoBlock();
	~OppoBlock();
	virtual bool init();
	virtual void update(float dt);
	CREATE_FUNC(OppoBlock);

private:
	Point p;
	float A;

private:
	Size visibleSize = Director::getInstance()->getVisibleSize();
};
#endif
#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "cocos2d.h"

USING_NS_CC;

class Background : public Sprite
{
public:
	Background();
	~Background();
	virtual bool init();
	virtual void update(float dt);
	static Background* create();

private:
	Size visibleSize = Director::getInstance()->getVisibleSize();
	enum actionMessage { up = 1001, betterUp, left, right, down, betterDown, stay, sleep, over };//动作消息协议
	int _front;

private:
	void autoMove(bool lock);

public:
	//only front "up"or"down",then dealWithMoveCommand
	void moveCommand(int front);
	//is next of moveCommand
	void dealWithMoveCommand();
	
};
#endif


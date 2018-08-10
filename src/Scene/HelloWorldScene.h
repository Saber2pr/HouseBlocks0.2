#ifndef _HELLOWORLDSCENE_H_
#define _HELLOWORLDSCENE_H_

#include "cocos2d.h"

#include "GameController.h"

USING_NS_CC;

class HelloWorld : public Layer
{
public:
	HelloWorld();
	~HelloWorld();
	virtual bool init();
	CREATE_FUNC(HelloWorld);

private:
	enum actionMessage { up = 1001, betterUp, left, right, down, betterDown, stay, sleep, over, normalAction, greatAction };//动作消息协议
	enum Tag { HeroTag, BlockTag, PowerBlockTag };
	bool contactBool = false;

private:
	void tagJudgeWithGameIndex(int tag, GameController* gameIndex);
	
public:
	static cocos2d::Scene* createScene();

};

#endif

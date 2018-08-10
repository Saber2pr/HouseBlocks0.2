#ifndef _GameController_H_
#define _GameController_H_

#include "cocos2d.h"
#include "ui\CocosGUI.h"

#include "Edge.h"
#include "Hero.h"
#include "Block.h"
#include "PowerBlock.h"
#include "Background.h"
#include "EnergyBar.h"
#include "ScoreText.h"

USING_NS_CC;

class GameController : public Layer
{
public:
	GameController();
	~GameController();
	virtual bool init(Layer* layer, float positionY);
	virtual void update(float dt);

private:
	Layer* _layer;
	Edge* edge;
	Background* background;
	Sprite* ground;
	EnergyBar* _energyBar;
	ScoreText* _scoreText;
private:
	Block* block1;
	Block* block2;
	Block* block3;
	Block* block4;

private:
	ui::Button* _pauseBtn;
	ui::Button* _finishBtn;
	
private:
	enum actionMessage { up = 1001, betterUp, left, right, down, betterDown, stay, sleep, over , normalAction, greatAction};//动作消息协议
	float _positionY;
	Size visibleSize = Director::getInstance()->getVisibleSize();;
	int height;
	int overHeight = 0;
	Point _ptouch;
	int heightCount;
	bool powerLock = false;
	float frameCount = 0;

private:
	ParticleMeteor* psMeteor;
	ParticleExplosion* psExplosion;
	ParticleSnow* psSnow;

private:
	void addBlock(int y);
	void addPowerBlock();
	void addViewMagic();
	void updateBlock(int front);
	void moveBlock(Block* block, int speed);
	void addBtns();
	void updateViewMagic();
	void getTouchPoint(Point ptouch);
	Point getRandPointInforY(int y);

public:
	Hero* hero;

public:
	bool hitTestPoint(Vec2 point);
	void physicsContactEvent(int act);
	void touchEvent();

	static GameController* create(Layer* layer, float positionY);//自定义初始化方法，要操作外部类对象，则为static类型

};
#endif

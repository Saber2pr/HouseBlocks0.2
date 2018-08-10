#ifndef _HERO_H_
#define _HERO_H_

#include "cocos2d.h"

USING_NS_CC;

//只需设置初始位置。
class Hero : public Sprite
{
public:
	Hero();
	~Hero();
	virtual bool init(Layer* layer, std::string plist, std::string png);
	virtual void update(float dt);

private:
	enum actionMessage { up = 1001, betterUp, left, right, down, betterDown, stay, sleep, over };//动作消息协议
	enum Tag { HeroTag, BlockTag, PowerBlockTag };
	Layer* _layer;
	int _message;//消息存储器
	int _actMessage = stay;//初始动作消息
	Vec2 _pointRecord;//位置记录器

private:
	std::string _plist;
	std::string _png;

private:
	Sprite* upIng;
	Sprite* downIng;
	Sprite* leftIng;
	Sprite* rightIng;
	Sprite* stayIng;
	Sprite* sleepIng;
	Sprite* overIng;

private:
	bool _bodyInit();//初始化身体
	bool _spriteInit();//初始化精灵
	void _dealWithMessage();//消息分发处理器
	void _dealWithActionMessage();//动作消息处理器
	void autoJump();
	void jump();

public:
	int height;//在外部使用
	int overHeight = 0;
	
public:
	//检测角色位置，并发出移动命令，参数为地面高度
	virtual void heroListener(float positionY);
	//强制移动命令
	virtual void actionCommander(int act);

	//得到当前hero状态
	int getMessage();

	//** this layer, Hero's plist and png.
	//* Uping.png, Downing.png, Lefting.png, Righting.png, Staying.png, Sleeping.png, Overing.png
	//public: height, overHeight, heroListener, actionCommander, getMessage
	static Hero* create(Layer* layer, std::string plist, std::string png);//利用静态全局方法可以引入外部指针

};

#endif

/**
*注意：类对象收集在自己外部的信息，传入内部做出反应。外部只需设置对象的监听或强制命令。
*

//////////////////////////////////////////////////////////////////////////

消息处理机制：

private：
	0.消息存储器 _message ：负责存储消息。
	1.消息协议 enum Message { up = 1001, left, right, down, stay, sleep, over }。
	2.消息处理器 _dealWithMessage ：放置在自己的循环中，对收集到的消息进行识别处理。

public：
	3.消息收听者 heroListener() ：放置在主循环中持续收听并收集信息。
	4.强制命令 actionCommander(int message) ：直接指定角色消息。

//////////////////////////////////////////////////////////////////////////

static静态取出[外部类容器]机制：

private：
	1.容器地址副本 Layer* _layer;
	2.复制地址方法 void copyAdress(Layer* layer);//保存容器的地址。
public:
	3.创造函数static 类名* create(容器* );//new一个该类对象并autorelease，调用copyAdress，最后返回。

//////////////////////////////////////////////////////////////////////////

this指针取入该类对象的指针进行调用该类的方法。

//////////////////////////////////////////////////////////////////////////
*/

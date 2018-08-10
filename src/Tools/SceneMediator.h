#ifndef _SCENEMEDIATOR_H_
#define _SCENEMEDIATOR_H_

#include "cocos2d.h"

USING_NS_CC;

class SceneMediator
{
public:
	SceneMediator();
	~SceneMediator();

protected:
	static SceneMediator* _instance;

public:
	static SceneMediator* getInstance();

	virtual void gotoStartScene();
	virtual void backtoStartScene();
	virtual void backtoPreViewScene();
	virtual void pushPauseScene();
	virtual void popPauseScene();
	virtual void gotoNoticeScene();
	virtual void gotoLoadScene();
	virtual void gotoHelloWorldScene();
	virtual void backtoHelloWorldScene();
	virtual void gotoGameWinScene();
	virtual void gotoGameOverScene();
	virtual void gotoAboutScene();
	virtual void gotoAtlasScene();

};

#endif
//////////////////////////////////////////////////////////////////////////
//接口类
//静态获取实例调用类成员函数
//1. protected: static SceneMediator* _instance;
//2. public: static SceneMediator* getInstance();
//3. public: virtual void func();
//////////////////////////////////////////////////////////////////////////
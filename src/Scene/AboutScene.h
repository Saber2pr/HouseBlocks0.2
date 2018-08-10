#ifndef _ABOUTSCENE_H_
#define _ABOUTSCENE_H_

#include "cocos2d.h"
#include "ui\CocosGUI.h"

USING_NS_CC;

class AboutScene : public Layer
{
public:
	AboutScene();
	~AboutScene();
	virtual bool init();
	CREATE_FUNC(AboutScene);

private:
	ui::Button* _backToMenuBtn;

public:
	static Scene* createScene();

};
#endif

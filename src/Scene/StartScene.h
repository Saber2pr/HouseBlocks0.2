#ifndef _STARTSCENE_H_
#define _STARTSCENE_H_

#include "cocos2d.h"
#include "ui\CocosGUI.h"

#include "Background.h"
#include "MusicBox.h"

USING_NS_CC;

class StartScene : public Layer
{
public:
	StartScene();
	~StartScene();
	virtual bool init();
	CREATE_FUNC(StartScene);
	static Scene* createScene();

protected:
	Sprite* _background;
	MusicBox* musicBox;

protected:
	ui::Button* _startBtn;
	ui::Button* _scoreBtn;
	ui::Button* _musicLockBtn;
	ui::Button* _atlasBtn;
	ui::Button* _aboutBtn;
	ui::Button* _exitBtn;
};
#endif

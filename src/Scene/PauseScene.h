#ifndef _PAUSESCENE_H_
#define _PAUSESCENE_H_

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "MusicBox.h"

USING_NS_CC;

class PauseScene : public Layer
{
public:
	PauseScene();
	~PauseScene();
	virtual bool init();
	CREATE_FUNC(PauseScene);
	static Scene* createScene();

private:
	Sprite* _pauseBack;
	MusicBox* musicBox;

private:
	ui::Button* _backToGameBtn;
	ui::Button* _musicLockBtn;
	

	
};
#endif

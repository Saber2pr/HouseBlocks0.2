#ifndef _GameOverScene_H_
#define _GameOverScene_H_

#include "cocos2d.h"
#include "ui\CocosGUI.h"

USING_NS_CC;
class GameOverScene : public Layer
{
private:
	Size visibleSize;
	ui::Button* _restartBtn;
	ui::Button* _backToMenuBtn;
public:
	GameOverScene();
	~GameOverScene();
	virtual bool init();
	CREATE_FUNC(GameOverScene);

	static Scene* createScene();
};
#endif

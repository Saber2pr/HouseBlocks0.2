#ifndef _GAMEWINSCENE_H_
#define _GAMEWINSCENE_H_

#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

class GameWinScene : public Layer
{
public:
	GameWinScene();
	~GameWinScene();
	virtual bool init();
	CREATE_FUNC(GameWinScene);

	static Scene* createScene();

protected:
	ui::Button* _backToMenuBtn;

};
#endif // _GAMEWINSCENE_H_

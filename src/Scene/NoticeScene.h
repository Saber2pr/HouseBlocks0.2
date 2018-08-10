#ifndef _NOTICESCENE_H_
#define _NOTICESCENE_H_

#include "cocos2d.h"
#include "ui\CocosGUI.h"

USING_NS_CC;

class NoticeScene : public Layer
{
public:
	NoticeScene();
	~NoticeScene();
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(NoticeScene);

private:
	ui::Button* _nextBtn;

};
#endif

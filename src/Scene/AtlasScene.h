#ifndef _ATLASSCENE_H_
#define _ATLASSCENE_H_

#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

class AtlasScene : public Layer
{
public:
	AtlasScene();
	~AtlasScene();
	CREATE_FUNC(AtlasScene);
	virtual bool init();

	static Scene* createScene();

	Size visibleSize = Director::getInstance()->getVisibleSize();

private:
	ui::Button* _backToMenuBtn;

};
#endif // _ATLASSCENE_H_


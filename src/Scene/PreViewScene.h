#ifndef _PREVIEWSCENE_H_
#define _PREVIEWSCENE_H_

#include "cocos2d.h"
#include "ui\CocosGUI.h"

#include "Load.h"

USING_NS_CC;

class PreViewScene : public Layer
{
public:
	PreViewScene();
	~PreViewScene();
	virtual bool init();
	void preview2(float dt);
	CREATE_FUNC(PreViewScene);
	static Scene* createScene();

private:
	Size visibleSize;

private:
	ui::Button* _clickBtn;
	

};
#endif

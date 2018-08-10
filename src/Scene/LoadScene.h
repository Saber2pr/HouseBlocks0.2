#ifndef _LOADSCENE_H_
#define _LOADSCENE_H_

#include "cocos2d.h"
#include "Load.h"

USING_NS_CC;

class LoadScene : public Layer
{
public:
	LoadScene();
	~LoadScene();
	CREATE_FUNC(LoadScene);
	virtual bool init();
	void next(float dt);
	static Scene* createScene();
};
#endif


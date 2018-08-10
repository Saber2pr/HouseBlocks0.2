#ifndef __LOAD_H__
#define __LOAD_H__

#include "cocos2d.h"

USING_NS_CC;

class Load : public Sprite
{
public:
	Load();
	~Load();
	virtual bool init();
	CREATE_FUNC(Load);
};
#endif

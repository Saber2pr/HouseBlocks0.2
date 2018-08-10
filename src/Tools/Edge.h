#ifndef __EDGE_H__
#define __EDGE_H__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;
class Edge : public Node
{
public:
	Edge();
	~Edge();
	virtual bool init();
	CREATE_FUNC(Edge);

};
#endif


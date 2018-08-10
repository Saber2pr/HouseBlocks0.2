#include "Edge.h"


Edge::Edge()
{
}


Edge::~Edge()
{
}

bool Edge::init()
{
	Node::init();
	
	Size visibleSize = Director::getInstance()->getVisibleSize();

	setAnchorPoint(Vec2(0.5, 0.5));//EdgeÄ¬ÈÏÃªµãÊÇ£¨0£¬ 0£©
	setPosition(visibleSize.width / 2, visibleSize.height / 2);

	Size edgeSize = Size(visibleSize.width, visibleSize.height + 20);
	setContentSize(edgeSize);

	setPhysicsBody(PhysicsBody::createEdgeBox(visibleSize));

	return true;
}



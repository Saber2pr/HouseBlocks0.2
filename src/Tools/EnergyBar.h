#ifndef _ENERGYBAR_H_
#define _ENERGYBAR_H_

#include "cocos2d.h"

USING_NS_CC;

class EnergyBar : public Node
{
public:
	EnergyBar();
	~EnergyBar();
	CREATE_FUNC(EnergyBar);
	virtual bool init();

protected:
	ProgressTimer* _progress;
	Sprite* _background;

protected:
	float _percentage;

public:
	void updateView(int value);


};
#endif // _ENERGYBAR_H_


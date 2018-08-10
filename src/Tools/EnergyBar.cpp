#include "EnergyBar.h"



EnergyBar::EnergyBar() : _percentage(0)
{
}


EnergyBar::~EnergyBar()
{
}

bool EnergyBar::init()
{
	if (!Node::init())
	{
		return false;
	}

	//add sprites
	_progress = ProgressTimer::create(Sprite::create("energy_front.png"));

	_progress->setType(ProgressTimer::Type::BAR);
	_progress->setMidpoint(Vec2(0, 0));
	_progress->setBarChangeRate(Vec2(0, 1));

	_background = Sprite::create("energy_back.png");
	
	this->addChild(_background);
	this->addChild(_progress);

	this->setContentSize(_background->getContentSize());

	updateView(0.0f);

	return true;

}

void EnergyBar::updateView(int value)
{
	auto percentage = value / 100.0f;
	_progress->setPercentage(percentage);
	_percentage = percentage;

}


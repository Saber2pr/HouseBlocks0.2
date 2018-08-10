#include "ScoreText.h"



ScoreText::ScoreText() : _score(0)
{
}


ScoreText::~ScoreText()
{
}

bool ScoreText::init()
{
	if (!Node::init())
	{
		return false;
	}

	_text = ui::TextAtlas::create("1234567890", "num.png", 30, 30, "0");

	_text->setAnchorPoint(Vec2(1, 0.5));

	this->addChild(_text);

	return true;
}

void ScoreText::updateView(int value)
{
	_text->setString(StringUtils::format("%d", value / 10));

}

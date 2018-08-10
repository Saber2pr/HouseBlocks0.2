#ifndef _SCORETEXT_H_
#define _SCORETEXT_H_

#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

class ScoreText : public Node
{
public:
	ScoreText();
	~ScoreText();
	CREATE_FUNC(ScoreText);
	virtual bool init();
	virtual void updateView(int value);

protected:
	ui::TextAtlas* _text;

protected:
	int _score;

};
#endif // _DEBUG


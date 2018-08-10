#include "AnimateTool.h"



AnimateTool::AnimateTool()
{
}


AnimateTool::~AnimateTool()
{
}

Sprite * AnimateTool::getSpriteAction(char* s, float width, float height, int n, float fps, Sprite* p)
{
	Vector<cocos2d::SpriteFrame*> pAniFrameVec = Vector<cocos2d::SpriteFrame*>(n);//用模板命名一个名为pAniFrameVec容量n的Vector
	char szFile[20] = "";
	Sprite *pSprite = nullptr;
	for (int i = 1; i <= n; i++)
	{
		sprintf(szFile, s, i);
		auto pFrame = SpriteFrame::create(szFile, Rect(0, 0, width, height));
		if (i == 1)
		{
			pSprite = Sprite::createWithSpriteFrame(pFrame);
			pSprite->setAnchorPoint(Vec2(0, 0));
			pSprite->setPosition(Vec2(p->getContentSize().width / 2, p->getContentSize().height / 2));
			p->addChild(pSprite, 1);
		}
		pAniFrameVec.pushBack(pFrame);
	}
	Animation *pAnimation = Animation::createWithSpriteFrames(pAniFrameVec, fps);
	Animate* pAnimate = Animate::create(pAnimation);
	ActionInterval* seq = (ActionInterval *)(Sequence::create(pAnimate, NULL));
	pSprite->runAction(RepeatForever::create(seq));
	return pSprite;
}

ActionInterval* AnimateTool::getSpriteAction(std::string plist, std::string png, int n, float fps)
{
	std::string name = png;
	for (size_t i = 1; i < name.length(); i++ )
	{
		if (name[i] == '.')
		{
			name = name.substr(0, i);
			break;
		}
	}

	SpriteFrameCache* sfc = SpriteFrameCache::getInstance();
	sfc->addSpriteFramesWithFile(plist, png);
	Vector<cocos2d::SpriteFrame*> pAniFrameVec = Vector<cocos2d::SpriteFrame*>(n);
	std::stringstream ss;
	std::string filename;
	char num[50] = "";
	for (int i = 1; i <= n; i++)
	{
		sprintf(num, "%02d", i);
		ss.clear();
		ss.str("");
		ss << name << num << ".png";
		filename = ss.str();
		auto pFrame = sfc->getSpriteFrameByName(filename);
		pAniFrameVec.pushBack(pFrame);
	}
	Animation *pAnimation = Animation::createWithSpriteFrames(pAniFrameVec, fps);
	Animate* pAnimate = Animate::create(pAnimation);
	ActionInterval* seq = (ActionInterval *)(Sequence::create(pAnimate, NULL));
	return seq;
}

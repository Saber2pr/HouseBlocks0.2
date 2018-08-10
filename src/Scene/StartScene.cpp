#include "StartScene.h"
#include "SceneMediator.h"
#include "UserData.h"

StartScene::StartScene() :
	_background(nullptr), _startBtn(nullptr), _scoreBtn(nullptr), _musicLockBtn(nullptr), _aboutBtn(nullptr), _exitBtn(nullptr)
{
}


StartScene::~StartScene()
{
}


bool StartScene::init()
{
	if (Layer::init() == false)
	{
		return false;
	}

	//add musicBox
	optionLock = 20;
	musicBox = MusicBox::createWithMusicFlag(optionLock);

	//add viewSize
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//add sprites
	_background = Sprite::create("StartMap.png");
	_background->setAnchorPoint(Vec2(0, 0));
	_background->setPosition(0, 0);
	addChild(_background);

	//add buttons
	float btnAnchorPoint = visibleSize.height / 4 + 60;
	_startBtn = ui::Button::create("StartBtn.png");
	_startBtn->setPosition(Vec2(visibleSize.width / 2, btnAnchorPoint + 60));
	addChild(_startBtn);
	_startBtn->addClickEventListener(
		[](Ref* ref)
	{
		SceneMediator::getInstance()->gotoNoticeScene();
	}
		);

	_musicLockBtn = ui::Button::create("MusicLockBtn.png");
	_musicLockBtn->setPosition(Vec2(visibleSize.width / 2, btnAnchorPoint));
	addChild(_musicLockBtn);
	_musicLockBtn->addClickEventListener(
		[this](Ref* ref)
	{
		
		if (optionLock == 20)
		{
			optionLock = 1;
		}
		else
		{
			optionLock = 20;
		}

		musicBox->musicFlagListener(optionLock);

	}
		);
	
	_atlasBtn = ui::Button::create("AtlasBtn.png");
	_atlasBtn->setPosition(Vec2(visibleSize.width / 2, btnAnchorPoint - 60));
	addChild(_atlasBtn);
	_atlasBtn->addClickEventListener(
		[](Ref* ref)
	{
		SceneMediator::getInstance()->gotoAtlasScene();
	}
		);

	_aboutBtn = ui::Button::create("AboutBtn.png");
	_aboutBtn->setPosition(Vec2(visibleSize.width / 2, btnAnchorPoint - 60 - 60));
	addChild(_aboutBtn);
	_aboutBtn->addClickEventListener(
		[](Ref* ref)
	{
		SceneMediator::getInstance()->gotoAboutScene();
	}
		);

	_exitBtn = ui::Button::create("ExitBtn.png");
	_exitBtn->setPosition(Vec2(visibleSize.width / 2, btnAnchorPoint - 60 - 60 - 60));
	addChild(_exitBtn);
	_exitBtn->addClickEventListener(
		[](Ref* ref)
	{
		Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		exit(0);
#endif

	}

	);

	return true;
}

Scene * StartScene::createScene()
{
	auto scene = Scene::create();
	auto layer = StartScene::create();
	scene->addChild(layer);

	return scene;
}

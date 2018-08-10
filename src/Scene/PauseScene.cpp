#include "PauseScene.h"
#include "SceneMediator.h"
#include "UserData.h"

PauseScene::PauseScene() :
	_pauseBack(nullptr),
	_backToGameBtn(nullptr)
{
}


PauseScene::~PauseScene()
{
}


bool PauseScene::init()
{
	Layer::init();

	//add musicBox
	optionLock = 0;
	musicBox = MusicBox::create();

	//add viewSize
	auto visibleSize = Director::getInstance()->getVisibleSize();

	//add sprites
	_pauseBack = Sprite::create("PauseMap.png");
	_pauseBack->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(_pauseBack, 0);

	//add buttons
	_backToGameBtn = ui::Button::create("BackToGameBtn.png");
	_backToGameBtn->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 ));
	this->addChild(_backToGameBtn, 1);
	_backToGameBtn->addClickEventListener(
		[](Ref* ref)
	{
		Director::getInstance()->popScene();
	}
		);

	_musicLockBtn = ui::Button::create("MusicLockBtn.png");
	_musicLockBtn->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 3));
	addChild(_musicLockBtn);
	_musicLockBtn->addClickEventListener(
		[this](Ref* ref)
	{
		musicBox->musicFlagListener(optionLock);
		optionLock = !optionLock;
	}
	);

	return true;
}

Scene * PauseScene::createScene()
{
	auto scene = Scene::create();
	auto layer = PauseScene::create();
	scene->addChild(layer);
	return scene;
}

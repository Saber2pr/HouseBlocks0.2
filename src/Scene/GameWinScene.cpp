#include "GameWinScene.h"
#include "SceneMediator.h"


GameWinScene::GameWinScene()
{
}


GameWinScene::~GameWinScene()
{
}

bool GameWinScene::init()
{
	Layer::init();

	auto visibleSize = Director::getInstance()->getVisibleSize();

	//add sprites
	auto winScene = Sprite::create("WinMap.png");
	winScene->setPosition(visibleSize.width / 2, visibleSize.height / 2);	
	addChild(winScene);
	
	//add ui
	_backToMenuBtn = ui::Button::create("BackToMenuBtn.png");
	_backToMenuBtn->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 4));
	addChild(_backToMenuBtn);

	_backToMenuBtn->addClickEventListener(
		[](Ref* ref)
	{
		SceneMediator::getInstance()->backtoStartScene();
	}
	);

	return true;
}

Scene* GameWinScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameWinScene::create();
	scene->addChild(layer);
	return scene;
}

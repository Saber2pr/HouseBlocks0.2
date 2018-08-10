#include "GameOverScene.h"
#include "SceneMediator.h"

GameOverScene::GameOverScene():
	_restartBtn(nullptr),
	_backToMenuBtn(nullptr)
{
}


GameOverScene::~GameOverScene()
{
}

bool GameOverScene::init()
{
	Layer::init();//下面addChild都会加在这个层里

	visibleSize = Director::getInstance()->getVisibleSize();

	Sprite* spriteOver = Sprite::create("OverMap.png");
	spriteOver->setPosition(visibleSize.width/2, visibleSize.height/2);
	addChild(spriteOver);

	_restartBtn = ui::Button::create("RestartBtn.png");
	_restartBtn->setPosition(Vec2(visibleSize.width / 2, visibleSize.height/4));
	addChild(_restartBtn);

	_restartBtn->addClickEventListener(
		[](Ref* ref)
	{
		SceneMediator::getInstance()->backtoHelloWorldScene();
	}
		);

	_backToMenuBtn = ui::Button::create("BackToMenuBtn.png");
	_backToMenuBtn->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 4 - 60));
	addChild(_backToMenuBtn);

	_backToMenuBtn->addClickEventListener(
		[](Ref* ref)
	{
		SceneMediator::getInstance()->backtoStartScene();
	}
		);


	return true;
}

Scene * GameOverScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameOverScene::create();
	scene->addChild(layer);
	return scene;
}

#include "NoticeScene.h"
#include "SceneMediator.h"
#include "MusicBox.h"

NoticeScene::NoticeScene() : _nextBtn(nullptr)
{
}


NoticeScene::~NoticeScene()
{
}


Scene * NoticeScene::createScene()
{
	auto scene = Scene::create();
	auto layer = NoticeScene::create();
	scene->addChild(layer);
	return scene;
}

bool NoticeScene::init()
{
	Layer::init();

	//init viewSize
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//add music
	auto music1 = MusicBox::createWithMusicFlag(19);

	//add sprites
	auto pause = Sprite::create("NoticeMap.png");
	pause->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(pause);
	
	//add buttons
	_nextBtn = ui::Button::create("NextBtn.png");
	_nextBtn->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 4));
	addChild(_nextBtn);
	_nextBtn->addClickEventListener(
		[](Ref* ref)
	{
		SceneMediator::getInstance()->gotoHelloWorldScene();
	}
		);

	return true;
}

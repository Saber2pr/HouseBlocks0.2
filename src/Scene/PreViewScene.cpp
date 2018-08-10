#include "PreViewScene.h"
#include "SceneMediator.h"

PreViewScene::PreViewScene() : _clickBtn(nullptr)
{
	visibleSize = Director::getInstance()->getVisibleSize();
}


PreViewScene::~PreViewScene()
{
}

bool PreViewScene::init()
{
	Layer::init();

	auto p1 = Sprite::create("PreviewMap1.png");
	p1->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(p1);
	
	auto loading = Load::create();
	loading->setPosition(370, 34);
	addChild(loading);
	
	scheduleOnce(schedule_selector(PreViewScene::preview2), 2.00f); //在1.0f (1秒) 之后执行preview2方法，并且只执行一次。355,20

	return true;
}


void PreViewScene::preview2(float dt)
{
	auto p2 = Sprite::create("PreviewMap2.png");
	p2->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(p2);

	_clickBtn = ui::Button::create("ClickBtn.png");
	_clickBtn->setPosition(Vec2(333, 97));
	addChild(_clickBtn);
	_clickBtn->addClickEventListener(
		[](Ref* ref)
	{
		SceneMediator::getInstance()->gotoLoadScene();
	}
		);

}

Scene * PreViewScene::createScene()
{
	auto scene = Scene::create();
	auto layer = PreViewScene::create();
	scene->addChild(layer);
	return scene;
}




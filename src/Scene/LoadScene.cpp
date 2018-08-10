#include "LoadScene.h"
#include "SceneMediator.h"


LoadScene::LoadScene()
{
}


LoadScene::~LoadScene()
{
}


bool LoadScene::init()
{
	Layer::init();

	//add viewSize
	auto visibleSize = Director::getInstance()->getVisibleSize();

	//add load
	auto loading = Load::create();
	loading->setPosition(370, 34);
	addChild(loading, 1);
	
	//add sprites
	auto loadMap = Sprite::create("LoadMap.png");
	loadMap->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(loadMap);

	auto loadResource = Sprite::create("LoadResource.png");
	loadResource->setPosition(360, 70);
	addChild(loadResource);

	//add update
	scheduleOnce(schedule_selector(LoadScene::next), 2.00f); //在1.0f (1秒) 之后执行preview2方法，并且只执行一次。355,20

	return true;
}

void LoadScene::next(float dt)
{
	SceneMediator::getInstance()->gotoStartScene();
}

Scene * LoadScene::createScene()
{
	auto scene = Scene::create();
	auto layer = LoadScene::create();
	scene->addChild(layer);
	return scene;
}

#include "AboutScene.h"
#include "SceneMediator.h"


AboutScene::AboutScene() : _backToMenuBtn(nullptr)
{
}


AboutScene::~AboutScene()
{
}


bool AboutScene::init()
{
	Layer::init();
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//add sprites
	auto aboutScene = Sprite::create("AboutMap.png");
	aboutScene->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(aboutScene);

	//add viewMagic
	ParticleSystem* ps1 = ParticleSnow::create();
	ps1->setTexture(Director::getInstance()->getTextureCache()->addImage("texture.png"));
	ps1->setPosition(Point(200, 810));
	addChild(ps1, 10);

	//add buttons
	_backToMenuBtn = ui::Button::create("BackToMenuBtn.png");
	_backToMenuBtn->setPosition(Vec2(visibleSize.width / 2 + 100, visibleSize.height / 4 - 110));
	addChild(_backToMenuBtn);
	_backToMenuBtn->addClickEventListener(
		[](Ref* ref)
	{
		SceneMediator::getInstance()->backtoStartScene();
	}
	);

	return true;
}

Scene * AboutScene::createScene()
{
	auto scene = Scene::create();
	auto layer = AboutScene::create();
	scene->addChild(layer);
	return scene;
}

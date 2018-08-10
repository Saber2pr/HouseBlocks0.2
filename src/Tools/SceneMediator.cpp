#include "SceneMediator.h"
#include "StartScene.h"
#include "PreViewScene.h"
#include "PauseScene.h"
#include "NoticeScene.h"
#include "LoadScene.h"
#include "HelloWorldScene.h"
#include "GameOverScene.h"
#include "GameWinScene.h"
#include "AboutScene.h"
#include "AtlasScene.h"

SceneMediator::SceneMediator()
{
}


SceneMediator::~SceneMediator()
{
	//delete(_instance);
}

SceneMediator* SceneMediator::_instance = nullptr;

SceneMediator* SceneMediator::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new SceneMediator;
	}
	return _instance;
}

void SceneMediator::gotoStartScene()
{
	auto reScene = TransitionMoveInL::create(0.3f, StartScene::createScene());
	Director::getInstance()->replaceScene(reScene);
}

void SceneMediator::backtoStartScene()
{
	auto reScene = TransitionMoveInR::create(0.3f, StartScene::createScene());
	Director::getInstance()->replaceScene(reScene);
}

void SceneMediator::backtoPreViewScene()
{
	auto reScene = TransitionMoveInR::create(0.3f, PreViewScene::createScene());
	Director::getInstance()->replaceScene(reScene);
}

void SceneMediator::pushPauseScene()
{
	auto rescene = TransitionSlideInT::create(0.3f, PauseScene::createScene());
	Director::getInstance()->pushScene(rescene);
}

void SceneMediator::popPauseScene()
{
	Director::getInstance()->popScene();//弹出暂停场景,返回上个场景。
}

void SceneMediator::gotoNoticeScene()
{
	auto reScene1 = TransitionSlideInL::create(0.5f, NoticeScene::createScene());
	Director::getInstance()->replaceScene(reScene1);
}

void SceneMediator::gotoLoadScene()
{
	auto reScene = TransitionCrossFade::create(0.7f, LoadScene::createScene());
	Director::getInstance()->replaceScene(reScene);
}

void SceneMediator::gotoHelloWorldScene()
{
	auto rescene = TransitionSlideInL::create(0.4f, HelloWorld::createScene());
	Director::getInstance()->replaceScene(rescene);
}

void SceneMediator::backtoHelloWorldScene()
{
	auto rescene = TransitionSlideInR::create(0.4f, HelloWorld::createScene());
	Director::getInstance()->replaceScene(rescene);
}

void SceneMediator::gotoGameWinScene()
{
	auto rescene = TransitionSlideInR::create(0.4f, GameWinScene::createScene());
	Director::getInstance()->replaceScene(rescene);
}

void SceneMediator::gotoGameOverScene()
{
	auto rescene = TransitionSlideInL::create(0.4f, GameOverScene::createScene());
	Director::getInstance()->replaceScene(rescene);
}

void SceneMediator::gotoAboutScene()
{
	auto reScene2 = TransitionMoveInL::create(0.3f, AboutScene::createScene());
	Director::getInstance()->replaceScene(reScene2);
}

void SceneMediator::gotoAtlasScene()
{
	auto reScene = TransitionCrossFade::create(0.7f, AtlasScene::createScene());
	Director::getInstance()->replaceScene(reScene);
}

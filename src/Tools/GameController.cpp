#include "GameController.h"
#include "SceneMediator.h"
#include "PauseScene.h"


void GameController::addBlock(int y)
{
	block1 = Block::create();
	block1->setPosition(getRandPointInforY(y));
	_layer->addChild(block1);

	block2 = Block::create();
	block2->setPosition(getRandPointInforY(y + 200));
	_layer->addChild(block2);

	block3 = Block::create();
	block3->setPosition(getRandPointInforY(y + 400));
	_layer->addChild(block3);

	block4 = Block::create();
	block4->setPosition(getRandPointInforY(y + 600));
	_layer->addChild(block4);

}

void GameController::addPowerBlock()
{
	auto powerBlock = PowerBlock::create();
	powerBlock->setPosition(getRandPointInforY(visibleSize.height));
	_layer->addChild(powerBlock);
}

void GameController::addViewMagic()
{
	psSnow = ParticleSnow::create();
	psSnow->setTexture(Director::getInstance()->getTextureCache()->addImage("Star.png"));
	psSnow->setPosition(Point(200, 810));
	_layer->addChild(psSnow, 10);

	psMeteor = ParticleMeteor::create();
	psMeteor->setTexture(Director::getInstance()->getTextureCache()->addImage("Star.png"));
	_layer->addChild(psMeteor, 10);

	psExplosion = ParticleExplosion::create();
	psExplosion->setTexture(Director::getInstance()->getTextureCache()->addImage("Star.png"));
	psExplosion->setContentSize(Size(100, 100));
	_layer->addChild(psExplosion);

}

Point GameController::getRandPointInforY(int y)
{
	int sand = visibleSize.width;
	int x = rand() % (sand);
	return Point(x, y);
}

void GameController::updateBlock(int front)
{
	int speed = 0;
	switch (front)
	{
	case up : speed = 5; break;
	case down : speed = - 5; break;
	case betterDown: speed = -10; break;

	default:
		break;
	}

	moveBlock(block1, speed);
	moveBlock(block2, speed);
	moveBlock(block3, speed);
	moveBlock(block4, speed);

}

void GameController::moveBlock(Block* block, int speed)
{
	block->setPositionY(block->getPosition().y + speed);
}

void GameController::addBtns()
{
	//add buttons

	_finishBtn = ui::Button::create("FinishBtn.png");
	_finishBtn->setPosition(Vec2(25, visibleSize.height - 25));
	_layer->addChild(_finishBtn, 1);
	_finishBtn->addClickEventListener(
		[](Ref* ref)
	{
		SceneMediator::getInstance()->backtoStartScene();
	}
	);
}

GameController::GameController()
	: _layer(nullptr),
	edge(nullptr),
	hero(nullptr),
	_pauseBtn(nullptr),
	_finishBtn(nullptr),
	block1(nullptr),
	block2(nullptr),
	block3(nullptr),
	block4(nullptr)
{
}


GameController::~GameController()
{
}


bool GameController::init(cocos2d::Layer * layer, float positionY)//将其他场景中的层取出来，进行设置， 在场景里用create（）参数设置。
{
	_layer = layer;
	_positionY = positionY;

	heightCount = 0;
	
	//add background
	background = Background::create();
	_layer->addChild(background, 0);

	//add hero
	hero = Hero::create(_layer, "GirlAction.plist", "GirlAction.png");
	hero->setPosition(50, hero->getContentSize().height + 80);
	height = 10;//hero初始高度为10;
	_layer->addChild(hero, 3);//添加hero到显示层

	//add blocks
	addBlock(120);

	//add ground
	Size size = Size(480, 40);
	ground = Sprite::create("Ground.png");
	ground->setPosition(visibleSize.width / 2, 6);
	_layer->addChild(ground, 0);

	//add edge
	edge = Edge::create();//头文件已声明类型，此处不可写auto edge
	edge->setPosition(visibleSize.width / 2, visibleSize.height / 2 + positionY);
	edge->setContentSize(visibleSize);//铺满整个屏幕
	_layer->addChild(edge, 1);

	//add energyBar
	_energyBar = EnergyBar::create();
	_energyBar->setPosition( 50.0f, visibleSize.height / 2);
	_layer->addChild(_energyBar);
	
	//add scoreText
	_scoreText = ScoreText::create();
	_scoreText->setPosition(Vec2(100, visibleSize.height - 150));
	_layer->addChild(_scoreText);
	
	//add buttons
	addBtns();

	//viewMagic
	addViewMagic();

	scheduleUpdate();

	return true;
}


void GameController::update(float dt)//帧函数
{
	//////////////////////////////////////////////////////////////////////////

	if (height > heightCount + 500)
	{
		heightCount = height;
		addPowerBlock();
	}

	//move back and ground
	if (hero->getPositionY() >= visibleSize.height * 0.75)//如果在屏幕顶部
	{
		background->moveCommand(betterDown);
		background->dealWithMoveCommand();
		updateBlock(betterDown);
		height = height + 5;
		ground->setPosition(visibleSize.width / 2, -height + _positionY);//地板下移
	}

	
	if (hero->getPositionY() >= visibleSize.height * 0.5 && hero->getPositionY() < visibleSize.height * 0.75)//如果在屏幕上方
	{//背景向下滚动，hero高度 + 1。
		//mapDown
		background->moveCommand(down);
		background->dealWithMoveCommand();
		updateBlock(down);
		height++;
		ground->setPosition(visibleSize.width / 2, -height + _positionY);//地板下移

	}
	else
	{
		if (hero->getPositionY() >= visibleSize.height * 0.25)//如果在屏幕中间
		{//背景不滚动

		}
		else//如果在屏幕下方
		{//背景向上滚动, 滚动时间由hero高度height决定。
			if (height >= 0)//如果hero在高空
			{
				//mapUp
				background->moveCommand(up);
				background->dealWithMoveCommand();
				updateBlock(up);
				height = height - 10;
				ground->setPosition(visibleSize.width / 2, -height + 30 + _positionY);//地板上移

			}

		}
	}

	//////////////////////////////////////////////////////////////////////////

	//judge the game result
	log("height = %d", height);
	if (height >= 100 || height < -20)//危险高度
	{
		overHeight = 1;
	}

	if (overHeight && height < 10)//如果从高处落下
	{
		SceneMediator::getInstance()->gotoGameOverScene();
	}

	if (height > 9000)
	{
		SceneMediator::getInstance()->gotoGameWinScene();
	}

	//////////////////////////////////////////////////////////////////////////

	//send the hero messagge
	hero->heroListener(_positionY);
	hero->height = height;
	hero->overHeight = overHeight;

	//updateViewMagic
	updateViewMagic();

	//////////////////////////////////////////////////////////////////////////

	//scoreText
	_scoreText->updateView(height);

	//energy
	_energyBar->updateView(height);

	//////////////////////////////////////////////////////////////////////////

	

}


bool GameController::hitTestPoint(Vec2 point)
{
	getTouchPoint(point);
	return edge->getBoundingBox().containsPoint(point);
}


void GameController::physicsContactEvent(int act)
{
	switch (act)
	{
	case normalAction: hero->getPhysicsBody()->setVelocity(Vec2(0, 480)); break;
	case greatAction: hero->getPhysicsBody()->setVelocity(Vec2(0, 1000)); powerLock = true; break;
	default:
		break;
	}
	
}

void GameController::touchEvent()
{
	psSnow->setPosition(_ptouch);
}

void GameController::getTouchPoint(Point ptouch)
{
	_ptouch = ptouch;
}

void GameController::updateViewMagic()
{
	//viewMagic
	if (powerLock == true)
	{
		frameCount++;
		psMeteor->setPosition(hero->getPosition());
		if (frameCount > 650)
		{
			powerLock = false;
		}
	}
	else
	{
		psMeteor->setPosition(Vec2::ZERO);
	}

	psExplosion->setPosition(_ptouch);

}

GameController * GameController::create(Layer * layer, float positionY)
{ 
	auto _ins = new GameController();
	_ins->init(layer, positionY);
	_ins->autorelease();
	return _ins;
}

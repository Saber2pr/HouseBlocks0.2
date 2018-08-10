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


bool GameController::init(cocos2d::Layer * layer, float positionY)//�����������еĲ�ȡ�������������ã� �ڳ�������create�����������á�
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
	height = 10;//hero��ʼ�߶�Ϊ10;
	_layer->addChild(hero, 3);//���hero����ʾ��

	//add blocks
	addBlock(120);

	//add ground
	Size size = Size(480, 40);
	ground = Sprite::create("Ground.png");
	ground->setPosition(visibleSize.width / 2, 6);
	_layer->addChild(ground, 0);

	//add edge
	edge = Edge::create();//ͷ�ļ����������ͣ��˴�����дauto edge
	edge->setPosition(visibleSize.width / 2, visibleSize.height / 2 + positionY);
	edge->setContentSize(visibleSize);//����������Ļ
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


void GameController::update(float dt)//֡����
{
	//////////////////////////////////////////////////////////////////////////

	if (height > heightCount + 500)
	{
		heightCount = height;
		addPowerBlock();
	}

	//move back and ground
	if (hero->getPositionY() >= visibleSize.height * 0.75)//�������Ļ����
	{
		background->moveCommand(betterDown);
		background->dealWithMoveCommand();
		updateBlock(betterDown);
		height = height + 5;
		ground->setPosition(visibleSize.width / 2, -height + _positionY);//�ذ�����
	}

	
	if (hero->getPositionY() >= visibleSize.height * 0.5 && hero->getPositionY() < visibleSize.height * 0.75)//�������Ļ�Ϸ�
	{//�������¹�����hero�߶� + 1��
		//mapDown
		background->moveCommand(down);
		background->dealWithMoveCommand();
		updateBlock(down);
		height++;
		ground->setPosition(visibleSize.width / 2, -height + _positionY);//�ذ�����

	}
	else
	{
		if (hero->getPositionY() >= visibleSize.height * 0.25)//�������Ļ�м�
		{//����������

		}
		else//�������Ļ�·�
		{//�������Ϲ���, ����ʱ����hero�߶�height������
			if (height >= 0)//���hero�ڸ߿�
			{
				//mapUp
				background->moveCommand(up);
				background->dealWithMoveCommand();
				updateBlock(up);
				height = height - 10;
				ground->setPosition(visibleSize.width / 2, -height + 30 + _positionY);//�ذ�����

			}

		}
	}

	//////////////////////////////////////////////////////////////////////////

	//judge the game result
	log("height = %d", height);
	if (height >= 100 || height < -20)//Σ�ո߶�
	{
		overHeight = 1;
	}

	if (overHeight && height < 10)//����Ӹߴ�����
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

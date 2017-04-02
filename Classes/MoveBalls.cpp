#include "MoveBalls.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"


USING_NS_CC;

using namespace cocostudio::timeline;
using namespace cocos2d::ui;
using namespace CocosDenshion;

Scene* MoveBalls::createScene() {
	auto scene = Scene::create();
	auto background = Layer::create();
	auto bcSprite = Sprite::create("background.png");
	bcSprite->setAnchorPoint(Vec2(0,0));
	background->addChild(bcSprite);
	scene->addChild(background);
	auto layer = MoveBalls::create();
	scene->addChild(layer);
	return scene;
}

bool MoveBalls::init() {

	if (!Layer::init())
	{
		return false;
	}
	//addProgressBar();
	visiableSize = Director::getInstance()->getVisibleSize();
	scheduleUpdate();
	addBall(100, 100);
	paddle = Paddle::create();
	addChild(paddle);
	addBrick();
	return true;
}

void MoveBalls::update(float dt) {
	ball->move();
	if (isKit(ball,paddle))
	{
		auto audio = SimpleAudioEngine::getInstance();
		audio->playEffect("kit.wav",false,1.0f,1.0f,1.0f);
		//auto random=CCRANDOM_0_1() * 2;
		//ball->setSpeedY(ball->getSpeedY()+random);
		ball->reverseSpeedY();
	}
	//auto loadingbar = (LoadingBar*)this->getChildByTag(1);
	//loadingbar->setPercent(time--);
	for (int i = 0; i < bricks.size(); i++)
	{
		auto brick = bricks.at(i);
		if (isKit(ball,brick))
		{
			auto audio = SimpleAudioEngine::getInstance();
			audio->playEffect("kit_brick.wav", false, 1.0f, 1.0f, 1.0f);
			bricks.eraseObject(brick);
			removeChild(brick);
			ball->reverseSpeedY();
		}
	}
}

void MoveBalls::addBall(float x, float y) {
	ball = Ball::create();
	ball->setPosition(x, y);
	addChild(ball);
}
MoveBalls::MoveBalls()
{
}

bool MoveBalls::isKit(Sprite* a, Sprite* b) {
	return PixelCollision::getInstance()->collidesWithSprite(a, b, true);
}

void MoveBalls::addProgressBar() {
	time = 100;
	auto loadingbar = LoadingBar::create("board.png");
	loadingbar->setDirection(LoadingBar::Direction::LEFT);
	loadingbar->setAnchorPoint(Vec2(0, 0));
	loadingbar->setPosition(Vec2(100, 480));
	loadingbar->setPercent(100);
	loadingbar->setTag(1);
	addChild(loadingbar);
}

void MoveBalls::addBrick() {
	auto width = visiableSize.width;
	auto height = visiableSize.height;

	auto dis = width / 5;
	for (int i = 0; i < 5; i++)
	{
		auto brick = Brick::create(0);
		brick->setAnchorPoint(Vec2(0,0));
		brick->setPosition(i*dis,height-brick->getContentSize().height);
		bricks.pushBack(brick);
		addChild(brick);
	}
	for (int i = 0; i < 5; i++)
	{
		auto brick = Brick::create(0);
		brick->setAnchorPoint(Vec2(0, 0));
		brick->setPosition(i*dis, height - 2*brick->getContentSize().height);
		bricks.pushBack(brick);
		addChild(brick);
	}
	for (int i = 0; i < 5; i++)
	{
		auto brick = Brick::create(0);
		brick->setAnchorPoint(Vec2(0, 0));
		brick->setPosition(i*dis, height - 3*brick->getContentSize().height);
		bricks.pushBack(brick);
		addChild(brick);
	}
	for (int i = 0; i < 5; i++)
	{
		auto brick = Brick::create(0);
		brick->setAnchorPoint(Vec2(0, 0));
		brick->setPosition(i*dis, height - 4*brick->getContentSize().height);
		bricks.pushBack(brick);
		addChild(brick);
	}
	for (int i = 0; i < 5; i++)
	{
		auto brick = Brick::create(0);
		brick->setAnchorPoint(Vec2(0, 0));
		brick->setPosition(i*dis, height - 4 * brick->getContentSize().height);
		bricks.pushBack(brick);
		addChild(brick);
	}
}


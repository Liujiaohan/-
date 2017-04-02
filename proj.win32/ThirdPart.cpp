#include "ThirdPart.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "MenuScene.h"
#include <stdlib.h>

#include <iostream>
#include <string>
#include <sstream>

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace std;




Scene* ThirdPart::createScene() {
	//create a physic scene
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->getDebugDrawMask();
	//add background

	//ball = static_cast<Button*> (skillLayer->getChildByName("Ball"));

	//create the main layer
	auto layer = ThirdPart::create();
	layer->setPhysicsWorld(scene->getPhysicsWorld());
	scene->addChild(layer);
	return scene;
}

bool ThirdPart::init() {

	if (!Layer::init())
	{
		return false;
	}
	gameLayer = (Layer*)CSLoader::createNode("SecondPart.csb");
	this->addChild(gameLayer);
	score = 0;
	isGameOver = false;
	visibleSize = Director::getInstance()->getVisibleSize();
	audio = SimpleAudioEngine::getInstance();
	counter = PointCounter::getInstance();
	
	num1 = static_cast<Sprite *> (gameLayer->getChildByName("Number1"));
	num2 = static_cast<Sprite *> (gameLayer->getChildByName("Number2"));

	num4 = static_cast<Sprite *> (gameLayer->getChildByName("Number4"));
	num3 = static_cast<Sprite *> (gameLayer->getChildByName("Number3"));


	auto contactListener = EventListenerPhysicsContact::create();
	//设置监听器的碰撞开始函数  
	contactListener->onContactSeparate = CC_CALLBACK_1(ThirdPart::onContactSeperate, this);
	contactListener->onContactBegin = CC_CALLBACK_1(ThirdPart::onContactBegin, this);
	//添加到事件分发器中  
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
	scheduleUpdate();

	addBall(visibleSize.width / 2, 80);
	addPaddle();
	addBrick();
	addEdge();
	//addLostLayer();
	return true;
}

void ThirdPart::addEdge() {
	auto leftedge = Sprite::create();
	PhysicsBody* leftboundBody = PhysicsBody::createEdgeBox(Size(2, visibleSize.height), PHYSICSBODY_MATERIAL_DEFAULT, 3);
	leftboundBody->getShape(0)->setFriction(1.0f);
	leftboundBody->getShape(0)->setRestitution(1.0f);
	leftedge->setPhysicsBody(leftboundBody);
	leftedge->setPosition(Point(2, visibleSize.height / 2));
	this->addChild(leftedge);
	leftedge->setTag(0);


	auto rightedge = Sprite::create();
	PhysicsBody* rightboundBody = PhysicsBody::createEdgeBox(Size(2, visibleSize.height), PHYSICSBODY_MATERIAL_DEFAULT, 3);
	rightboundBody->getShape(0)->setFriction(1.0f);
	rightboundBody->getShape(0)->setRestitution(1.0f);
	rightedge->setPhysicsBody(rightboundBody);
	rightedge->setPosition(Point(visibleSize.width, visibleSize.height / 2));
	this->addChild(rightedge);
	rightedge->setTag(0);

	auto upedge = Sprite::create();
	PhysicsBody* upboundBody = PhysicsBody::createEdgeBox(Size(visibleSize.width, 2), PHYSICSBODY_MATERIAL_DEFAULT, 3);
	upboundBody->getShape(0)->setFriction(1.0f);
	upboundBody->getShape(0)->setRestitution(1.0f);
	upedge->setPhysicsBody(upboundBody);
	upedge->setPosition(Point(visibleSize.width / 2, visibleSize.height));
	this->addChild(upedge);
	upedge->setTag(0);

}

void ThirdPart::update(float dt) {
	if (!isGameOver)
	{
		float x = mballBody->getVelocity().x;
		float y = mballBody->getVelocity().y;
		if (x != 350 && x != -350)
		{
			if (x<0)
			{
				x = -350;
			}
			else
			{
				x = 350;
			}
		}
		if (y != 350 && y != -350)
		{
			if (y<0)
			{
				y = -350;
			}
			else
			{
				y = 350;
			}
		}

		mballBody->setVelocity(Vec2(x, y));


		int a = score / 1000;
		int b = score / 100 % 10;
		int c = score / 10 % 10;
		int d = score % 10;

		num1->setTexture(Director::getInstance()->getTextureCache()->addImage(counter->getPng(a)));
		num2->setTexture(Director::getInstance()->getTextureCache()->addImage(counter->getPng(b)));
		num3->setTexture(Director::getInstance()->getTextureCache()->addImage(counter->getPng(c)));
		num4->setTexture(Director::getInstance()->getTextureCache()->addImage(counter->getPng(d)));
	}
	else
	{
		addLostLayer();
	}
	if (ball->getPosition().y<0)
	{
		isGameOver = true;
	}
}

void ThirdPart::addBall(float x, float y) {
	ball = Ball::create();
	ball->setPosition(x, y);
	//Point points[3] = { Point(-30.00000, -30.50000), Point(0.00000, 30.50000), Point(30.00000, -30.50000) };
	//PhysicsBody* ballBodyOne = PhysicsBody::createPolygon(points,3,PHYSICSBODY_MATERIAL_DEFAULT,Vec2(0,0));
	//PhysicsBody* ballBodyOne = PhysicsBody::createCircle(ball->getContentSize().width / 2+3, PHYSICSBODY_MATERIAL_DEFAULT);
	auto manger = PointCounter::getInstance();
	auto currentBall = manger->getCurrentBall();
	Point points[5] = { Point(-13.00000,-43.00000), Point(-27.00000, 10.00000), Point(-10.00000, 43.00000),Point(27.00000,0.00000) ,Point(27.00000,-43.00000) };
	//Point points[4] = { Point(-30.00000, -30.50000), Point(0.00000, 30.50000), Point(10.00000, 30.50000),Point(30.00000, -30.50000) };
	PhysicsBody* ballBodyOne;
	switch (currentBall)
	{
	case 1:
		ballBodyOne = PhysicsBody::createCircle(ball->getContentSize().width / 2 + 3, PHYSICSBODY_MATERIAL_DEFAULT);
		break;
	case 3:
		ballBodyOne = PhysicsBody::createCircle(ball->getContentSize().width / 2 + 3, PHYSICSBODY_MATERIAL_DEFAULT);
		break;
	case 4:
		ballBodyOne = PhysicsBody::createPolygon(points, 5, PHYSICSBODY_MATERIAL_DEFAULT, Vec2(0, 0));
		break;
	case 5:
		ballBodyOne = PhysicsBody::createPolygon(points, 5, PHYSICSBODY_MATERIAL_DEFAULT, Vec2(0, 0));
		break;
	default:
		ballBodyOne = PhysicsBody::createCircle(ball->getContentSize().width / 2 + 3, PHYSICSBODY_MATERIAL_DEFAULT);
		break;
	}
	//是否设置物体为静态  
	//ballBody->setDynamic(false);  
	//设置物体的恢复力  
	ballBodyOne->getShape(0)->setRestitution(1.0f);
	//设置物体的摩擦力  
	ballBodyOne->getShape(0)->setFriction(1.0f);
	//设置物体密度  
	ballBodyOne->getShape(0)->setDensity(1.0f);
	//设置质量  
	//ballBodyOne->getShape(0)->setMass(5000);  
	//设置物体是否受重力系数影响  
	ballBodyOne->setGravityEnable(false);

	ballBodyOne->setCategoryBitmask(0xFFFFFFFF);
	ballBodyOne->setContactTestBitmask(0x00000110);
	ballBodyOne->setCollisionBitmask(0x00000100);
	//设置物体的冲力  
	Vect force = Vect(500000.0f, 800000.0f);
	ballBodyOne->applyImpulse(force);
	mballBody = ballBodyOne;
	//把物体添加到精灵中  
	ball->setPhysicsBody(ballBodyOne);
	//设置标志  
	ball->setTag(0);

	addChild(ball);
}

bool ThirdPart::onContactBegin(const PhysicsContact& contact)
{
	return true;
}

void ThirdPart::onContactSeperate(PhysicsContact& contact) {
	Sprite* spriteA = (Sprite*)contact.getShapeA()->getBody()->getNode();
	Sprite* spriteB = (Sprite*)contact.getShapeB()->getBody()->getNode();
	if (!isGameOver)
	{
		collusion(spriteA, spriteB);
	}
}

void ThirdPart::collusion(Sprite* spriteA, Sprite* spriteB) {
	int tagA = spriteA->getTag();
	int tagB = spriteB->getTag();
	//if (tagA == 2 && tagB == 1)
	//{
	//	audio->playEffect("kit_brick.wav", false, 1.0f, 1.0f, 1.0f);

	//	auto sun = ParticleExplosion::create();
	//	sun->setTexture(Director::getInstance()->getTextureCache()->addImage("star.png"));
	//	sun->setPosition(spriteB->getPosition());

	//	sun->setTotalParticles(300);
	//	sun->setLife(1.0f);

	//	this->addChild(sun);
	//	spriteA->removeFromParent();
	//	//		counter->addPoint(100);

	//	score = score + 2;


	//}
	if (tagB == 0 && tagA == 1)
	{
		audio->playEffect("kit_brick.wav", false, 1.0f, 1.0f, 1.0f);
		auto sun = ParticleExplosion::create();
		sun->setTexture(Director::getInstance()->getTextureCache()->addImage("star.png"));
		sun->setPosition(spriteB->getPosition());

		sun->setTotalParticles(300);
		sun->setLife(1.0f);

		this->addChild(sun);
		spriteA->removeFromParent();
		score += 2;
	}
	if ((tagB == 0) && ((tagA==3)||(tagA==4)||(tagA==5))
	{
		audio->playEffect("kit_brick.wav", false, 1.0f, 1.0f, 1.0f);

		auto sun = ParticleExplosion::create();
		sun->setTexture(Director::getInstance()->getTextureCache()->addImage("star.png"));
		sun->setPosition(spriteB->getPosition());

		sun->setTotalParticles(300);
		sun->setLife(1.0f);

		this->addChild(sun);
		spriteA->removeFromParent();
		score += 2;
	}
	else if((tagB == 0) && (tagA == 2))
	{
		audio->playEffect("kit_brick.wav", false, 1.0f, 1.0f, 1.0f);

		auto sun = ParticleExplosion::create();
		sun->setTexture(Director::getInstance()->getTextureCache()->addImage("star.png"));
		sun->setPosition(spriteB->getPosition());

		sun->setTotalParticles(300);
		sun->setLife(1.0f);

		this->addChild(sun);
		spriteA->removeFromParent();
		score -= 10;
	}
	else if ((tagA == 11 && tagB == 0))
	{
		audio->playEffect("kit.wav", false, 1.0f, 1.0f, 1.0f);
	}
}

void ThirdPart::addBrick() {
	string name = "Brick_";
	
	for (int i = 1; i < 31; i++)
	{
		stringstream ss;
		ss << name << i;
		auto brick = static_cast<Sprite *> (gameLayer->getChildByName(ss.str()));
		ss.clear();
		PhysicsBody* brickBody = PhysicsBody::createEdgeBox(Size(brick->getContentSize().width, brick->getContentSize().height), PhysicsMaterial(0.1f, 1.0f, 0.0f));
		//			PhysicsBody* brickBody = PhysicsBody::createCircle(brick->getContentSize().width / 2, PHYSICSBODY_MATERIAL_DEFAULT);
		//是否设置物体为静态  
		brickBody->setDynamic(true);
		//设置物体的恢复力  
		brickBody->getShape(0)->setRestitution(1.0f);
		//设置物体的摩擦力  
		brickBody->getShape(0)->setFriction(1.0f);
		//设置物体密度  
		brickBody->getShape(0)->setDensity(1.0f);
		//设置质量  
		//ballBodyOne->getShape(0)->setMass(5000);  
		//设置物体是否受重力系数影响  
		brickBody->setGravityEnable(false);
		brickBody->setCategoryBitmask(0xFFFFFFF0);
		brickBody->setContactTestBitmask(0x00000010);
		brickBody->setCollisionBitmask(0x00000001);
		//设置物体的冲力  
		//Vect force = Vect(500000.0f, 500000.0f);
		//brickBody->applyImpulse(force);
		//把物体添加到精灵中  
		brick->setPhysicsBody(brickBody);
		//设置标志  
		bricks.pushBack(brick);
	}
}

void ThirdPart::addPaddle() {

	paddle = Paddle::create();
	paddle->setPosition(visibleSize.width / 2, 30);
	//PhysicsBody* paddleBody = PhysicsBody::createEdgeBox(Size(paddle->getContentSize().width, paddle->getContentSize().height), PhysicsMaterial(0.1f, 1.0f, 0.0f));
	//			PhysicsBody* brickBody = PhysicsBody::createCircle(brick->getContentSize().width / 2, PHYSICSBODY_MATERIAL_DEFAULT);
	//是否设置物体为静态  

	auto manger = PointCounter::getInstance();
	auto currentBoard = manger->getCurrentBoard();
	Point points[16] = { Point(-94.00000, -5.00000), Point(-94.00000, 40.00000),Point(-76.00000,40.00000) ,Point(-76.00000,0.00000),
		Point(-58.00000,0.00000), Point(-58.00000, -13.00000), Point(-18.00000, -13.00000),Point(-18.00000,-26.00000) ,Point(18.00000,-26.00000) ,
		Point(18.00000,-13.00000), Point(58.00000,-13.00000), Point(58.00000, 0.00000),Point(76.00000,0.00000) ,Point(76.00000,40.00000),
		Point(94.00000,40.00000), Point(94.00000, -5.00000) };
	//Point points[4] = { Point(-30.00000, -30.50000), Point(0.00000, 30.50000), Point(10.00000, 30.50000),Point(30.00000, -30.50000) };
	PhysicsBody* paddleBody;;
	switch (currentBoard)
	{
	case 2:
		paddleBody = PhysicsBody::createEdgeBox(Size(paddle->getContentSize().width, paddle->getContentSize().height), PhysicsMaterial(0.1f, 1.0f, 0.0f));
		break;
	case 6:
		paddleBody = PhysicsBody::createEdgeBox(Size(paddle->getContentSize().width, paddle->getContentSize().height), PhysicsMaterial(0.1f, 1.0f, 0.0f));
		break;
	case 8:
		paddleBody = PhysicsBody::createEdgeBox(Size(paddle->getContentSize().width, paddle->getContentSize().height), PhysicsMaterial(0.1f, 1.0f, 0.0f));
		break;
	default:
		paddleBody = PhysicsBody::createCircle(ball->getContentSize().width / 2 + 3, PHYSICSBODY_MATERIAL_DEFAULT);
		break;
	}
	paddleBody->setDynamic(true);
	//设置物体的恢复力  
	paddleBody->getShape(0)->setRestitution(1.0f);
	//设置物体的摩擦力  
	paddleBody->getShape(0)->setFriction(1.0f);
	//设置物体密度  
	paddleBody->getShape(0)->setDensity(1.0f);
	//设置质量  
	//ballBodyOne->getShape(0)->setMass(5000);  
	//设置物体是否受重力系数影响  
	paddleBody->setGravityEnable(false);
	paddleBody->setCategoryBitmask(0xFFFFFFF0);
	paddleBody->setContactTestBitmask(0x00000010);
	paddleBody->setCollisionBitmask(0x00000001);
	//设置物体的冲力  
	//Vect force = Vect(500000.0f, 500000.0f);
	//brickBody->applyImpulse(force);
	//把物体添加到精灵中  
	paddle->setPhysicsBody(paddleBody);
	//设置标志  
	paddle->setTag(11);
	addChild(paddle);
}

void ThirdPart::addLostLayer() {
	lostLayer = Layer::create();
	auto lostBackground = Sprite::create("Background/FailScene.png");
	lostBackground->setAnchorPoint(Vec2(0, 0));
	lostBackground->setPosition(90, 200);
	lostLayer->addChild(lostBackground);
	auto spnum1 = Sprite::create("Number/0.png");
	auto spnum2 = Sprite::create("Number/0.png");
	spnum1->setAnchorPoint(Vec2(0, 0));
	spnum1->setPosition(509, 240);
	lostLayer->addChild(spnum1);

	spnum2->setAnchorPoint(Vec2(0, 0));
	spnum2->setPosition(549, 244);
	lostLayer->addChild(spnum2);

	auto spnum3 = Sprite::create("Number/0.png");//860 595
	spnum3->setAnchorPoint(Vec2(0, 0));
	spnum3->setPosition(589, 244);

	auto spnum4 = Sprite::create("Number/0.png");//885 595
	spnum4->setAnchorPoint(Vec2(0, 0));
	spnum4->setPosition(629, 244);
	/*
	save total score
	*/
	int total = UserDefault::getInstance()->getIntegerForKey("total", 0);
	total += score;
	UserDefault::getInstance()->setIntegerForKey("total", total);

	lostLayer->addChild(spnum4);
	lostLayer->addChild(spnum3);
	int a = score / 1000;
	int b = score / 100 % 10;
	int c = score / 10 % 10;
	int d = score % 10;

	spnum1->setTexture(Director::getInstance()->getTextureCache()->addImage(counter->getPng(a)));
	spnum2->setTexture(Director::getInstance()->getTextureCache()->addImage(counter->getPng(b)));
	spnum3->setTexture(Director::getInstance()->getTextureCache()->addImage(counter->getPng(c)));
	spnum4->setTexture(Director::getInstance()->getTextureCache()->addImage(counter->getPng(d)));


	auto listener4 = EventListenerTouchOneByOne::create();
	listener4->setSwallowTouches(true);
	auto backButton = Sprite::create("Button/Button_Back.png");
	backButton->setAnchorPoint(Vec2(0, 0));
	backButton->setPosition(375, 133);

	listener4->onTouchBegan = [](Touch* touch, Event* event) {
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		// 获取当前点击点所在相对按钮的位置坐标
		Point locationInNode = target->convertToNodeSpace(touch->getLocation());
		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);

		// 点击范围判断检测
		if (rect.containsPoint(locationInNode))
		{
			auto scene = MenuScene::createScene();
			auto transitions = TransitionFade::create(3.0f, scene);
			Director::getInstance()->replaceScene(transitions);
			return true;
		}
		return false;
	};
	lostLayer->addChild(backButton);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener4, backButton);
	this->addChild(lostLayer);
}

void ThirdPart::addWinLayer() {
	winLayer = Layer::create();
	auto lostBackground = Sprite::create("Background/PassScene.png");
	lostBackground->setAnchorPoint(Vec2(0, 0));
	lostBackground->setPosition(90, 200);
	winLayer->addChild(lostBackground);
	auto spnum1 = Sprite::create("Number/0.png");
	auto spnum2 = Sprite::create("Number/0.png");
	spnum1->setAnchorPoint(Vec2(0, 0));
	spnum1->setPosition(509, 240);
	winLayer->addChild(spnum1);

	spnum2->setAnchorPoint(Vec2(0, 0));
	spnum2->setPosition(549, 244);
	winLayer->addChild(spnum2);

	auto spnum3 = Sprite::create("Number/0.png");//860 595
	spnum3->setAnchorPoint(Vec2(0, 0));
	spnum3->setPosition(589, 244);

	auto spnum4 = Sprite::create("Number/0.png");//885 595
	spnum4->setAnchorPoint(Vec2(0, 0));
	spnum4->setPosition(629, 244);

	int total = UserDefault::getInstance()->getIntegerForKey("total", 0);
	total += score;
	UserDefault::getInstance()->setIntegerForKey("total", total);

	winLayer->addChild(spnum4);
	winLayer->addChild(spnum3);
	int a = score / 1000;
	int b = score / 100 % 10;
	int c = score / 10 % 10;
	int d = score % 10;

	spnum1->setTexture(Director::getInstance()->getTextureCache()->addImage(counter->getPng(a)));
	spnum2->setTexture(Director::getInstance()->getTextureCache()->addImage(counter->getPng(b)));
	spnum3->setTexture(Director::getInstance()->getTextureCache()->addImage(counter->getPng(c)));
	spnum4->setTexture(Director::getInstance()->getTextureCache()->addImage(counter->getPng(d)));


	auto listener4 = EventListenerTouchOneByOne::create();
	listener4->setSwallowTouches(true);
	auto backButton = Sprite::create("Button/Button_Back.png");
	backButton->setAnchorPoint(Vec2(0, 0));
	backButton->setPosition(375, 133);

	listener4->onTouchBegan = [](Touch* touch, Event* event) {
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		// 获取当前点击点所在相对按钮的位置坐标
		Point locationInNode = target->convertToNodeSpace(touch->getLocation());
		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);

		// 点击范围判断检测
		if (rect.containsPoint(locationInNode))
		{
			auto scene = MenuScene::createScene();
			auto transitions = TransitionFade::create(3.0f, scene);
			Director::getInstance()->replaceScene(transitions);
			return true;
		}
		return false;
	};
	winLayer->addChild(backButton);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener4, backButton);


	auto listener5 = EventListenerTouchOneByOne::create();
	listener5->setSwallowTouches(false);
	auto goonButton = Sprite::create("Button/Button_begin.png");
	goonButton->setAnchorPoint(Vec2(0, 0));

	goonButton->setPosition(560, 133);

	listener5->onTouchBegan = [](Touch* touch, Event* event) {
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		// 获取当前点击点所在相对按钮的位置坐标
		Point locationInNode = target->convertToNodeSpace(touch->getLocation());
		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);

		// 点击范围判断检测
		if (rect.containsPoint(locationInNode))
		{
			auto scene = ThirdPart::createScene();
			auto transitions = TransitionFade::create(3.0f, scene);
			Director::getInstance()->replaceScene(transitions);
			return true;
		}
		return false;
	};
	winLayer->addChild(goonButton);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener5, goonButton);

	this->addChild(winLayer);
}

ThirdPart::ThirdPart()
{
}


ThirdPart::~ThirdPart()
{
}

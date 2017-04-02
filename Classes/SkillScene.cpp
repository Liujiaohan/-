#include "SkillScene.h"
#include "PointCounter.h"
#include "MenuScene.h"

Scene* SkillScene::createScene() {
	auto scene = Scene::create();
	auto layer = SkillScene::create();
	scene->addChild(layer);
	return scene;
}

bool SkillScene::init() {
	if (!Layer::init())
	{
		return false;
	}
	skillLayer = (Layer*)CSLoader::createNode("skill.csb");
	this->addChild(skillLayer);

	ball = static_cast<Button*> (skillLayer->getChildByName("Ball"));
	ball->setTag(1);
	board = static_cast<Button*> (skillLayer->getChildByName("board"));
	board->setTag(2);
	sun = static_cast<Button*> (skillLayer->getChildByName("Sun"));
	sun->setTag(3);
	knife = static_cast<Button*> (skillLayer->getChildByName("Knife"));
	knife->setTag(4);
	knife1 = static_cast<Button*> (skillLayer->getChildByName("Knife1"));
	knife1->setTag(5);
	longBoard = static_cast<Button*> (skillLayer->getChildByName("Longboard"));
	longBoard->setTag(6);
	spider = static_cast<Button*> (skillLayer->getChildByName("Spider"));
	spider->setTag(7);
	newBoard = static_cast<Button*> (skillLayer->getChildByName("NewBoard"));
	newBoard->setTag(8);
	buttonBack = static_cast<Button*> (skillLayer->getChildByName("ButtonBack"));
	buttonBack->setTag(9);

	num1= static_cast<Sprite*> (skillLayer->getChildByName("Number_1"));
	num2 = static_cast<Sprite*> (skillLayer->getChildByName("Number_2"));
	num3 = static_cast<Sprite*> (skillLayer->getChildByName("Number_3"));
	num4 = static_cast<Sprite*> (skillLayer->getChildByName("Number_4"));

	ball->addTouchEventListener(this, toucheventselector(SkillScene::touchEvent));
	sun->addTouchEventListener(this, toucheventselector(SkillScene::touchEvent));
	board->addTouchEventListener(this, toucheventselector(SkillScene::touchEvent));
	knife->addTouchEventListener(this, toucheventselector(SkillScene::touchEvent));
	knife1->addTouchEventListener(this, toucheventselector(SkillScene::touchEvent));
	spider->addTouchEventListener(this, toucheventselector(SkillScene::touchEvent));
	newBoard->addTouchEventListener(this, toucheventselector(SkillScene::touchEvent));
	buttonBack->addTouchEventListener(this, toucheventselector(SkillScene::touchEvent));
	longBoard->addTouchEventListener(this, toucheventselector(SkillScene::touchEvent));

	choosenBall = Sprite::create("check.png");
	choosenBoard = Sprite::create("check.png");

	setBall();
	setBoard();
	addNum();
	this->addChild(choosenBall);
	this->addChild(choosenBoard);
	return true;
}
void SkillScene::addNum() {
	auto manger = PointCounter::getInstance();
	int score= UserDefault::getInstance()->getIntegerForKey("total", 0);
	int a = score / 1000;
	int b = score / 100 % 10;
	int c = score / 10 % 10;
	int d = score % 10;

	num1->setTexture(Director::getInstance()->getTextureCache()->addImage(manger->getPng(a)));
	num2->setTexture(Director::getInstance()->getTextureCache()->addImage(manger->getPng(b)));
	num3->setTexture(Director::getInstance()->getTextureCache()->addImage(manger->getPng(c)));
	num4->setTexture(Director::getInstance()->getTextureCache()->addImage(manger->getPng(d)));
}
void SkillScene::setBall() {
	auto manger = PointCounter::getInstance();
	auto currentBall = manger->getCurrentBall();
	switch (currentBall)
	{
	case 1:
		choosenBall->setPosition(ball->getPosition());
		break;
	case 3:
		choosenBall->setPosition(sun->getPosition());
		break;
	case 4:
		choosenBall->setPosition(knife->getPosition());
		break;
	case 5:
		choosenBall->setPosition(knife1->getPosition());
		break;
	case 7:
		choosenBall->setPosition(spider->getPosition());
		break;
	default:
		break;
	}
}

void SkillScene::setBoard() {
	auto manger = PointCounter::getInstance();
	auto currentBoard = manger->getCurrentBoard();
	switch (currentBoard)
	{
	case 2:
		choosenBoard->setPosition(board->getPosition());
		break;
	case 6:
		choosenBoard->setPosition(longBoard->getPosition());
		break;
	case 8:
		choosenBoard->setPosition(newBoard->getPosition());
		break;
	default:
		break;
	}
}
void SkillScene::touchEvent(CCObject* pSender, TouchEventType type) {
	auto button = (Button*)pSender;
	int tag = button->getTag();
	auto manger = PointCounter::getInstance();
	int score = UserDefault::getInstance()->getIntegerForKey("total", 0);
	if (tag == 1)
	{
		manger->setCurrentBall(1);
		choosenBall->setPosition(ball->getPosition());
	}
	else if (tag == 2)
	{
		choosenBoard->setPosition(board->getPosition());
		manger->setCurrentBoard(2);
	}
	else if ((tag == 3) & (score>500))
	{
		choosenBall->setPosition(sun->getPosition());
		manger->setCurrentBall(3);
	}
	else if ((tag == 4) &(score>2000)) {
	
		choosenBall->setPosition(knife->getPosition());
		manger->setCurrentBall(4);
	}
	else if ((tag == 5) &(score>3000))
	{
		choosenBall->setPosition(knife1->getPosition());
		manger->setCurrentBall(5);
	}
	else if ((tag == 6) & (score>1300))
	{
		choosenBoard->setPosition(longBoard->getPosition());
		manger->setCurrentBoard(6);
	}
	else if ((tag == 7) & (score>1500))
	{
		choosenBall->setPosition(spider->getPosition());
		manger->setCurrentBall(7);
	}
	else if ((tag == 8) & (score>1000))
	{
		choosenBoard->setPosition(newBoard->getPosition());
		manger->setCurrentBoard(8);
	}
	else if (tag == 9)
	{
		auto scene = MenuScene::createScene();
		auto transitions = TransitionFade::create(3.0f, scene);
		Director::getInstance()->replaceScene(transitions);
	}
}

SkillScene::SkillScene()
{
}


SkillScene::~SkillScene()
{
}

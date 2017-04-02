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

	ball->addTouchEventListener(this, toucheventselector(SkillScene::touchEvent));
	sun->addTouchEventListener(this, toucheventselector(SkillScene::touchEvent));
	board->addTouchEventListener(this, toucheventselector(SkillScene::touchEvent));
	knife->addTouchEventListener(this, toucheventselector(SkillScene::touchEvent));
	knife1->addTouchEventListener(this, toucheventselector(SkillScene::touchEvent));
	spider->addTouchEventListener(this, toucheventselector(SkillScene::touchEvent));
	newBoard->addTouchEventListener(this, toucheventselector(SkillScene::touchEvent));
	buttonBack->addTouchEventListener(this, toucheventselector(SkillScene::touchEvent));
	longBoard->addTouchEventListener(this, toucheventselector(SkillScene::touchEvent));


	return true;
}


void SkillScene::touchEvent(CCObject* pSender, TouchEventType type) {
	auto button = (Button*)pSender;
	int tag = button->getTag();
	auto manger = PointCounter::getInstance();
	if (tag == 1)
	{

		manger->setCurrentBall(1);
	}
	else if (tag == 2)
	{
		manger->setCurrentBoard(2);
	}
	else if (tag == 3)
	{
		manger->setCurrentBall(3);
	}
	else if (tag == 4)
	{
		manger->setCurrentBall(4);
	}
	else if (tag == 5)
	{
		manger->setCurrentBall(5);
	}
	else if (tag == 6)
	{
		manger->setCurrentBoard(6);
	}
	else if (tag == 7)
	{
		manger->setCurrentBall(7);
	}
	else if (tag == 8)
	{
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

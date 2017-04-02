#include "MenuScene.h"
#include "ChooseScene.h"
#include "FirstPart.h"
#include "SkillScene.h"
USING_NS_CC;

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
using namespace cocostudio::timeline;
using namespace cocos2d::ui;
using namespace CocosDenshion;

Scene* MenuScene::createScene() {
	auto scene = Scene::create();

	auto layer = Layer::create();
	auto background = Sprite::create("Background/MenuSceneBackground.png");
	background->setAnchorPoint(Vec2(0,0));
	layer->addChild(background);

	scene->addChild(layer);

	auto layer2 = MenuScene::create(); 
	scene->addChild(layer2);
	return scene;
}


bool MenuScene::init()
{
	if ( !Layer::init() )
	{
	return false;
	}
	visiableSize = Director::getInstance()->getVisibleSize();
	addStartButton();
	addRankButton();
	addAboutButton();
	return true;
}

void MenuScene::addStartButton(){
	auto startButton = Sprite::create("Button/Button_begin.png");
	startButton->setAnchorPoint(Vec2(0, 0));
	startButton->setPosition(150,140);
	auto listener1 = EventListenerTouchOneByOne::create();
	listener1->setSwallowTouches(true);

	listener1->onTouchBegan = [](Touch* touch, Event* event) {
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		// 获取当前点击点所在相对按钮的位置坐标
		Point locationInNode = target->convertToNodeSpace(touch->getLocation());
		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);

		// 点击范围判断检测
		if (rect.containsPoint(locationInNode))
		{
			target->setTexture(Director::getInstance()->getTextureCache()->addImage("Button/Button_begin1.png"));
			return true;
		}
		return false;
	};
	listener1->onTouchEnded = [](Touch* touch, Event* event) {
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		// 获取当前点击点所在相对按钮的位置坐标
		Point locationInNode = target->convertToNodeSpace(touch->getLocation());
		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);

		// 点击范围判断检测
		if (rect.containsPoint(locationInNode))
		{
			auto scene = ChooseScene::createScene();
			auto transitions = TransitionFade::create(3.0f, scene);
			Director::getInstance()->replaceScene(transitions);
			return true;
		}
		return false;
	};
	this->addChild(startButton);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, startButton);

}

void MenuScene::addAboutButton(){
	auto startButton = Sprite::create("Button/Button_setting.png");
	startButton->setAnchorPoint(Vec2(0, 0));
	startButton->setPosition(600, 140);
	auto listener1 = EventListenerTouchOneByOne::create();
	listener1->setSwallowTouches(true);

	listener1->onTouchBegan = [](Touch* touch, Event* event) {
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		// 获取当前点击点所在相对按钮的位置坐标
		Point locationInNode = target->convertToNodeSpace(touch->getLocation());
		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);

		// 点击范围判断检测
		if (rect.containsPoint(locationInNode))
		{
			target->setTexture(Director::getInstance()->getTextureCache()->addImage("Button/Button_setting1.png"));
			return true;
		}
		return false;
	};
	listener1->onTouchEnded = [](Touch* touch, Event* event) {
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		// 获取当前点击点所在相对按钮的位置坐标
		Point locationInNode = target->convertToNodeSpace(touch->getLocation());
		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);

		// 点击范围判断检测
		if (rect.containsPoint(locationInNode))
		{
			auto scene = ChooseScene::createScene();
			auto transitions = TransitionFade::create(3.0f, scene);
			Director::getInstance()->replaceScene(transitions);
			return true;
		}
		return false;
	};

	this->addChild(startButton);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, startButton);
}

void MenuScene::addRankButton(){
	auto startButton = Sprite::create("Button/Button_skill.png");
	startButton->setAnchorPoint(Vec2(0, 0));
	startButton->setPosition(375, 140);

	auto listener1 = EventListenerTouchOneByOne::create();
	listener1->setSwallowTouches(true);
	listener1->onTouchBegan = [](Touch* touch, Event* event) {
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		// 获取当前点击点所在相对按钮的位置坐标
		Point locationInNode = target->convertToNodeSpace(touch->getLocation());
		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);

		// 点击范围判断检测
		if (rect.containsPoint(locationInNode))
		{
			target->setTexture(Director::getInstance()->getTextureCache()->addImage("Button/Button_skill1.png"));
			return true;
		}
		return false;
	};
	listener1->onTouchEnded = [](Touch* touch, Event* event) {
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		// 获取当前点击点所在相对按钮的位置坐标
		Point locationInNode = target->convertToNodeSpace(touch->getLocation());
		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);

		// 点击范围判断检测
		if (rect.containsPoint(locationInNode))
		{
			auto scene = SkillScene::createScene();
			auto transitions = TransitionFade::create(3.0f, scene);
			Director::getInstance()->replaceScene(transitions);
			return true;
		}
		return false;
	};
	this->addChild(startButton);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, startButton);
}
MenuScene::MenuScene()
{
}


MenuScene::~MenuScene()
{
}

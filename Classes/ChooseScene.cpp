#include "ChooseScene.h"
#include "ThirdPart.h"
#include "SecondPart.h"
#include "ForthPart.h"
#include "FifthPart.h"

Scene* ChooseScene::createScene() {
	auto scene = Scene::create();
	auto layer = ChooseScene::create();
	scene->addChild(layer);
	return scene;
}

bool ChooseScene::init() {
	if (!Layer::init())
	{
		return false;
	}
	chooseNode= (Layer*)CSLoader::createNode("Layer.csb");
	this->addChild(chooseNode);

	button1 = static_cast<Button*> (chooseNode->getChildByName("Button_1"));
	button1->setTag(1);
	button2 = static_cast<Button*> (chooseNode->getChildByName("Button_2"));
	button2->setTag(2);
	button3 = static_cast<Button*> (chooseNode->getChildByName("Button_3"));
	button3->setTag(3);
	button4 = static_cast<Button*> (chooseNode->getChildByName("Button_4"));
	button4->setTag(4);
	button5 = static_cast<Button*> (chooseNode->getChildByName("Button_5"));
	button5->setTag(5);

	button1->addTouchEventListener(this,toucheventselector(ChooseScene::touchEvent));
	button2->addTouchEventListener(this, toucheventselector(ChooseScene::touchEvent));
	button3->addTouchEventListener(this, toucheventselector(ChooseScene::touchEvent));
	button4->addTouchEventListener(this, toucheventselector(ChooseScene::touchEvent));
	button5->addTouchEventListener(this, toucheventselector(ChooseScene::touchEvent));

	return true;
}

void ChooseScene::touchEvent(CCObject* pSender,TouchEventType type) {
	auto button = (Button*)pSender;
	int tag = button->getTag();
	if (tag==1)
	{
		auto scene = FirstPart::createScene();
		auto transitions = TransitionFade::create(1.2f, scene);
		Director::getInstance()->replaceScene(transitions);
	}
	else if (tag==2)
	{
		auto scene = SecondPart::createScene();
		auto transitions = TransitionFade::create(1.2f, scene);
		Director::getInstance()->replaceScene(transitions);
	}
	else if (tag==3)
	{
		auto scene = ThirdPart::createScene();
		auto transitions = TransitionFade::create(1.2f, scene);
		Director::getInstance()->replaceScene(transitions);
	}

	else if (tag == 4)
	{
		auto scene = ForthPart::createScene();
		auto transitions = TransitionFade::create(1.2f, scene);
		Director::getInstance()->replaceScene(transitions);
	}
	else if (tag == 5)
	{
		auto scene = FifthPart::createScene();
		auto transitions = TransitionFade::create(1.2f, scene);
		Director::getInstance()->replaceScene(transitions);
	}
}
ChooseScene::ChooseScene()
{
}


ChooseScene::~ChooseScene()
{
}

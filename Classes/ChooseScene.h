#pragma once
#include <cocos2d.h>
#include <FirstPart.h>
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"


USING_NS_CC;

using namespace cocos2d::ui;
using namespace cocostudio::timeline;
using namespace CocosDenshion;


class ChooseScene :
	public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(ChooseScene);
	void touchEvent(CCObject* pSender,TouchEventType type);
	ChooseScene();
	~ChooseScene();

private:
	Layer* chooseNode;
	Button* button1;
	Button* button2;
	Button* button3;
	Button* button4;
	Button* button5;
};


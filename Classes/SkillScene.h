#pragma once
#include <cocos2d.h>
#include <FirstPart.h>
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"


USING_NS_CC;

using namespace cocos2d::ui;
using namespace cocostudio::timeline;
using namespace CocosDenshion;


class SkillScene :
	public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(SkillScene);
	void touchEvent(CCObject* pSender, TouchEventType type);
	void setBall();
	void setBoard();
	void addNum();
	SkillScene();
	~SkillScene();

private:
	Layer* skillLayer;
	Button* buttonBack;
	Button* ball;
	Button* sun;
	Button* knife;
	Button* knife1;
	Button* newBoard;
	Button* spider;
	Button* longBoard;
	Button* board;
	Sprite* num1;
	Sprite* num2;
	Sprite* num3;
	Sprite* num4;

	Sprite* choosenBall;
	Sprite* choosenBoard;
};


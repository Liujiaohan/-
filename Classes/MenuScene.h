#pragma once
#include "cocos2d.h"
USING_NS_CC;

class MenuScene:public cocos2d::Layer
{
public:
	virtual bool init();
	static cocos2d::Scene* createScene();
	CREATE_FUNC(MenuScene);
	MenuScene();
	~MenuScene();
private:
	Size visiableSize;
	void addStartButton();
	void addRankButton();
	void addAboutButton();
};


#pragma once
#include <cocos2d.h>
#include <stdio.h>


USING_NS_CC;

class Paddle:public cocos2d::Sprite
{
public:
	virtual bool init();
	EventListenerKeyboard* listener;
	CREATE_FUNC(Paddle);
	void registerDragListener();
	Vec2 direction;
	virtual void update(float dt);
	void onKeyPressed(EventKeyboard::KeyCode keycode,Event *event);
	void onKeyReleased(EventKeyboard::KeyCode keycode, Event *event);
	Paddle();
	~Paddle();
	void move(Vec2 vec);
private:
	Size visiableSize;
	bool pressing;
};


#pragma once
#include <stdio.h>
#include <cocos2d.h>
USING_NS_CC;
class Ball:public cocos2d::Sprite 
{
public:
	virtual bool init();

	void move();
	CREATE_FUNC(Ball);
	Ball();
	~Ball() {}
	void setSpeedX(float speed);
	void setSpeedY(float speed);
	void reverseSpeedY();
	float getSpeedY();
private:
	float speedX, speedY;
	Size visiableSize;
};


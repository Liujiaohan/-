#pragma once
#include <cocos2d.h>
#include <stdio.h>
USING_NS_CC;
class Brick :public cocos2d::Sprite
{
public:
	int hitCount;
	virtual bool init();
	//CREATE_FUNC(Brick);
	static Brick* create(int type);
	void setType(int type);
	int getType();
	Brick(int type);
	~Brick(){}
private:
	int type;
};


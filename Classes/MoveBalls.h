#pragma once

#include "cocos2d.h"
#include "Ball.h"
#include "Paddle.h"
#include "PixelCollision.h"
#include "Brick.h"


class MoveBalls :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	virtual void update(float dt);

	MoveBalls();
	~MoveBalls() {};

	bool isKit(Sprite* a, Sprite* b);

	CREATE_FUNC(MoveBalls);

private:
	Size visiableSize;
	Ball* ball;
	Paddle* paddle;

	void addBall(float x, float y);
	cocos2d::Vector<Brick*> bricks;
	int time;
	void addProgressBar();
	void addBrick();
};
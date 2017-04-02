#pragma once
#include "Ball.h"
#include "cocos2d.h"
#include "Paddle.h"
#include "Brick.h"
#include "SimpleAudioEngine.h"
#include "PointCounter.h"

using namespace cocos2d::ui;
using namespace CocosDenshion;

class ForthPart :public cocos2d::Layer
{
public:
	PointCounter* counter;
	ForthPart();
	~ForthPart();
	int map[10][5] = { { 2,0,1,0 },{ 2,0,1,0 },{ 2,0,1,0 },{ 2,0,1,0 },{ 2,0,1,0 },{ 2,0,1,0 },{ 2,0,1,0 },{ 2,0,1,0 },{ 2,0,1,0 },{ 2,0,1,0 } };

	static cocos2d::Scene* createScene();

	Layer* numLayer;

	virtual bool init();

	virtual void update(float dt);

	void setPhysicsWorld(PhysicsWorld* world) { mWorld = world; }

	PhysicsWorld* mWorld;
	PhysicsBody *mballBody;
	CREATE_FUNC(ForthPart);
	int score;
	bool onContactBegin(const PhysicsContact& contact);
	void onContactSeperate(PhysicsContact& contact);
private:
	bool isGameOver;
	bool isWin;
	void collusion(Sprite*, Sprite*);
	Layer* gameLayer;
	Layer* winLayer;
	Layer* lostLayer;
	Sprite* num1;
	Sprite* num2;
	Sprite* num3;
	Sprite* num4;
	SimpleAudioEngine* audio;
	Size visibleSize;
	Ball* ball;
	Paddle* paddle;

	void addBall(float x, float y);
	void addEdge();
	void addWinLayer();
	void addLostLayer();
	cocos2d::Vector<Sprite*> bricks;
	int time;
	void addBrick();
	void addPaddle();
};


#pragma once
#include "cocos2d.h"
#include <iostream>

using namespace cocos2d;

class PointCounter
{
public:
	int score;
	static PointCounter* getInstance();
	char* getPng(int num);
	int getCurrentBall();
	int getCurrentBoard();
	void setCurrentBall(int a);
	void setCurrentBoard(int b);
	void addPoint(int point);
	void resetPoint();
	PointCounter();
	~PointCounter();
private:
	static 	PointCounter* instance;
	Layer* mlayer;
	Sprite* spNum1;
	Sprite* spNum2;
};


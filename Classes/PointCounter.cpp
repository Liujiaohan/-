#include "PointCounter.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"


USING_NS_CC;

using namespace cocostudio::timeline;
using namespace cocos2d::ui;

PointCounter* PointCounter::instance = nullptr;

PointCounter* PointCounter::getInstance() {
	if (instance==nullptr)
	{
		instance = new PointCounter();
	}
	return instance;
}

int PointCounter::getCurrentBall() {
	auto currentBall = UserDefault::getInstance()->getIntegerForKey("currentBall", 1);
	return currentBall;
}

int PointCounter::getCurrentBoard() {
	auto currentBoard = UserDefault::getInstance()->getIntegerForKey("currentBoard", 2);
	return currentBoard;
}

void PointCounter::setCurrentBall(int a) {
	UserDefault::getInstance()->setIntegerForKey("currentBall", a);
}

void PointCounter::setCurrentBoard(int a) {
	UserDefault::getInstance()->setIntegerForKey("currentBoard", a);
}


char* PointCounter::getPng(int num) {
	switch (num)
	{
	case 0:
		return "Number/0.png";
		break;
	case 1:
		return "Number/1.png";
		break;
	case 2:
		return "Number/2.png";
		break;
	case 3:
		return "Number/3.png";
		break;
	case 4:
		return "Number/4.png";
		break;
	case 5:
		return "Number/5.png";
		break;
	case 6:
		return "Number/6.png";
		break;
	case 7:
		return "Number/7.png";
		break;
	case 8:
		return "Number/8.png";
		break;
	case 9:
		return "Number/9.png";
		break;
	default:
		return "Number/0.png";
		break;
	}
}
void PointCounter::addPoint(int point) {
	score += point;
}
void PointCounter::resetPoint() {
	score = 0;
}
PointCounter::PointCounter()
{
	score = 0;
}


PointCounter::~PointCounter()
{
}

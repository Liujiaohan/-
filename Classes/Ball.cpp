#include "Ball.h"
#include "PointCounter.h"
bool Ball::init() {
//	normalBrick = 0;
//	transparentBrick = 1;
//	slowBrick = 2;
//	rigidBrick = 3;
	auto manger = PointCounter::getInstance();
	int currentBall = manger->getCurrentBall();
	//initWithFile("Ball/Ball.png");
	switch (currentBall)
	{
	case 1:
		initWithFile("Ball/Ball.png");
		break;
	case 4:
		initWithFile("Ball/Knife.png");
		break;
	case 5:
		initWithFile("Ball/Knife1.png");
		break;
	case 7:
		initWithFile("Ball/Spider.png");
		break;
	case 3:
		initWithFile("Ball/Sun.png");
		break;
	default:
		initWithFile("Ball/Ball.png");
		break;
	}

	speedX = CCRANDOM_0_1() * 5 + 5;
	speedY = CCRANDOM_0_1() * 5 + 5;
	visiableSize = Director::getInstance()->getVisibleSize();
	return true;
}

void Ball::move() {
	setPosition(getPositionX()+speedX,getPositionY()+speedY);
	if (getPositionX()>(visiableSize.width-this->getContentSize().width))
	{
		speedX = -speedX;
	}
	if (getPositionX()<this->getContentSize().width/2)
	{
		speedX = -speedX;
	}
	if (getPositionY()>(visiableSize.height-this->getContentSize().height/2))
	{
		speedY = -speedY;
	}
	if (getPositionY()<(this->getContentSize().height/2))
	{
		Director::getInstance()->pause();
	}
}
Ball::Ball()
{
}

void Ball::setSpeedX(float speed) {
	speedX = speed;
}

void Ball::setSpeedY(float speed) {
	speedY = speed;
}

void Ball::reverseSpeedY() {
//	speedY = speedY + CCRANDOM_0_1() * 1;
	speedY = -speedY;
}

float Ball::getSpeedY() {
	return speedY;
}
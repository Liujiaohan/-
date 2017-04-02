#include "Brick.h"
bool Brick::init() {
	switch (type)
	{
	case 0:
		initWithFile("Brick/Brick.png");//casual brick
		hitCount = 1;
		break;
	case 1:
		initWithFile("Brick/Brick.png");//hit twice brick
		hitCount = 2;
		break;
	case 2:
		initWithFile("Brick/Brick.png");//tansparent brick
		hitCount = 1;
		break;
	case 3:
		initWithFile("Brick/Brick.png");//rigid brick
		hitCount = 1;
		break;
	default:
		break;
	}

	return true;
}

Brick::Brick(int t)
{
	this->type = t;
}

void Brick::setType(int type) {
	//this->type = type;
	//if (type==0)
	//{
	//	this->setTexture(Sprite::create("brick")->getTexture());
	//}
	//else if (type == 1)
	//{
	//	this->setTexture(Sprite::create("brick_1")->getTexture());
	//}
	//else if (type == 2)
	//{
	//	this->setTexture(Sprite::create("brick_2")->getTexture());
	//}
	//else if (type == 2)
	//{
	//	this->setTexture(Sprite::create("brick")->getTexture());
	//}

}

int Brick::getType() {
	return type;
}

Brick* Brick::create(int type) 
{ 
	Brick *pRet = new Brick(type);
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}


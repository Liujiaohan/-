#include "Paddle.h"
#include "PointCounter.h"


Paddle::Paddle()
{
}


Paddle::~Paddle()
{
}

bool Paddle::init() {
	auto manger = PointCounter::getInstance();
	int currentBoard = manger->getCurrentBoard();
	switch (currentBoard)
	{
	case 2:
		initWithFile("board.png");
		break;
	case 6:
		initWithFile("LongBoard.png");
		break;
	case 8:
		initWithFile("NewBoard.png");
		break;
	default:
		break;
	}
	
	visiableSize = Director::getInstance()->getVisibleSize();
	setPosition(visiableSize.width / 2, 0);
	direction = Vec2(0,0);
	pressing = false;
	this->registerDragListener();
	this->scheduleUpdate(); 
	return true;
}

void Paddle::registerDragListener() {
	listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(Paddle::onKeyPressed,this);
	listener->onKeyReleased = CC_CALLBACK_2(Paddle::onKeyReleased,this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
}

void Paddle::onKeyPressed(EventKeyboard::KeyCode keyCode,Event* event) {
	switch (keyCode) {
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		pressing = true;
		direction = Vec2(15,0);
		break;
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		pressing = true;
		direction = Vec2(-15,0);
		break;
	default:
		break;
	}
}

void Paddle::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event) {
	pressing = false;
	direction = Vec2(0,0);
}

void Paddle::move(Vec2 vec) {
	auto position = this->getPosition() + vec;
	auto positionX = position.x;
	if ((positionX<visiableSize.width-getContentSize().width/2)&(positionX>getContentSize().width / 2))
	{
		this->setPosition(this->getPosition() + vec);
	}
}

void Paddle::update(float dt) {
	if (pressing) {
		move(direction);
	}
}
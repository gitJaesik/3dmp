#include "Hero.h"
#include "Po.h"
#include "missile.h"
#include <windows.h>
#include <iostream>


Hero::Hero()
{
	// 생성자에서 actorInfo._pt가 초기화가 안 되어있기 때문에 쓰레기값이 입력 된다.
}

Hero::Hero(const std::string& actorName) : Actor(actorName)
{
	
}

Hero::~Hero()
{
}

void Hero::update()
{
	Actor::update();
}

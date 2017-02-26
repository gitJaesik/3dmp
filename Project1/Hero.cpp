#include "Hero.h"
#include "Po.h"
#include <windows.h>
#include <iostream>


Hero::Hero()
{
	// 생성자에서 actorInfo._pt가 초기화가 안 되어있기 때문에 쓰레기값이 입력 된다.
}

Hero::~Hero()
{
}

void Hero::update()
{
	Po* po = static_cast<Po*>(this->getChildNodes()[0]);

	if (GetAsyncKeyState(VK_LEFT) & 0x8001)
		po->_theta -= 0.03f;
		//po->_theta += 0.03f;
		//_theta += 0.03f;

	if (GetAsyncKeyState(VK_RIGHT) & 0x8001)
		po->_theta += 0.03f;
		//po->_theta -= 0.03f;
		//_theta -= 0.03f;
}

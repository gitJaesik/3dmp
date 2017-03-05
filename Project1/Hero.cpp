#include "Hero.h"
#include "Po.h"
#include "missile.h"
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

	if (GetAsyncKeyState(VK_RIGHT) & 0x8001)
		po->_theta += 0.03f;

	if (GetAsyncKeyState(VK_SPACE) & 0x8001) {
		// po 밑에 missle 추가하기
		po->addChildNode(new missile);

		missile* missile1 = new missile;
		missile1->actorInfo = ActorInfo(18, 8, 0, 1);
	}

	Actor::update();
}

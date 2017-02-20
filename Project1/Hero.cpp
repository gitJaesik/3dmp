#include "Hero.h"
#include "Po.h"
#include <windows.h>
#include <iostream>


Hero::Hero()
{
	// 포의 위치 : 생성자에서 actorInfo._pt가 초기화가 안 되어있기 때문에 쓰레기값이 입력 된다.
	//_d = actorInfo._pt;

	//_d.y -= 2;
	//_d.x -= 1;


	
}



Hero::~Hero()
{
}


void Hero::update()
{
	_d = actorInfo._pt;

	Po* po = static_cast<Po*>(this->_ChildNode[0]);


	if (GetAsyncKeyState(VK_LEFT) & 0x8001)
		po->_theta += 0.03f;
		//_theta += 0.03f;

	if (GetAsyncKeyState(VK_RIGHT) & 0x8001)
		po->_theta -= 0.03f;
		//_theta -= 0.03f;
}
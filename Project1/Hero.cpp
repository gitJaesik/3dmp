#include "Hero.h"
#include "Po.h"
#include <windows.h>
#include <iostream>


Hero::Hero()
{
	// �����ڿ��� actorInfo._pt�� �ʱ�ȭ�� �� �Ǿ��ֱ� ������ �����Ⱚ�� �Է� �ȴ�.
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

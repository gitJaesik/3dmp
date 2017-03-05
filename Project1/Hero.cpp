#include "Hero.h"
#include "Po.h"
#include "missile.h"
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

	if (GetAsyncKeyState(VK_RIGHT) & 0x8001)
		po->_theta += 0.03f;

	if (GetAsyncKeyState(VK_SPACE) & 0x8001) {
		// po �ؿ� missle �߰��ϱ�
		po->addChildNode(new missile);

		missile* missile1 = new missile;
		missile1->actorInfo = ActorInfo(18, 8, 0, 1);
	}

	Actor::update();
}

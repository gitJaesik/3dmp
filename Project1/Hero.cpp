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
	Actor::update();
}

#pragma once
#include "Actor.h"

// ������ singleton���� �ؾ��ϴ��� ����ϱ�
class Hero : public Actor
{
public:
	Hero();
	~Hero();

	virtual void update() override;

};


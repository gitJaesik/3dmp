#pragma once
#include "Actor.h"

// ������ singleton���� �ؾ��ϴ��� ����ϱ�
class Hero : public Actor
{
protected:
	Hero();
public:
	Hero(const std::string& actorName);
	~Hero();

	virtual void update() override;

};


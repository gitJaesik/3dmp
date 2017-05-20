#pragma once
#include "Actor.h"

// 영웅을 singleton으로 해야하는지 고려하기
class Hero : public Actor
{
protected:
	Hero();
public:
	Hero(const std::string& actorName);
	~Hero();

	virtual void update() override;

};


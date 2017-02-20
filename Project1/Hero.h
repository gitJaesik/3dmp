#pragma once
#include "Actor.h"

// 영웅을 singleton으로 해야하는지 고려하기
class Hero : public Actor
{
public:
	Hero();
	~Hero();

	virtual void update() override;

public :
	Point _d;

};


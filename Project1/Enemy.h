#pragma once
#include "Actor.h"
class Enemy : public Actor
{
public:
	Enemy();
	~Enemy();

	virtual void update() override;

};


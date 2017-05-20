#pragma once
#include "Actor.h"
class Enemy : public Actor
{
protected:
	Enemy();

public:
	Enemy(const std::string& actorName);
	~Enemy();

	virtual void update() override;

};


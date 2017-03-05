#pragma once
#include "Actor.h"
class missile : public Actor
{
public:
	missile();
	~missile();

	virtual void update() override;
};


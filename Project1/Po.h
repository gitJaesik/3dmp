#pragma once
#include "Actor.h"

class Po : public Actor
{
public:
	Po();
	~Po();

	// theta ¼±¾ð 
	float _theta;
	float _gun_barrel_length;

	virtual void update() override;
};


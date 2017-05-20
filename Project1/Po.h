#pragma once
#include "Actor.h"

class Po : public Actor
{
protected:
	Po();

public:
	Po(const std::string& actorName);
	~Po();

	// theta ���� 
	float _theta;
	float _gun_barrel_length;

	virtual void update() override;
};


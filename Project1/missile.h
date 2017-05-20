#pragma once
#include "Actor.h"
class missile : public Actor
{
protected:
	missile();

public:
	missile(const std::string& actorName);
	~missile();

	virtual void update() override;
};


#pragma once
#include "ActorInfo.h"
#include <vector>

class Actor
{
public:
	Actor();
	~Actor();
	ActorInfo actorInfo;

	virtual void update();

	std::vector<Actor*> _ChildNode;

	Actor* _ParentNode;
};


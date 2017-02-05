#pragma once
#include "ActorInfo.h"
class Actor
{
public:
	Actor(int x, int y, int type, int life);
	Actor();
	~Actor();
	ActorInfo actorInfo;
};


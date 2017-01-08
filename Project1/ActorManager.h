#pragma once
#include "ActorInfo.h"
#include "Actor.h"
#include "Enemy.h"
#include "Hero.h"
#include "missile.h"
#include <vector>

class ActorManager
{
public:
	ActorManager();
	~ActorManager();

	std::vector<Actor*> actors;

	void initialize();
};


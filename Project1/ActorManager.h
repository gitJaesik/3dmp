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
	
	~ActorManager();

	std::vector<Actor*> actors;

	void initialize();
	void AddActor(Actor* pActor);
	void RemoveActor();

	static ActorManager* GetInstance();

private:
	ActorManager();
};


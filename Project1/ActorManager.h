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

	void initialize();
	void AddActor(Actor* pActor);
	void UpdateActor(Actor* pActor);
	void RemoveActor();

	// �����ڸ� �ѱ����� ����� ���δ�.
	const std::vector<Actor*>& GetActors();

	void update();

	static ActorManager* GetInstance();

private:
	ActorManager();

	std::vector<Actor*> actors;
};


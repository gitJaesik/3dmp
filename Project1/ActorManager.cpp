#include "ActorManager.h"

ActorManager* ActorManager::GetInstance()
{
	static ActorManager actorManager;
	return &actorManager;
}



ActorManager::ActorManager()
{
}


ActorManager::~ActorManager()
{
}

void ActorManager::initialize()
{
	// buffer size = 640 = 16*40

	
}

void ActorManager::AddActor(Actor* pActor)
{
	actors.push_back(pActor);
}

void ActorManager::RemoveActor()
{
	for (unsigned int i = 0; i < actors.size(); ++i) {
		delete actors[i];
		actors[i] = nullptr;
	}
	actors.clear();
}


void ActorManager::update()
{
	// 모든 actor의 값을 업데이트한다.
	for (auto actor : actors)
	{
		actor->update();
	}

	// 업데이트 된 값을 Renderer에서 사용할 것이다.
}

void ActorManager::UpdateActor(Actor* pActor)
{
	
}

std::vector<Actor*> ActorManager::GetActors()
{
	return actors;
}
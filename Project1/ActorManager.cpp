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


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
		// childe node ����
		for (auto& child_node : actors[i]->getChildNodes())
		{
			delete child_node;
		}

		delete actors[i];
		actors[i] = nullptr;
	}
	actors.clear();
}


void ActorManager::update()
{
	// ��� actor�� ���� ������Ʈ�Ѵ�.
	for (auto actor : actors)
	{
		actor->update();
		if (actor->getChildNodes().size() != 0) {
			for (auto child_actor : actor->getChildNodes()) {
				child_actor->update();
			}
		}
	}

	// ������Ʈ �� ���� Renderer���� ����� ���̴�.
}

void ActorManager::UpdateActor(Actor* pActor)
{
	
}

const std::vector<Actor*>& ActorManager::GetActors()
{
	return actors;
}
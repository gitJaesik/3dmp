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

void ActorManager::RemoveAllActor()
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

void ActorManager::RemoveActor(Actor* pActor)
{
	auto next = actors.begin();
	auto end = actors.end();
	while(next != end)
	{
		if (*next == pActor) {
			delete *next;
			next = actors.erase(next);
			end = actors.end();
			break;
		} else {
			++next;
		}
		
	}
}

Actor* ActorManager::FindActorByActorName(const std::string& name)
{
	auto next = actors.begin();
	auto end = actors.end();
	while (next != end) {
		if ((*next)->isEqualActorName(name)) {
			return *next;
		}
		++next;
	}

	return nullptr;
}
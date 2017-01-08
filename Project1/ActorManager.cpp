#include "ActorManager.h"



ActorManager::ActorManager()
{
}


ActorManager::~ActorManager()
{
}

void ActorManager::initialize()
{
	// Hero
	Hero* hero = new Hero;
	hero->actorInfo.pt.x = 5;
	hero->actorInfo.pt.y = 3;

	hero->actorInfo.type = 1;

	hero->actorInfo.life = 1;

	actors.push_back(hero);


	// Enemy
	Enemy* enemy = new Enemy;
	enemy->actorInfo.pt.x = 10;
	enemy->actorInfo.pt.y = 4;

	enemy->actorInfo.type = 2;

	enemy->actorInfo.life = 1;

	actors.push_back(enemy);

	Enemy* enemy2 = new Enemy;
	enemy2->actorInfo.pt.x = 10;
	enemy2->actorInfo.pt.y = 5;

	enemy2->actorInfo.type = 2;

	enemy2->actorInfo.life = 1;

	actors.push_back(enemy2);
}

#include <iostream>
using namespace std;

#include "ActorInfo.h"
#include "Enemy.h"
#include "Hero.h"
#include "Renderer.h"
#include "ActorManager.h"
#include <windows.h>

int main() 
{
	//create
	//Renderer render;

	//initialize
	//render.initialize();
	Renderer::GetInstance()->initialize();

	Hero* hero = new Hero;
	hero->actorInfo.initialize(7, 15, 1, 1);
	ActorManager::GetInstance()->AddActor(hero);

	Enemy* enemy = new Enemy;
	enemy->actorInfo.initialize(3, 3, 2, 1);
	ActorManager::GetInstance()->AddActor(enemy);

	Enemy* enemy2 = new Enemy;
	enemy2->actorInfo.initialize(5, 4, 2, 1);
	ActorManager::GetInstance()->AddActor(enemy2);

	Enemy* enemy3= new Enemy;
	enemy2->actorInfo.initialize(10, 7, 2, 1);
	ActorManager::GetInstance()->AddActor(enemy3);

	missile* missile1 = new missile;
	missile1->actorInfo.initialize(9, 10, 0, 1);
	ActorManager::GetInstance()->AddActor(missile1);



	printf("\0");
	while ( !(GetAsyncKeyState(VK_ESCAPE) & 0x8000) ) 
	{	//update , render
	
		Renderer::GetInstance()->update();
		Renderer::GetInstance()->reder();
	}

	ActorManager::GetInstance()->RemoveActor();

	return 0;
}
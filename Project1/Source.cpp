#include <iostream>

#include "ActorInfo.h"
#include "Enemy.h"
#include "Hero.h"
#include "Po.h"
#include "Renderer.h"
#include "ActorManager.h"
#include <windows.h>

using namespace std;


void createObjects() {
	Hero* hero = new Hero;
	hero->actorInfo = ActorInfo(13, 11, 1, 1);
	ActorManager::GetInstance()->AddActor(hero);

	// Po의 시작점과 끝점을 입력
	Po* po = new Po;
	po->actorInfo = ActorInfo(18, 8, 3, 1);
	hero->addChildNode(po); 
	po->setParentNode(hero);

	Enemy* enemy = new Enemy;
	enemy->actorInfo = ActorInfo(6, 3, 2, 1);
	ActorManager::GetInstance()->AddActor(enemy);

	Enemy* enemy2 = new Enemy;
	enemy2->actorInfo = ActorInfo(10, 4, 2, 1);
	ActorManager::GetInstance()->AddActor(enemy2);

	Enemy* enemy3 = new Enemy;
	enemy3->actorInfo = ActorInfo(20, 7, 2, 1);
	ActorManager::GetInstance()->AddActor(enemy3);

	missile* missile1 = new missile;
	missile1->actorInfo = ActorInfo(18, 8, 0, 1);
	ActorManager::GetInstance()->AddActor(missile1);
}


int main() 
{
	//create
	//Renderer render;

	//initialize
	//render.initialize();
	Renderer::GetInstance()->initialize();

	createObjects();

	
	printf("\0");
	while ( true ) 
	{	//update , render
		//hero->actorInfo._pt.x++;
		Renderer::GetInstance()->windowClear();

		// 모든 actor들을 update하도록 변경
		ActorManager::GetInstance()->update();
		
		Renderer::GetInstance()->update();

		Renderer::GetInstance()->reder();

		// break하는 부분

		if ((GetAsyncKeyState(VK_ESCAPE) & 0x8000))
			break;
	}

	ActorManager::GetInstance()->RemoveActor();

	return 0;
}
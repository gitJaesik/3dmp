#include <iostream>
using namespace std;

#include "ActorInfo.h"
#include "Enemy.h"
#include "Hero.h"
#include "Renderer.h"
#include "ActorManager.h"

int main() {
	//create
	ActorManager actorManager;

	Renderer render;								

	//initialize
	render.initialize();
	actorManager.initialize();


	while (true) {		//update , render
		for (auto actor : actorManager.actors) {
			render.update(actor);
		}
		render.reder();			
	}
	return 0;
}
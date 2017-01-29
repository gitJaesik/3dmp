#include "Renderer.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h> // needs for getch() and kbhit()
#include <iostream>
#include "ActorManager.h"


Renderer* Renderer::GetInstance()
{
	static Renderer renderer;
	return &renderer;
}

Renderer::Renderer()
{
	objectShape[0] = '*';
	objectShape[1] = 'o';
	objectShape[2] = '#';
}

Renderer::~Renderer()
{
}

void Renderer::initialize()
{
	buffer.resize(640);
	
	for (size_t i = 0; i < buffer.size(); ++i) {
		buffer[i] = ' ';
	}
}
void Renderer::gotoxy(int x, int y)
{
	COORD XY = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XY);
}

void Renderer::update()
{

	for (unsigned int i = 0; i < ActorManager::GetInstance()->actors.size(); ++i) {
		Actor* actor = ActorManager::GetInstance()->actors[i];
		if (actor->actorInfo._life > 0) {
			buffer[actor->actorInfo._pt.x + actor->actorInfo._pt.y * 40] = objectShape[actor->actorInfo._type];
		}
	}

}

void Renderer::reder()
{
	gotoxy(0, 0);

	for (size_t  i = 0; i < buffer.size(); ++i) {
		if (i != 0 && i % 40 == 0) {
			printf("\n");
		}
		printf("%c", buffer[i]);
	}
}



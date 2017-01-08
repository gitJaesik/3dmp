#include "Renderer.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h> // needs for getch() and kbhit()



Renderer::Renderer()
{
	draw[0] = '*';
	draw[1] = '^';
	draw[2] = '#';
}


Renderer::~Renderer()
{
}

void Renderer::initialize()
{
	for (int i = 0; i < limit; ++i) {
		view[i] = ' ';
	}
}

void Renderer::reder()
{
	gotoxy(0, 0);

	
	
	for (int i = 0; i < limit; i++) {
		if (i != 0 && i % 40 == 0) {
			printf("\n");
		}
		printf("%c", view[i]);
	}
	
}

void Renderer::gotoxy(int x, int y)
{
	COORD XY = { x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XY);
}

void Renderer::update(Actor* actor)
{
	if (actor->actorInfo.life > 0) {
		view[actor->actorInfo.pt.x + actor->actorInfo.pt.y * 40] = draw[actor->actorInfo.type];
	}
}


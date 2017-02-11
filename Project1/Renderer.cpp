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

	Point H;
	Point D;

	//수학식 좌표 포 위치를 배치
	H.x = 0;
	H.y = 0;

	D.x = -8;
	D.y = 5;



	float Distance=  sqrtf((D.y - H.y) * (D.y - H.y) + (D.x- H.x) * (D.x - H.x));
	float t=0.0f;

	Point G;
	G.x = D.x - H.x;
	G.y = D.y - H.y;

	for (int increment_t = 0; increment_t  < (int)Distance; ++increment_t) {
		t = increment_t / float(Distance);
		//t = 0.0 ~ 1.0
		//t 에 따른 직선을 구한다

		int pox = G.x*t;
		int poy = G.y*t;

		int po = 15 + pox + (poy+7) * 40;
		buffer[po] = 'x';		//화면 좌표 기준
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



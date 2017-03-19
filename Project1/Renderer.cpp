#include "Renderer.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h> // needs for getch() and kbhit()
#include <iostream>
#include <typeinfo>
#include "ActorManager.h"
#include <string>

Renderer* Renderer::GetInstance()
{
	static Renderer renderer;
	return &renderer;
}

Renderer::Renderer()
{
	// missile
	objectShape[0] = '*';
	// hero
	objectShape[1] = 'o';
	// enemy
	objectShape[2] = '#';
	// po
	objectShape[3] = 'x';
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
	
	//hero 의 포 구하기, actormanager를 world 개념으로 사용하여 world중에서 hero를 구하는 방식으로 구하기

	for (auto e : ActorManager::GetInstance()->GetActors())
	{
		// const std::type_info& t1 = typeid(*e);
		// const std::type_info& t2 = typeid(Hero);

		if (typeid(*e) == typeid(Hero))
		{
			// 부모노드 위치(hero 위치)와 자식노드(po의 위치) 사이의 거리를 구한다.
			float Distance = sqrtf(
				(e->getChildNodes()[0]->actorInfo._pt.y - e->actorInfo._pt.y) * (e->getChildNodes()[0]->actorInfo._pt.y - e->actorInfo._pt.y)
				+ (e->getChildNodes()[0]->actorInfo._pt.x - e->actorInfo._pt.x) * (e->getChildNodes()[0]->actorInfo._pt.x - e->actorInfo._pt.x)
			);

			Point G;
			G.x = e->getChildNodes()[0]->actorInfo._pt.x - e->actorInfo._pt.x;
			G.y = e->getChildNodes()[0]->actorInfo._pt.y - e->actorInfo._pt.y;

			// t는 0~1까지의 범위를 가진다.
			float t = 0.0f;

			for (int increment_t = 0; increment_t < (int)Distance; ++increment_t) {
				t = increment_t / float(Distance);
				//t = 0.0 ~ 1.0
				//t 에 따른 직선을 구한다

				int pox = G.x*t;
				int poy = G.y*t;

				int po = pox + e->actorInfo._pt.x + (poy + e->actorInfo._pt.y) * width;

				// buffer size 초과 하지 않도록 설정
				if (po < buffer.size())
					buffer[po] = objectShape[e->getChildNodes()[0]->actorInfo._type];		//화면 좌표 기준
			}


			// Hero 주의에 원 그리기
			float radious = 5.0f;
			float toRad = 3.141592f / 180.0f;
			// degree to radian,  radian to degree
			for (float angle = 0; angle <= 360; angle+=15.0f)
			{

				float xx = e->actorInfo._pt.x + int(cosf(angle*toRad) * radious);
				float yy = e->actorInfo._pt.y + int(sinf(angle*toRad) * radious);
		
				int circle = xx + yy *width;

				//OutputDebugString((std::to_string(yy *width) + std::string(", ") + std::to_string(int(yy) *width) + std::string("\n")).c_str());

				if (circle < buffer.size())
					buffer[circle] = objectShape[1];
			}

		}
	}
}

void Renderer::reder()
{
	gotoxy(0, 0);

	for (unsigned int i = 0; i < ActorManager::GetInstance()->GetActors().size(); ++i) {
		Actor* actor = ActorManager::GetInstance()->GetActors()[i];

		int acotrPos = actor->actorInfo._pt.x + actor->actorInfo._pt.y * width;
		if (acotrPos < 640 && actor->actorInfo._life > 0) {
			buffer[acotrPos] = objectShape[actor->actorInfo._type];
		} else {
			actor->actorInfo._life = 0;
			ActorManager::GetInstance()->RemoveActor(actor);
		}
	}

	for (size_t  i = 0; i < buffer.size(); ++i) {
		if (i != 0 && i % width == 0) {
			printf("\n");
		}
		printf("%c ", buffer[i]);
	}
}


void Renderer::windowClear()
{
	// &연산자를 붙이지 않으면 복사가 되지 않는다.
	for (auto& elem : buffer)
	{
		elem = ' ';
	} 
}
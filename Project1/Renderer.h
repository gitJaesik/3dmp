#pragma once
#include "Actor.h"

class Renderer
{
public:
	Renderer();
	~Renderer();


	void initialize();

	const static int limit = 640;
	char view[limit];
	char draw[5]; // type 별로 그림을 그릴 때 사용할 배열
	void reder();
	void gotoxy(int x, int y);
	void update(Actor* actorInfo);
};


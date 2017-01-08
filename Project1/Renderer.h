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
	char draw[5]; // type ���� �׸��� �׸� �� ����� �迭
	void reder();
	void gotoxy(int x, int y);
	void update(Actor* actorInfo);
};


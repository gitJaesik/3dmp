#pragma once
#include "Actor.h"
#include <vector>

class Renderer
{
public:
	
	~Renderer();

	void initialize();
	void gotoxy(int x, int y);

	void update();
	void reder();

	static Renderer* GetInstance();

private: 
	Renderer();

private :

	std::vector<char> buffer;

	char objectShape[5]; // type ���� �׸��� �׸� �� ����� �迭
	
};


#pragma once
#include "Actor.h"
#include <vector>

class Renderer
{
public:
	
	~Renderer();

	void initialize();
	void windowClear();
	void gotoxy(int x, int y);

	void update();
	void reder();

	static Renderer* GetInstance();

private: 
	Renderer();

private :

	std::vector<char> buffer;

	char objectShape[5]; // type 별로 그림을 그릴 때 사용할 배열
	const int width = 30;
};


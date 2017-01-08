#pragma once

struct Point {
	int x;
	int y;
};

class ActorInfo
{
public:
	ActorInfo();
	~ActorInfo();

	Point pt;
	int type;
	int life;

};


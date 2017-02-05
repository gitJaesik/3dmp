#pragma once

struct Point {
	int x;
	int y;
};

class ActorInfo
{
public:
	ActorInfo(int x, int y, int type, int life);
	ActorInfo();
	~ActorInfo();

	Point _pt;
	int _type;
	int _life;

	void initialize(int x, int y, int type, int life);

};


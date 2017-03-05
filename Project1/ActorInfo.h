#pragma once

struct Point {
	float x;
	float y;
};

struct ActorInfo
{
	ActorInfo(float x, float y, int type, int life);
	ActorInfo();
	~ActorInfo();

	Point _pt;
	int _type;
	int _life;

	void initialize(float x, float y, int type, int life);

};


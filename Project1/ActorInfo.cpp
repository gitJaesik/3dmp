#include "ActorInfo.h"

ActorInfo::ActorInfo(float x, float y, int type, int life)
{
	initialize(x, y, type, life);
}

ActorInfo::ActorInfo()
{

}

ActorInfo::~ActorInfo()
{
}

void ActorInfo::initialize(float x, float y, int type, int life)
{
	_pt.x = x;
	_pt.y = y;

	_type = type;
	_life = life;
}

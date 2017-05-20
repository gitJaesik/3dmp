#include "missile.h"



missile::missile()
{
}


missile::missile(const std::string& actorName) :Actor(actorName)
{

}

missile::~missile()
{
}

void missile::update()
{
	Actor::update();

}
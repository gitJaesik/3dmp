#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(const std::string& actorName) : Actor(actorName)
{

}

Enemy::~Enemy()
{
}

void Enemy::update()
{
	Actor::update();

	// 적군 움직이게 하기
	actorInfo._pt.y += 1.0;
}
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

	// ���� �����̰� �ϱ�
	actorInfo._pt.y += 1.0;
}
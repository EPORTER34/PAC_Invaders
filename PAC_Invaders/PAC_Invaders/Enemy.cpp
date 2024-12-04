#include "Enemy.hpp"

Enemy::Enemy()
{
	health = 0;
}

int Enemy::getHealth()
{
	return health;
}

void Enemy::setHealth(int newHealth)
{
	health = newHealth;
}


void Enemy::fireFootballs(Projectile& football)
{
	if (football.getGlobalBounds().top  <= 540)
	{
		football.move(0, 0.125);
	}
}

#include "Enemy.hpp"

Enemy::Enemy(Vector2f& newVelocity, int newHealth) : HitBox(newVelocity)
{
	health = newHealth;
}

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

void Enemy::checkForWalls()
{
	if (getPosition().y >= 540)
	{
		setPosition(getPosition().x, -100);
	}
}


void Enemy::fireFootballs(Projectile& football)
{
	if (football.getGlobalBounds().top  <= 540)
	{
		football.move(0, 0.125);
	}
}

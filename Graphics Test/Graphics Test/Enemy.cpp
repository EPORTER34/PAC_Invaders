#include "Enemy.hpp"

Enemy::Enemy(Vector2f& newVelocity, int newHealth) : HitBox(newVelocity)
{
    setScale({ .06f,.06f });
    health = newHealth;
	cycle = 0;
}

int Enemy::getHealth()
{
    return health;
}

Vector2f Enemy::getDefaultPosition()
{
    return defaultPosition;
}

void Enemy::setHealth(int newHealth)
{
    health = newHealth;
}

void Enemy::setDefaultPosition(const Vector2f& newDefault)
{
    defaultPosition = newDefault;
}


void Enemy::checkForWalls()
{
	if (getPosition().y >= 1080)
	{
		setPosition(defaultPosition.x, -100);
		cycle = 1;
	}
	if (getPosition().x <= 0 || getPosition().x >= 1920)
	{
		velocity.x = -velocity.x;
	}
}


int Enemy::getCycle()
{
	return cycle;
}

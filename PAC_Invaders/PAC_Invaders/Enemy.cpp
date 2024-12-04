#include "Enemy.hpp"


void Enemy::fireFootballs(Projectile& football)
{
	if (football.getGlobalBounds().top  <= 540)
	{
		football.move(0, 0.125);
	}
}

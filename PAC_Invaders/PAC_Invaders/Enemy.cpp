#include "Enemy.hpp"

//fires a football from the enemy's current position
void Enemy::fireFootballs(Projectile& football)
{
	if (football.getGlobalBounds().top  <= 540)
	{
		football.move(0, 0.2);
	}
}

#pragma once
#include "hitBox.hpp"
#include "Projectile.hpp"

class Enemy : public HitBox
{
public:
	Enemy(Vector2f& newVelocity, int newHealth);
	Enemy();
	int getHealth();
	void setHealth(int newHealth);
	void checkForWalls();
	void fireFootballs(Projectile& football);
protected:
	int health;
};
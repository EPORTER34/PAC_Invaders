#pragma once
#include "hitBox.hpp"
#include "Projectile.hpp"

class Enemy : public Sprite
{
public:
	Enemy();
	int getHealth();
	void setHealth(int newHealth);
	void checkForWalls();
	void fireFootballs(Projectile& football);
protected:
	int health;
};
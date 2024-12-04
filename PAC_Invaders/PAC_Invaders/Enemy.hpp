#pragma once
#include "Projectile.hpp"

class Enemy : public Sprite
{
public:
	Enemy();
	int getHealth();
	void setHealth(int newHealth);
	void fireFootballs(Projectile& football);
protected:
	int health;
};
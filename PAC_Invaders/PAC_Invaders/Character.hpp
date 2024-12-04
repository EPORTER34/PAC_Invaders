#pragma once

#include "header.hpp"
#include "Projectile.hpp"


class Character : public Sprite
{
public:
	Character(int newHealth = 0) : Sprite()
	{
		
		health = newHealth;
	}

	void setHealth(int newHealth);
	int getHealth();

	virtual void fireFootballs(Projectile& football) = 0;
private:

	int health;
};
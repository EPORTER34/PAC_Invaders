#pragma once
#include "Projectile.hpp"

//abstract character class to avoid code reuse with enemy and player classes
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
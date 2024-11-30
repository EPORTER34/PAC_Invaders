#pragma once
#include "hitBox.hpp"
#include "Projectile.hpp"

class Enemy : public HitBox
{
public:
	Enemy(Vector2f& newVelocity, int newHealth);
	Enemy();
	int getHealth();
	Vector2f getDefaultPosition();
	void setHealth(int newHealth);
	void setDefaultPosition(const Vector2f& newDefault);
	void checkForWalls();
	int getCycle();
	void fireFootballs(Projectile& football);
protected:
	int health;
	Vector2f defaultPosition;
	int cycle;
};
#pragma once
#include "header.hpp"
#include "Projectile.hpp"

class Player : public Sprite
{
public:
	Player(float x = 0.0, float y = 0.0, int newHealth = 3, const string& spriteFile = "WSU_Logo.png");

	void update();
	void draw(RenderWindow& window) const;
	void playerBounds(RenderWindow& window);

	void setHealth(int newHealth);
	int getHealth();

	void fireFootballs(Projectile& football);

private:
	Texture texture; //using texture class
	int health;
};
#pragma once
#include "header.hpp"

class Player : public Sprite
{
public:
	Player(float x = 0.0, float y = 0.0, const string& spriteFile = "WSU_Logo.png");

	void update();
	void draw(RenderWindow& window) const;
	void playerBounds(RenderWindow& window);

	

private:
	Texture texture; //using texture class
};
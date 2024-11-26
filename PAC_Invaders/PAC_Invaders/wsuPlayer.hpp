#pragma once
#include "header.hpp"

class Player 
{
public:
	Player(float x, float y, const string& spriteFile);

	void update();
	void draw(RenderWindow& window) const;
	void playerBounds(RenderWindow& window);
private:
	Sprite player;
	Texture texture; //using texture class
};
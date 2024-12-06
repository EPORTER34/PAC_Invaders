#pragma once
#include "header.hpp"

//projectile class for rendering and collision detection of the footballs
class Projectile : public Sprite
{
public:
	Projectile() : Sprite()
	{
		if (!texture.loadFromFile("pixel_football.png"))
		{
			cout << "error finding file" << endl;
		}
		else
		{
			setTexture(texture);
		}

		this->setScale(0.075, 0.075);
		fired = false;
	}

	void setFired(bool isFired);
	bool getFired();
private:
	Texture texture;
	bool fired;
};
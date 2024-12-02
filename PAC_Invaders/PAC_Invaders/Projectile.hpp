#pragma once
#include "header.hpp"

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
	}
private:
	Texture texture;
};
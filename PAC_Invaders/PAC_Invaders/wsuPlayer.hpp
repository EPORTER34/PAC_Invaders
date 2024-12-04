#pragma once
#include "header.hpp"
#include "Projectile.hpp"
#include "character.hpp"

class Player : public Character
{
public:
	Player(float x = 0.0, float y = 0.0, string spriteFIle = "") : Character(3)
	{
		if (!texture.loadFromFile("WSU_Logo.png"))
		{
			cout << "error finding file" << endl;
		}
		else
		{
			setTexture(texture);
		}

		this->setPosition(x, y);
	}

	void update();
	void draw(RenderWindow& window) const;
	void playerBounds(RenderWindow& window);

	void fireFootballs(Projectile& football);
private:
	Texture texture;
	string spriteFile;
};
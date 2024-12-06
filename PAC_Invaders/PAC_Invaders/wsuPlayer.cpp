#include "wsuPlayer.hpp"


//left/right controls
void Player::update()
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Left))
	{
		this->move(-0.2f, 0.0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Right))
	{
		this->move(0.2f, 0.0f);
	}
}


void Player::playerBounds(RenderWindow& window)
{
	FloatRect windowBounds(0.f, 0.f, window.getSize().x, window.getSize().y);//used to get the  bounds of the window for borders
	Vector2f position = this->getPosition();
	FloatRect playerBounds = this->getGlobalBounds();

	//used to set bounds for the player, sprite cannot leave the screen
	position.x = max(position.x, windowBounds.left);
	position.x = min(position.x, windowBounds.left + windowBounds.width - playerBounds.width);
	position.y = max(position.y, windowBounds.top);
	position.y = min(position.y, windowBounds.top + windowBounds.height - playerBounds.height);

	this->setPosition(position);//updating where the position is

}


//up arror to fire projectile
void Player::fireFootballs(Projectile& football)
{
	if (football.getGlobalBounds().top + football.getGlobalBounds().height >= 0)
	{
		football.move(0, -0.2);
	}
}



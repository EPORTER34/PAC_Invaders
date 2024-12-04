#include "wsuPlayer.hpp"


void Player::update()
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Left))
	{
		this->move(-0.2f, 0.0); //feel free to change speed if its too fast or slow
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Right))
	{
		this->move(0.2f, 0.0f);
	}
}

void Player::draw(RenderWindow& window) const
{
	window.draw(*this);//used in main
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



void Player::fireFootballs(Projectile& football)
{
	if (football.getGlobalBounds().top + football.getGlobalBounds().height >= 0)
	{
		football.move(0, -0.125);
	}
}



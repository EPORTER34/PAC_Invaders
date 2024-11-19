#include "hitBox.hpp"


HitBox::HitBox(Vector2f Velocity)
{	
	velocity = Velocity;
}


HitBox::~HitBox()
{
	
}


Vector2f& HitBox::getVelocity()
{
	return velocity;
}


void HitBox::setVelocity(float x, float y)
{
	velocity.x = x;
	velocity.y = y;
}
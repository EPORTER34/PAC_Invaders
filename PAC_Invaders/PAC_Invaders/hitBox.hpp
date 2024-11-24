#pragma once
#include "header.hpp"

class HitBox : public Sprite
{
public:
	HitBox(Vector2f Velcoity);
	HitBox();
	~HitBox();
	Vector2f& getVelocity();
	void setVelocity(float x, float y);
	virtual void checkForWalls() = 0;
protected:
	Vector2f velocity;
};
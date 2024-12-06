#pragma once
#include "Projectile.hpp"
#include "header.hpp"
#include "Character.hpp"

//class for all of the enemies
class Enemy : public Character
{
public:
	Enemy() : Character() 
	{
	}
	void fireFootballs(Projectile& football);
};
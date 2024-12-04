#pragma once
#include "Projectile.hpp"
#include "header.hpp"
#include "Character.hpp"

class Enemy : public Character
{
public:
	Enemy() : Character() 
	{
	}
	void fireFootballs(Projectile& football);
};
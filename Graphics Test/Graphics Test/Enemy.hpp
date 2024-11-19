#include "hitBox.hpp"



class Enemy : public HitBox
{
public:
	Enemy(Vector2f& newVelocity, int newHealth);
	int getHealth();
	Vector2f getDefaultPosition();
	void setHealth(int newHealth);
	void setDefaultPosition(const Vector2f& newDefault);
	void checkForWalls();
	int getCycle();
protected:
	int health;
	Vector2f defaultPosition;
	int cycle;
};
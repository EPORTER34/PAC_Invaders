#pragma once
#include "Enemy.hpp"
#include "wsuPlayer.hpp"
#include "Projectile.hpp"




class App
{
public:
	App();
	void run();
private:
	Texture Logos[10];
	Enemy enemies[40];
	RenderWindow window;
	Player player;
	Sprite background;

	void moveRow(Clock& movementClock);
	void drawPlayer(Player& player);
	void movePlayer(Player& player);
	void drawEnemies();
	void enemyFire(vector<Projectile>& footballs, Player& player, int& inc, bool& projFired, Clock& clock, int& dropTime);
	void displayLives(Player& player);
};
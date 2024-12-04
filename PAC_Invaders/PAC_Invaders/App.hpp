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
	Enemy enemies[30];
	RenderWindow window;
	Sprite background;
	Font menuFont;
	Text gameOverText;
	Text title;
	Text menuOptions[3];
	Text enterToContinue;
	Text leftRight;
	Text fire;
	Text goal;
	Text lifeTable;
	Text numbers[3];
	Sprite tutorialImages[10];


	void moveRow(Clock& movementClock);
	void drawPlayer(Player& player);
	void movePlayer(Player& player);
	void drawEnemies();
	void enemyFire(vector<Projectile>& footballs, Player& player, int& inc, bool& projFired, Clock& clock, int& dropTime);
	void playerFire(Player& player, vector<Projectile>& playerBalls, int& playerInc, Event event, bool& keyPressedOnce);
	void displayLives(Player& player);
};
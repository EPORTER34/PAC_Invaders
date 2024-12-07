#pragma once
#include "Enemy.hpp"
#include "wsuPlayer.hpp"


//app container class for all of the elements used
class App
{
public:
	App();
	void run();
private:
	Texture Logos[10]; //enemies dont make copies of the texture, this keeps it in scope for rendering
	Enemy enemies[30]; //arrary of all the enemies on the level
	RenderWindow window;
	Sprite background;

	//text stuff is a mess, maybe cleanup?
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

	//scoring variables
	Text Score;
	int score;
	
	void moveRow(Clock& movementClock, int round);
	void drawPlayer(Player& player);
	void movePlayer(Player& player);
	void drawEnemies();
	void enemyFire(vector<Projectile>& footballs, vector<Projectile>& playerBalls, Player& player, int& inc, bool& projFired, Clock& clock, int& dropTime);
	void playerFire(Player& player, vector<Projectile>& playerBalls, int& playerInc, Event event, bool& keyPressedOnce, Clock& clock);
	void displayLives(Player& player);
	void drawTutorial();
	void resetEnemies();
	bool levelCleared();
};
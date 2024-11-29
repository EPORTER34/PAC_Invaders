#pragma once
#include "Enemy.hpp"
#include "wsuPlayer.hpp"




class App
{
public:
	App();
	void run();
private:
	Texture Logos[9];
	Enemy enemies[40];
	RenderWindow window;
	Player player;

	void drawPlayer(Player& player);
	void movePlayer(Player& player);
	void drawEnemies();
	void moveEnemies();
	void checkForWallsEnemies();
};
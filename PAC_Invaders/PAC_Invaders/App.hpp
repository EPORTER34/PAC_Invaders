#pragma once
#include "Enemy.hpp"




class App
{
public:
	App();
	void run();
private:
	Texture Logos[9];
	Enemy enemies[40];
	RenderWindow window;

	void drawEnemies();
	void moveEnemies();
	void checkForWallsEnemies();
};
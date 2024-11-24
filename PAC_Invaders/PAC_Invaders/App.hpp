#pragma once
#include "Enemy.hpp"




class App
{
public:
	App();
	void run();
private:
	Texture Logos[9];
	Enemy enemies[50];
	RenderWindow window;

	void draw();
	void move();
	void checkForWalls();
};
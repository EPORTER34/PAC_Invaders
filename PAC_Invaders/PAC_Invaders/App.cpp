#include "App.hpp"

App::App() : window(VideoMode(960, 540), "Pac_Invaders")
{

    //setting logo textures
	Logos[0].loadFromFile("WSU_Logo.png");
	Logos[1].loadFromFile("UW_Logo.png");
	Logos[2].loadFromFile("Oregon_Logo.png");
	Logos[3].loadFromFile("Cal_Logo.png");
	Logos[4].loadFromFile("Stanford_Logo.png");
	Logos[5].loadFromFile("UCLA_Logo.png");
	Logos[6].loadFromFile("USC_Logo.png");
	Logos[7].loadFromFile("Arizona_Logo.png");
	Logos[8].loadFromFile("ASU_Logo.png");


    //loading and placing each enemy
    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 10; column++)
        {
            switch (row)
            {
            case 0:
                if (column < 3 || column > 6)
                {
                    enemies[column].setTexture(Logos[6]);
                    enemies[column].setHealth(1);
                }
                else
                {
                    enemies[column].setTexture(Logos[2]);
                    enemies[column].setHealth(3);
                }
                break;
            case 1:
                if (column < 2 || column > 7)
                {
                    enemies[column + 10].setTexture(Logos[7]);
                }
                else if (column < 4 || column > 5)
                {
                    enemies[column + 10].setTexture(Logos[8]);
                }
                else
                {
                    enemies[column + 10].setTexture(Logos[5]);
                    enemies[column + 10].setScale(1.1, 1.1);
                }
                enemies[column + 10].setHealth(2);
                break;
            case 2:
                if (column < 2 || column > 7)
                {
                    enemies[column + 20].setTexture(Logos[4]);
                    enemies[column + 20].setScale(1.5, 1.5);
                }
                else if (column < 4 || column > 5)
                {
                    enemies[column + 20].setTexture(Logos[3]);
                }
                else
                {
                    enemies[column + 20].setTexture(Logos[1]);
                }
                enemies[column + 20].setHealth(1);
                break;
            }
            enemies[column + 10 * row].setPosition(100 * column + 5, 25 + 55 * row);
        }
    }



}

void App::run()
{
    Player player(480, window.getSize().y - 100, "WSU_Logo.png");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();


        drawEnemies();
        player.draw(window);
        player.update();
        moveEnemies();
        checkForWallsEnemies();

        window.display();
    }
}

void App::drawEnemies()
{
    for (int i = 0; i < 40; i++)
    {
        window.draw(enemies[i]);
    }
}

void App::moveEnemies()
{
    for (int i = 0; i < 40; i++)
    {
        enemies[i].move(enemies[i].getVelocity());
    }
}

void App::checkForWallsEnemies()
{
    for (int i = 0; i < 40; i++)
    {
        enemies[i].checkForWalls();
    }
}

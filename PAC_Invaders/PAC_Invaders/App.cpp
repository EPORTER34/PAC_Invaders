#include "App.hpp"

App::App() : window(VideoMode(1920/2, 1080/2), "Pac_Invaders")
{
	Logos[0].loadFromFile("WSU_Logo.png");
	Logos[1].loadFromFile("UW_Logo.png");
	Logos[2].loadFromFile("Oregon_Logo.png");
	Logos[3].loadFromFile("Cal_Logo.png");
	Logos[4].loadFromFile("Stanford_Logo.png");
	Logos[5].loadFromFile("UCLA_Logo.png");
	Logos[6].loadFromFile("USC_Logo.png");
	Logos[7].loadFromFile("Arizona_Logo.png");
	Logos[8].loadFromFile("ASU_Logo.png");

    for (int i = 0; i < 10; i++)
    {
        if (i < 2 || i > 7)
        {
            enemies[i].setTexture(Logos[6]);
            enemies[i].setHealth(1);
        }
        else
        {
            enemies[i].setTexture(Logos[2]); 
            enemies[i].setHealth(3);
        }
        enemies[i].setPosition(100*i + 5, 25);
        
    }
    for (int i = 10; i < 20; i++)
    {
        if (i < 12 || i > 18)
        {
            enemies[i].setTexture(Logos[7]);
        }
        else if (i < 14 || i > 15)
        {
            enemies[i].setTexture(Logos[8]);
        }
        else
        {
            enemies[i].setTexture(Logos[5]);
        }
        enemies[i].setPosition(100 * (i - 10) + 5, 80);
        enemies[i].setHealth(2);
    }
    for (int i = 20; i < 30; i++)
    {
        if (i < 22 || i > 28)
        {
            enemies[i].setTexture(Logos[4]);
            enemies[i].setScale(1.5, 1.5);
        }
        else if ( i < 24 || i > 25)
        {
            enemies[i].setTexture(Logos[3]);
        }
        else
        {
            enemies[i].setTexture(Logos[1]);
        }
        enemies[i].setPosition(100 * (i - 20) + 5, 135);
        enemies[i].setHealth(1);
    }
}

void App::run()
{

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();


        draw();
        move();
        checkForWalls();

        window.display();
    }
}

void App::draw()
{
    for (int i = 0; i < 50; i++)
    {
        window.draw(enemies[i]);
    }
}

void App::move()
{
    for (int i = 0; i < 50; i++)
    {
        enemies[i].move(enemies[i].getVelocity());
    }
}

void App::checkForWalls()
{
    for (int i = 0; i < 50; i++)
    {
        enemies[i].checkForWalls();
    }
}

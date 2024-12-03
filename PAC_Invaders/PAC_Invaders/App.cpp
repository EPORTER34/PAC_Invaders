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
    Logos[9].loadFromFile("Game_Background.png");


    background.setTexture(Logos[9]);
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
    Projectile* footballs = new Projectile[100];
    Clock clock;
    Clock movementClock;

    int dropTime = 5;
    int inc = 0;
    bool enemyProj = false;
    

    


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(background);

        enemyFire(footballs, player, inc, enemyProj, clock, dropTime);
        drawEnemies();
        drawPlayer(player);

        
        
        movePlayer(player);
        moveEnemies();
        moveRow(movementClock);
        checkForWallsEnemies();

        

        window.display();
    }
}


void App::moveRow(Clock& movementClock)
{
    if (movementClock.getElapsedTime().asSeconds() >= 30)
    {
        movementClock.restart();
        for (int i = 0; i < 40; i++)
        {
            enemies[i].setPosition(enemies[i].getPosition().x, enemies[i].getPosition().y + 50);
        }
    }
}

void App::drawPlayer(Player& player)
{
    player.draw(window);
}

void App::movePlayer(Player& player)
{
    player.update();
    player.playerBounds(window);
}

void App::drawEnemies()
{
    for (int i = 0; i < 40; i++)
    {
        if (enemies[i].getHealth() > 0)
        {
            window.draw(enemies[i]);
        }
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

void App::enemyFire(Projectile*& footballs, Player& player, int& inc, bool& projFired, Clock& clock, int& dropTime)
{
    int randEnemy = rand() % 30;

    if (clock.getElapsedTime().asSeconds() >= 5) // start at 5
    {
        if ((int)clock.getElapsedTime().asSeconds() == dropTime) // rounhds the time off so that we don't skip over the value
        {
            randEnemy = rand() % 30; // chooses an enemy, will need to be altered for when enemies get taken out, probably just a check to see if health == 0
            footballs[inc].setPosition(enemies[randEnemy].getPosition().x, enemies[randEnemy].getPosition().y);
            inc++;
            projFired = true;
            dropTime += rand() % 7 + 1;
        }
    }

    if (projFired)
    {
        for (int i = 0; i < inc; i++)
        {
            window.draw(footballs[i]);
            enemies[randEnemy].fireFootballs(footballs[i]);

            if (footballs[i].getGlobalBounds().intersects(player.getGlobalBounds()))
            {
                cout << "Boom!" << endl;
                projFired = false;
            }
        }
        
    }

    if (footballs != nullptr)
    {
        if (footballs[inc].getPosition().y >= 540)
        {
            inc++;
            projFired = false;
        }
    }
}



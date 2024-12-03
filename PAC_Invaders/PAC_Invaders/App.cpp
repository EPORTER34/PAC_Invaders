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
    Player player(480, window.getSize().y - 100, 3, "WSU_Logo.png");
    Projectile* footballs = new Projectile[100];
    Clock clock;

    int dropTime = 5;
    int inc = 0;
    int finished = 0;
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

        enemyFire(footballs, player, inc, enemyProj, clock, dropTime, finished);
        drawEnemies();
        drawPlayer(player);
        displayLives(player);

        
        
        movePlayer(player);
        moveEnemies();
        checkForWallsEnemies();

        

        window.display();
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

void App::enemyFire(Projectile*& footballs, Player& player, int& inc, bool& projFired, Clock& clock, int& dropTime, int& finished)
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
        for (int i = finished; i < inc; i++)
        {
            window.draw(footballs[i]);
            enemies[randEnemy].fireFootballs(footballs[i]);

            if (footballs[i].getGlobalBounds().intersects(player.getGlobalBounds()))
            {
                cout << "Boom!" << endl;
                player.setHealth(player.getHealth() - 1);
                projFired = false;
                finished++;
            }
        }
        
    }

    if (footballs != nullptr)
    {
        if (footballs[inc].getPosition().y >= 540)
        {
            inc++;
            projFired = false;
            finished++;
        }
    }
}

void App::displayLives(Player& player)
{
    vector<Sprite> logos(3);
    Texture texture;

    if (!texture.loadFromFile("WSU_Logo.png"))
    {
        cout << "error getting sprite";
    }

    for (int i = 0; i < 3; i++)
    {
        logos[i].setTexture(texture);
        logos[i].setScale(.5, .5);
    }

    logos[0].setPosition(850, 500);
    logos[1].setPosition(880, 500);
    logos[2].setPosition(910, 500);

    if (player.getHealth() == 3)
    {
        window.draw(logos[0]);
        window.draw(logos[1]);
        window.draw(logos[2]);
    }
    else if (player.getHealth() == 2)
    {
        window.draw(logos[0]);
        window.draw(logos[1]);
    }
    else if (player.getHealth() == 1)
    {
        window.draw(logos[0]);
    }
    
}



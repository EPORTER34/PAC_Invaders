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

    //setting menu, tutorial, & game over text
    menuFont.loadFromFile("ARIALBD.TTF");
    gameOverText.setFont(menuFont);
    gameOverText.setString("Game Over");
    gameOverText.setPosition(320,100);
    gameOverText.setCharacterSize(64);
    gameOverText.setFillColor(Color::Red);
    title.setFont(menuFont);
    title.setString("PAC Invaders");
    title.setPosition(183, 50);
    title.setCharacterSize(96);
    title.setFillColor(Color::Red);
    leftRight.setFont(menuFont);
    leftRight.setString("Use Left/Right Arrows for Movement");
    leftRight.setPosition(2, 130);
    leftRight.setCharacterSize(16);
    leftRight.setFillColor(Color::Red);
    fire.setFont(menuFont);
    fire.setString("Use Up Arrow to Fire");
    fire.setPosition(352, 130);
    fire.setCharacterSize(16);
    fire.setFillColor(Color::Red);
    goal.setFont(menuFont);
    goal.setString("Goal is to kill all enemies");
    goal.setPosition(552, 130);
    goal.setCharacterSize(16);
    goal.setFillColor(Color::Red);
    lifeTable.setFont(menuFont);
    lifeTable.setString("Enemies have x Number of Lives");
    lifeTable.setPosition(30, 250);
    lifeTable.setCharacterSize(16);
    lifeTable.setFillColor(Color::Red);
    for (int i = 0; i < 3; i++)
    {
        numbers[i].setFont(menuFont);
        numbers[i].setPosition(2, 300 + 50 * i);
        numbers[i].setFillColor(Color::Red);
        numbers[i].setCharacterSize(24);
    }
    numbers[0].setString("1");
    numbers[1].setString("2");
    numbers[2].setString("3");
    for (int i = 0; i < 3; i++)
    {
        menuOptions[i].setFont(menuFont);
        menuOptions[i].setPosition(350, 175 + 75 * i);
        menuOptions[i].setFillColor(Color::Red);
        menuOptions[i].setCharacterSize(48);
    }
    menuOptions[0].setString("(1)Play");
    menuOptions[1].setString("(2)How to Play");
    menuOptions[2].setString("(3)Exit");
    enterToContinue.setFont(menuFont);
    enterToContinue.setPosition(220, 470);
    enterToContinue.setFillColor(Color::Red);
    enterToContinue.setCharacterSize(48);
    enterToContinue.setString("Press Enter to Continue");

    //logos for the tutorial
    for (int i = 0; i < 9; i++)
    {
        tutorialImages[i].setTexture(Logos[i]);
    }
    tutorialImages[1].setPosition(30, 300);
    tutorialImages[3].setPosition(100, 300);
    tutorialImages[4].setPosition(170, 300);
    tutorialImages[4].setScale(1.2, 1.2);
    tutorialImages[6].setPosition(220, 300);
    tutorialImages[6].setScale(.8, .8);
    tutorialImages[5].setPosition(30, 350);
    tutorialImages[7].setPosition(100, 350);
    tutorialImages[8].setPosition(170, 350);
    tutorialImages[2].setPosition(30, 400);

    //scoring system
    score = 0;
    Score.setString("Score: 0");
    Score.setFont(menuFont);
    Score.setFillColor(Color::Red);
    Score.setCharacterSize(48);
    Score.setPosition(2, 485);

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

    vector<Projectile> enemyBalls(250);
    vector<Projectile> playerBalls(250);

    Clock clock;
    Clock cooldownClock;
    Clock movementClock;

    int dropTime = 3;
    int enemyInc = 0;
    int playerInc = 0;
    int menu = 0;
    int round = 0;

    bool enemyProj = false;
    bool keyPressedOnce = false;

    Texture temp;
    temp.loadFromFile("pixel_football.png");
    tutorialImages[9].setTexture(temp);
    tutorialImages[9].setScale(.05, .05);
    tutorialImages[9].setPosition(420,45);

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

        switch (menu)
        {
        case 0: //main menu
            if (Keyboard::isKeyPressed(Keyboard::Key::Num1)) //hit play
            {
                menu = 2;
                Score.setPosition(2, 485);
                movementClock.restart();
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::Num2)) //hit how to play
            {
                menu = 1;
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::Num3)) //hit exit
            {
                window.close();
            }
            window.draw(title);
            window.draw(menuOptions[0]);
            window.draw(menuOptions[1]);
            window.draw(menuOptions[2]);
            break;
        case 1: //how to play
            drawTutorial();
            
            if (Keyboard::isKeyPressed(Keyboard::Key::Enter))
            {
                menu = 0;
            }
            break;
        case 2: //main game
            enemyFire(enemyBalls, playerBalls, player, enemyInc, enemyProj, clock, dropTime);
            playerFire(player, playerBalls, playerInc, event, keyPressedOnce, cooldownClock);
            drawEnemies();
            drawPlayer(player);
            displayLives(player);
            movePlayer(player);
            moveRow(movementClock,round);
            window.draw(Score);
            if (levelCleared())
            {
                resetEnemies();
                score += 1000;
                Score.setString("Score: " + to_string(score));
                round--;
            }
            if (player.getHealth() <= 0)
            {
                Score.setPosition(320, 175);
                menu = 3;
            }
            break;
        case 3: //game over screen
            window.draw(gameOverText);
            window.draw(enterToContinue);
            window.draw(Score);
            if (Keyboard::isKeyPressed(Keyboard::Key::Enter))
            {
                round = 0;
                menu = 0;
                player.setHealth(3);
                resetEnemies();
            }
            break;
        }
        
        window.display();
    }
}


void App::moveRow(Clock& movementClock, int round)
{
    if (movementClock.getElapsedTime().asSeconds() >= 10 - .1 * round)
    {
        movementClock.restart();
        for (int i = 0; i < 30; i++)
        {
            enemies[i].setPosition(enemies[i].getPosition().x, enemies[i].getPosition().y + 50);
        }
    }
}

void App::drawPlayer(Player& player)
{
    window.draw(player);
}

void App::movePlayer(Player& player)
{
    player.update();
    player.playerBounds(window);
}

void App::drawEnemies()
{
    for (int i = 0; i < 30; i++)
    {
        if (enemies[i].getHealth() > 0)
        {
            window.draw(enemies[i]);
        }
        else
        {
            enemies[i].setPosition(-30, -30);
        }
    }
}

void App::enemyFire(vector<Projectile>& footballs,  vector<Projectile>& playerBalls, Player& player, int& inc, bool& projFired, Clock& clock, int& dropTime)
{
    int randEnemy = rand() % 30;

   
    if (clock.getElapsedTime().asSeconds() >= 3) // start at 3
    {
        if (clock.getElapsedTime().asSeconds() > dropTime) // runs when we pass the drop time
        {
            randEnemy = rand() % 30; // chooses an enemy, will need to be altered for when enemies get taken out, probably just a check to see if health == 0
            while (enemies[randEnemy].getHealth() == 0)
            {
                randEnemy = rand() % 30; // keep generating new enemies until we have one that isn't dead
            }
            footballs[inc].setPosition(enemies[randEnemy].getPosition().x, enemies[randEnemy].getPosition().y); // football spawns by the enemy
            inc++;
            projFired = true; 
            dropTime += rand() % 2 + 1; // generates a new drop time
        }
    }
    
    
    if (projFired)
    {
        for (int i = 0; i < inc; i++)
        {
            window.draw(footballs[i]); 
            enemies[randEnemy].fireFootballs(footballs[i]);

            if (footballs[i].getGlobalBounds().intersects(player.getGlobalBounds())) // handles collisions
            {
                cout << "Boom!" << endl;
                player.setHealth(player.getHealth() - 1);
                projFired = false; // projectile should no longer be rendered
                footballs.erase(footballs.begin(), footballs.begin() + inc);
                for (int row = 0; row < 3; row++) //resetting enemy position to top of the screen
                {
                    for (int column = 0; column < 10; column++)
                    {
                        enemies[column + 10 * row].setPosition(100 * column + 5, 25 + 55 * row);
                    }
                }
                footballs.clear();
                footballs.resize(250);
                playerBalls.clear();
                playerBalls.resize(250);
                inc = 0;
                clock.restart();
                dropTime = 3; // resets drop time because the round basically reset
            }
        }
        
    }

    if (!footballs.empty())
    {
        if (footballs[inc].getPosition().y >= 540) // if the football goes off screen stop rendering it
        {
            inc++;
            projFired = false;
        }
    }
}

void App::playerFire(Player& player, vector<Projectile>& playerBalls, int& playerInc, Event event, bool& keyPressedOnce, Clock& clock)
{
    int hit = -1; // flag variable

    if (event.type == Event::KeyPressed && !keyPressedOnce) 
    {
        if (clock.getElapsedTime().asSeconds() > .75) // a cooldown so that the player can't just spam footballs
        {
            if (event.key.code == Keyboard::Up)
            {
                playerBalls[playerInc].setPosition(player.getPosition());
                playerBalls[playerInc].setFired(true);
                playerInc++;
                clock.restart();
                keyPressedOnce = true;
            }
        }
    }

    if (event.type == Event::KeyReleased) // only want the player to shoot one ball per press, no matter how long they hold it
    {
        if (event.key.code == Keyboard::Up)
        {
            keyPressedOnce = false;
        }
    }

    for (int i = 0; i < playerInc; i++) // 
    {
        if (playerBalls[i].getFired() == true) 
        {
            window.draw(playerBalls[i]);
            player.fireFootballs(playerBalls[i]);
        }
        if (playerBalls[i].getGlobalBounds().top + playerBalls[i].getGlobalBounds().height <= 0)
        {
            playerBalls[i].setFired(false);
            playerBalls[i].setPosition(-100, -100);
        }

        for (int j = 0; j < 30; j++)
        {
            if (playerBalls[i].getGlobalBounds().intersects(enemies[j].getGlobalBounds()))
            {
                hit = j;
            }
        }

        if (hit != -1)
        {
            enemies[hit].setHealth(enemies[hit].getHealth() - 1);
            if (enemies[hit].getHealth() == 0)
            {
                enemies[hit].setPosition(-100, -100);
            }
            playerBalls[i].setFired(false);
            playerBalls[i].setPosition(-100, -100);
            score += 100;
            Score.setString("Score: " + to_string(score));

            hit = -1;
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

void App::drawTutorial()
{
    window.draw(enterToContinue);
    tutorialImages[0].setPosition(100, 75);
    window.draw(tutorialImages[0]);
    window.draw(leftRight);
    tutorialImages[0].setPosition(400, 75);
    window.draw(tutorialImages[0]);
    window.draw(fire);
    window.draw(tutorialImages[9]);
    window.draw(goal);
    window.draw(lifeTable);
    window.draw(numbers[0]);
    window.draw(numbers[1]);
    window.draw(numbers[2]);
    for (int i = 0; i < 9; i++)
    {
        window.draw(tutorialImages[i]);
    }
}

void App::resetEnemies()
{
    for (int row = 0; row < 3; row++) //resetting enemy health and position
    {
        for (int column = 0; column < 10; column++)
        {
            switch (row)
            {
            case 0:
                if (column < 3 || column > 6)
                {
                    enemies[column].setHealth(1);
                }
                else
                {
                    enemies[column].setHealth(3);
                }
                break;
            case 1:
                enemies[column + 10].setHealth(2);
                break;
            case 2:
                enemies[column + 20].setHealth(1);
                break;
            }
            enemies[column + 10 * row].setPosition(100 * column + 5, 25 + 55 * row);
        }
    }
}

bool App::levelCleared()
{
    bool result = true;

    for (int i = 0; i < 30; i++)
    {
        if (enemies[i].getHealth() > 0)
        {
            result = false;
        }
    }

    return result;
}

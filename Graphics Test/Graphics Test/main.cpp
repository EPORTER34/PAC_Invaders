#include "header.hpp"
#include "hitBox.hpp"
#include "Enemy.hpp"

int main()
{
    srand(time(NULL));
    RenderWindow window(sf::VideoMode(1920, 1080), "Test");
    int thing = 0;
    Vector2f t = { 0,0 };
    Enemy teeemp(t,3);
    Enemy test[10] = { { t, 3 } ,{ t, 3 } ,{ t, 3 } ,{ t, 3 } ,{ t, 3 } ,{ t, 3 } ,{ t, 3 } ,{ t, 3 } ,{ t, 3 } ,{ t, 3 } };

    Texture temp;
    temp.loadFromFile("WSU_Logo.png");
    for (int i = 0; i < 10; i++)
    {
        test[i].setTexture(temp);
        test[i].setPosition({ 450.f + 100.f * i,100.f});
        test[i].setDefaultPosition({ 450.f + 100.f * i,100.f });
    }
    

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        
        for (int i = 0; i < 10; i++)
        {
            window.draw(test[i]);
        }
        thing = rand() % 10000;
        if (thing < 10)
        {
            test[thing].setVelocity(0, .1);
        }
        for (int i = 0; i < 10; i++)
        {
            test[i].move(test[i].getVelocity());
        }
        for (int i = 0; i < 10; i++)
        {
            test[i].checkForWalls();
        }
        for (int i = 0; i < 10; i++)
        {
            if (test[i].getDefaultPosition().y > test[i].getPosition().y /* && test[i].getCycle() == 1*/)
            {
                test[i].setVelocity(0, 0);
            }
        }

        window.display();
    }

    return 0;
}
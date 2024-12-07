#include "Test.hpp"

void Test::testPlayerFIre()
{
    RenderWindow window(VideoMode(960, 540), "Pac_Invaders");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
        window.display();
    }
}

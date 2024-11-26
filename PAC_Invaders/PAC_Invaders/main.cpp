#include "header.hpp"
#include "hitBox.hpp"
#include "wsuPlayer.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
   /* sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);*/
    Player player(50.0f, 300.0f, "WSU_Logo.png");//used to change position of player and open up the wsu sprite

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        player.update();
        player.playerBounds(window);

        window.clear();
        player.draw(window);//using function from wsuPlayer.cpp to draw
        window.display();
    }

    return 0;
}
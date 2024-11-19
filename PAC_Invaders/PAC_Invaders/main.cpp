#include "header.hpp"
#include "hitBox.hpp"
#include "Enemy.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    sf::CircleShape shape(100.f);
    Vector2f v = { 0,0 };

    Enemy thing(v, 3);
    Texture temp;
    temp.loadFromFile("WSU_Logo.png");
    thing.setTexture(temp);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        window.draw(thing);
        window.draw(shape);
        window.display();
    }

    return 0;
}
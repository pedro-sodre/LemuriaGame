#pragma once
#include "SFML/Graphics.hpp"

class Platform
{
public:
    Platform(sf::Vector2f tam, sf::Vector2f position);
    ~Platform();
    static int Nplat;

    void Draw(sf::RenderWindow& window);
    void setBody(sf::RectangleShape* b);
    sf::RectangleShape* getBody();

private:
    sf::RectangleShape* body;

};


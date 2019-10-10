#include "Platform.h"

Platform::Platform(sf::Vector2f tam, sf::Vector2f position)
{
    body = new sf::RectangleShape();

    body->setSize(tam);
    body->setOrigin(tam/2.0f);
    body->setPosition(position);
    body->setFillColor(sf::Color(92, 64, 51));
    Nplat++;
}

Platform::~Platform()
{
    delete body;
    Nplat--;
    //dtor
}

void Platform::setBody(sf::RectangleShape* b)
{
    body = b;
}

sf::RectangleShape* Platform::getBody()
{
    return body;
}

void Platform::Draw(sf::RenderWindow& window)
{
    window.draw(*body);
}

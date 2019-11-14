#include "EntidadeColidivel.h"

EntidadeColidivel::EntidadeColidivel():
Entidade()
{
    body = new sf::RectangleShape();
}

EntidadeColidivel::EntidadeColidivel(sf::RectangleShape* body):
Entidade()
{
    body = new sf::RectangleShape();
    body = body;
}

void EntidadeColidivel::destruir()
{
    delete body;
}

EntidadeColidivel::~EntidadeColidivel()
{
    destruir();
}

void EntidadeColidivel::setTexture(const sf::Texture pTexture)
{
    texture = pTexture;
    body->setTexture(&texture);
}



void EntidadeColidivel::executar(float deltaTime)
{
}

void EntidadeColidivel::Draw(sf::RenderWindow& window)
{
    window.draw(*body);
}

void EntidadeColidivel::onCollision(sf::Vector2f direction)
{
    if(direction.x < 0.0f)
        velocity.x = 0.0f;

    else if(direction.x > 0.0f)
        velocity.x = 0.0f;

    if(direction.y < 0.0f)
    {
        velocity.y = 0.0f;
    }

    if(direction.y > 0.0f)
        velocity.y = 0.0f;
}

void EntidadeColidivel::setBody(sf::RectangleShape* b)
{
    body = b;
}

sf::RectangleShape* EntidadeColidivel::getBody()
{
    return body;
}
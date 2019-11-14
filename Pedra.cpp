#include "Pedra.h"

Pedra::Pedra(sf::Vector2f tam, sf::Vector2f position, sf::Texture text, float peso, int ID):
Obstaculo()
{
    id = ID;
    body->setSize(tam);
    body->setOrigin(tam/2.0f);
    body->setPosition(position);

    x = position.x;
    y = position.y;

    this->peso = peso;

    texture = text;
    body->setTexture(&texture);
}

Pedra::~Pedra()
{
}

Pedra::Pedra(const Pedra& other, float x, float y):
Obstaculo()
{
    id = other.id;
    tam = other.body->getSize();
    body->setSize(tam);
    body->setOrigin(tam/2.0f);
    body->setPosition(x,y);

    x = other.x;
    y = other.y;

    peso = other.peso;

    texture = other.texture;
    body->setTexture(&texture);
}
void Pedra::executar(float deltaTime)
{
    velocity.x = 0.0f;
    velocity.y += 981.0f * deltaTime;                    //GRAVIDADE

    body->move(velocity * deltaTime);

    x = this->getPosition().x;
    y = this->getPosition().y;
}

Pedra* Pedra::clone(float x, float y) const
{
    return new Pedra(*this, x, y);
}

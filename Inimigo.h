#pragma once
#include "Personagem.h"

class Fase;

class Inimigo: public Personagem
{
protected:
    sf::RectangleShape* player1;
    sf::RectangleShape* player2;
    Fase* fase;
public:
    Inimigo();
    Inimigo(sf::RectangleShape* p1, sf::RectangleShape* p2);
    Inimigo(sf::RectangleShape* p1);
    virtual ~Inimigo();

    virtual void executar(float deltaTime);
};

#pragma once
#include "EntidadeColidivel.h"

class Obstaculo: public EntidadeColidivel
{
protected:
    sf::Vector2f tam;
    float peso;
public:
    Obstaculo();
    virtual ~Obstaculo();

    const float getPeso();

    virtual void executar(float deltaTime);
};

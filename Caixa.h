#pragma once
#include "Obstaculo.h"

class Caixa: public Obstaculo
{
private:

public:
    Caixa(sf::Vector2f tam, sf::Vector2f position, sf::Texture text, float peso = 0.5f, int ID = 3);
    Caixa(const Caixa& other, float x, float y);
    ~Caixa();

    void executar(float deltaTime);
    Caixa* clone(float x, float y) const;
};

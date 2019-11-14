#pragma once
#include "Obstaculo.h"

class Pedra: public Obstaculo
{
private:

public:
    Pedra(sf::Vector2f tam, sf::Vector2f position, sf::Texture text, float peso = 0.95f, int ID = 4);
    Pedra(const Pedra& other, float x, float y);
    ~Pedra();

    Pedra* clone(float x, float y) const;
    void executar(float deltaTime);
};


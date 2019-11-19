#pragma once
#include "Obstaculo.h"

class Tronco: public Obstaculo
{
private:

public:
    Tronco(const sf::Vector2f tam, const sf::Vector2f position, const sf::Texture text, const float peso = 0.99f, const int ID = 9);
    Tronco(const Tronco& other, float x, float y);
    ~Tronco();

    void inicializa(const sf::Vector2f tam, const sf::Vector2f position, const sf::Texture text, const float peso = 0.99f, const int ID = 9);
    Tronco* clone(float x, float y) const;

    void executar(float deltaTime);
};


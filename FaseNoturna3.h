#pragma once
#include "Fase.h"

class FaseNoturna3: public Fase
{
private:

public:
    FaseNoturna3(sf::Vector2f tam, Lemurya* jogo);
    ~FaseNoturna3();

    void Draw(sf::RenderWindow& window);
    void executar();
};



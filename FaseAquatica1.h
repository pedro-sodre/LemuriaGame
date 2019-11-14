#pragma once
#include "Fase.h"

class FaseAquatica1: public Fase
{
private:

public:
    FaseAquatica1(sf::Vector2f tam);
    ~FaseAquatica1();

    void Draw(sf::RenderWindow& window);
    void executar();
    void recuperarJogo(ListaEntidades& Lent, ListaInimigos& Lin, ListaObstaculos& Lobs, ListaPlataformas& Lplat, ListaProjeteis& Lproj, LemuryaPrototypeFactory prototype, Player& p1);
    void gravarJogo(ListaEntidades& Lentidades);

};

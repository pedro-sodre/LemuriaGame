#pragma once
#include "Fase.h"

class FaseAquatica2: public Fase
{
private:

public:
    FaseAquatica2(sf::Vector2f tam);
    ~FaseAquatica2();

    void Draw(sf::RenderWindow& window);
    void executar();
    void recuperarJogo(ListaEntidades& Lent, ListaInimigos& Lin, ListaObstaculos& Lobs, ListaPlataformas& Lplat, ListaProjeteis& Lproj, LemuryaPrototypeFactory prototype, Player& p1);
    void gravarJogo(ListaEntidades& Lentidades);
};


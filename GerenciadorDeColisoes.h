#pragma once
#include "ListaInimigos.h"
#include "ListaPlataformas.h"
#include "ListaObstaculos.h"
#include "ListaEntidades.h"
#include "ListaProjeteis.h"
#include "Player.h"
#include <stdio.h>

class GerenciadorDeColisoes
{
private:
    Player* player1;
    Platform* aux;
    ListaPlataformas* Lplataformas;
    ListaObstaculos* Lobstaculos;
    ListaInimigos* Linimigos;
    ListaEntidades* Lentidades;
    ListaProjeteis* Lprojeteis;
    sf::Vector2f direction;

public:
    GerenciadorDeColisoes(Player* p1, ListaPlataformas* lp, ListaObstaculos* lo, ListaInimigos* li, ListaEntidades* le, ListaProjeteis* lproj);
    ~GerenciadorDeColisoes();

    void executar();
};

#pragma once
#include "Lista.h"
#include "Inimigo.h"

class ListaInimigos
{
private:
    vector<Inimigo*> LTInimigos;
public:
    ListaInimigos();
    ~ListaInimigos();

    vector<Inimigo*> getLTInimigos();

    void retirar(int i);
    void limpaLista();
    void incluir(Inimigo* pi);
};

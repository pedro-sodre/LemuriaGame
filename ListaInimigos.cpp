#include "ListaInimigos.h"

ListaInimigos::ListaInimigos()
{
}

ListaInimigos::~ListaInimigos()
{
    limpaLista();
}

void ListaInimigos::limpaLista()
{
    LTInimigos.clear();
}

void ListaInimigos::incluir(Inimigo* pi)
{
    if(pi)
        LTInimigos.push_back(pi);
}

vector<Inimigo*> ListaInimigos::getLTInimigos()
{
    return LTInimigos;
}

void ListaInimigos::retirar(int i)
{
    LTInimigos.erase(LTInimigos.begin() + i);
}

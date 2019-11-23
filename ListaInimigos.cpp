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

void ListaInimigos::retirar(const int i)
{
    //delete LTInimigos[i];                     DESSA FORMA D� CERTO
    LTInimigos.erase(LTInimigos.begin() + i);
}

const int ListaInimigos::getTamanho() const
{
    return LTInimigos.size();
}

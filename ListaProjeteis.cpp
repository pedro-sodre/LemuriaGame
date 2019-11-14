#include "ListaProjeteis.h"

ListaProjeteis::ListaProjeteis()
{
}

ListaProjeteis::~ListaProjeteis()
{
    limpaLista();
}

void ListaProjeteis::limpaLista()
{
    LTProjeteis.clear();
}

void ListaProjeteis::incluir(BolaDeFogo* pp)
{
    if(pp != NULL)
        LTProjeteis.push_back(pp);
}

vector<BolaDeFogo*> ListaProjeteis::getLTProjeteis()
{
    return LTProjeteis;
}

void ListaProjeteis::retirar(int i)
{
    LTProjeteis.erase(LTProjeteis.begin() + i);
}

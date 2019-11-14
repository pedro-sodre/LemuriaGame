#pragma once
#include "Lista.h"
#include "BolaDeFogo.h"

class ListaProjeteis
{
private:
    vector<BolaDeFogo*> LTProjeteis;
public:
    ListaProjeteis();
    ~ListaProjeteis();

    vector<BolaDeFogo*> getLTProjeteis();

    void limpaLista();
    void incluir(BolaDeFogo* pp);
    void retirar(int i);
};

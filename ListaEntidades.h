#pragma once
#include "Lista.h"
#include "Entidade.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;


class ListaEntidades
{
private:
    Lista<Entidade> LTEntidades;
public:
    ListaEntidades();
    ~ListaEntidades();

    void executar(float deltaTime);
    void Draw(sf::RenderWindow& window);

    void gravarJogo();

    void limpaLista();
    void incluir(Entidade* pe);
    void retirar();

    Entidade* percorrer();
    Entidade* reiniciar();
};


#pragma once
#include "Elemento.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
using std::vector;

using std::cout;
using std::endl;

template<class TIPO>
class Lista
{
private:
    Elemento<TIPO>* pPrimeiro;
    Elemento<TIPO>* pAtual;

    Elemento<TIPO>* pPercorrimento;     ///TESTE PARA GERENCIAR COLISÕES

public:
    Lista();
    ~Lista();

    void inicializa();
    void limpar();

    bool incluaElemento(Elemento<TIPO>* pElemento);
    bool incluaInfo(TIPO* pInfo);
    void listeInfos();

    void setpPercorrimento(Elemento<TIPO>* p);

    Elemento<TIPO>* getpPrimeiro();
    Elemento<TIPO>* getpAtual();
    Elemento<TIPO>* getpPercorrimento();

};

template<class TIPO>
Lista<TIPO>::Lista()
{
    inicializa();
}

template<class TIPO>
Lista<TIPO>::~Lista()
{
    limpar();
}

template<class TIPO>
void Lista<TIPO>::limpar()
{
    Elemento<TIPO>* paux1;
    Elemento<TIPO>* paux2;

    paux1 = pPrimeiro;
    paux2 = paux1;

    while (paux1 != NULL)
    {
        paux2 = paux1->getProximo();
        delete (paux1);
        paux1 = paux2;
    }

    pPrimeiro = NULL;
    pAtual = NULL;
    pPercorrimento = NULL;
}

template<class TIPO>
void Lista<TIPO>::inicializa()
{
    pPrimeiro = NULL;
    pAtual = NULL;
    pPercorrimento = NULL;
}

template<class TIPO>
bool Lista<TIPO>::incluaElemento(Elemento<TIPO>* pElemento)
{
    if (NULL != pElemento)
    {
        if (NULL == pPrimeiro)
        {
            pPrimeiro = pElemento;
            pPercorrimento = pPrimeiro;
            pAtual = pPrimeiro;
        }
        else
        {
            pElemento->setAnterior(pAtual);
            pElemento->setProximo(NULL);
            pAtual->setProximo(pElemento);
            pAtual = pAtual->getProximo();
        }
        return true;
    }
    else
    {
        cout << " Erro, elemento nulo na lista. " << endl;
        return false;
    }
}

template<class TIPO>
bool Lista<TIPO>::incluaInfo(TIPO* pInfo)
{
    if (NULL != pInfo)
    {
        Elemento<TIPO>* pElemento;
        pElemento = new Elemento<TIPO>();
        pElemento->setInfo(pInfo);
        incluaElemento(pElemento);
        return true;
    }
    else
    {
        cout << "Erro, informação nula na lista. " << endl;
        return false;
    }
}

template<class TIPO>
Elemento<TIPO>* Lista<TIPO>::getpPrimeiro()
{
    return pPrimeiro;
}

template<class TIPO>
Elemento<TIPO>* Lista<TIPO>::getpAtual()
{
    return pAtual;
}

template<class TIPO>
Elemento<TIPO>* Lista<TIPO>::getpPercorrimento()
{
    return pPercorrimento;
}

template<class TIPO>
void Lista<TIPO>::setpPercorrimento(Elemento<TIPO>* p)
{
    pPercorrimento = p;
}

#pragma once
#include <stdio.h>
#include <stdlib.h>

template<class TIPO>
class Elemento
{
private:
    Elemento<TIPO>* pProximo;
    Elemento<TIPO>* pAnterior;
    TIPO* pInfo;

public:
    Elemento();
    ~Elemento();

    void setProximo(Elemento<TIPO>* pp);
    Elemento<TIPO>* getProximo();

    void setAnterior(Elemento<TIPO>* pa);
    Elemento<TIPO>* getAnterior();

    void setInfo(TIPO* pi);
    TIPO* getInfo();
};

template<class TIPO>
Elemento<TIPO>::Elemento()
{
    pProximo  = NULL;
    pAnterior = NULL;
    pInfo     = NULL;
}

template<class TIPO>
Elemento<TIPO>::~Elemento()
{
    pProximo  = NULL;
    pAnterior = NULL;
    pInfo     = NULL;
}

template<class TIPO>
void Elemento<TIPO>::setProximo(Elemento<TIPO>* pp)
{
    pProximo = pp;
}

template<class TIPO>
Elemento<TIPO>* Elemento<TIPO>::getProximo()
{
    return pProximo;
}

template<class TIPO>
void Elemento<TIPO>::setAnterior(Elemento<TIPO>* pa)
{
    pAnterior = pa;
}

template<class TIPO>
Elemento<TIPO>* Elemento<TIPO>::getAnterior()
{
    return pAnterior;
}

template<class TIPO>
void Elemento<TIPO>::setInfo(TIPO* pi)
{
    pInfo = pi;
}

template<class TIPO>
TIPO* Elemento<TIPO>::getInfo()
{
    return pInfo;
}

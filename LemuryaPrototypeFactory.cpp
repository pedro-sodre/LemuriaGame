#include "LemuryaPrototypeFactory.h"

LemuryaPrototypeFactory::LemuryaPrototypeFactory()
{
    esqueleto   = NULL;
    mago        = NULL;
    tritao      = NULL;
    chao        = NULL;
    plataforma  = NULL;
    caixa1      = NULL;
    pedra1      = NULL;
    pedra2      = NULL;
    bolaDeFogo  = NULL;
}

LemuryaPrototypeFactory::LemuryaPrototypeFactory(Caixa* c1, Pedra* p1, Pedra* p2, Esqueleto* e1, Mago* m1, Platform* pf1, Platform* pf2, Tritao* t1, BolaDeFogo* bf1)
{
    inicializa(c1, p1, p2, e1, m1, pf1, pf2,t1, bf1);
}

void LemuryaPrototypeFactory::inicializa(Caixa* c1, Pedra* p1, Pedra* p2, Esqueleto* e1, Mago* m1, Platform* pf1, Platform* pf2, Tritao* t1, BolaDeFogo* bf1)
{
    caixa1 = c1;
    pedra1 = p1;
    pedra2 = p2;
    esqueleto = e1;
    mago = m1;
    plataforma = pf1;
    chao = pf2;
    tritao = t1;
    bolaDeFogo = bf1;
}

LemuryaPrototypeFactory::~LemuryaPrototypeFactory()
{
    esqueleto   = NULL;
    mago        = NULL;
    tritao      = NULL;
    chao        = NULL;
    plataforma  = NULL;
    caixa1      = NULL;
    pedra1      = NULL;
    pedra2      = NULL;
    bolaDeFogo  = NULL;
}

Caixa* LemuryaPrototypeFactory::MakeCaixa(float x, float y) const
{
    return caixa1->clone(x,y);
}

Pedra* LemuryaPrototypeFactory::MakePedra(float x, float y) const
{
    return pedra1->clone(x,y);
}

Pedra* LemuryaPrototypeFactory::MakePedra2(float x, float y) const
{
    return pedra2->clone(x,y);
}

Esqueleto* LemuryaPrototypeFactory::MakeEsqueleto(float x, float y) const
{
    return esqueleto->clone(x,y);
}

Tritao* LemuryaPrototypeFactory::MakeTritao(float x, float y) const
{
    return tritao->clone(x,y);
}

Mago* LemuryaPrototypeFactory::MakeMago(float x, float y) const
{
    return mago->clone(x,y);
}

Platform* LemuryaPrototypeFactory::MakePlataforma(float x, float y) const
{
    return plataforma->clone(x,y);
}

Platform* LemuryaPrototypeFactory::MakeChao(float x, float y) const
{
    return chao->clone(x,y);
}

BolaDeFogo* LemuryaPrototypeFactory::MakeBolaDeFogo(float x, float y) const
{
    return bolaDeFogo->clone(x,y);
}

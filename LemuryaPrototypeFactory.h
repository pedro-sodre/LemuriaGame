#pragma once
#include "Mago.h"
#include "Tritao.h"
#include "Esqueleto.h"
#include "BolaDeFogo.h"
#include "Platform.h"
#include "Caixa.h"
#include "Pedra.h"

class LemuryaPrototypeFactory
{
private:
    Esqueleto* esqueleto;
    Mago* mago;
    Tritao* tritao;
    Platform* chao;
    Platform* plataforma;
    Caixa* caixa1;
    Pedra* pedra1;
    Pedra* pedra2;
    BolaDeFogo* bolaDeFogo;
public:
    LemuryaPrototypeFactory(Caixa* c1, Pedra* p1, Pedra* p2, Esqueleto* e1, Mago* m1, Platform* pf1, Platform* pf2, Tritao* t1, BolaDeFogo* bf1);
    LemuryaPrototypeFactory();
    ~LemuryaPrototypeFactory();
    void inicializa(Caixa* c1, Pedra* p1, Pedra* p2, Esqueleto* e1, Mago* m1, Platform* pf1, Platform* pf2, Tritao* t1, BolaDeFogo* bf1);

    Caixa* MakeCaixa(float x, float y) const;
    Esqueleto* MakeEsqueleto(float x, float y) const;
    Mago* MakeMago(float x, float y) const;
    Tritao* MakeTritao(float x, float y) const;
    Platform* MakeChao(float x, float y) const;
    Platform* MakePlataforma(float x, float y) const;
    Pedra* MakePedra(float x, float y) const;
    Pedra* MakePedra2(float x, float y) const;
    BolaDeFogo* MakeBolaDeFogo(float x, float y) const;


};


#pragma once
#include <SFML/Graphics.hpp>

#include "Lemurya.h"

#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <iostream>

class GerenciadorDePontuacao
{
private:
    sf::Text Rank;
    stringstream pRank;
    int pontuacao;

public:
    GerenciadorDePontuacao();
    GerenciadorDePontuacao(Lemurya* jogo);
    ~GerenciadorDePontuacao();

    void inicializa(Lemurya* jogo);
    void destruir();

    void executar();

    void setPontuacao(const int pont);
    void incrementarPontuacao(const int pont);
    int getPontuacao() const;

};

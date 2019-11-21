#pragma once
#include <SFML/Graphics.hpp>

#include "GerenciadorDeColisoes.h"
#include "GerenciadorDePontuacao.h"
#include "GerenciadorGrafico.h"

#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include <vector>
#include <stack>
using std::vector;
#include <map>
#include <string>

#include "LemuryaPrototypeFactory.h"

#include "Lista.h"
#include "ListaPlataformas.h"
#include "ListaObstaculos.h"
#include "ListaInimigos.h"
#include "ListaEntidades.h"
#include "ListaProjeteis.h"

#include "BolaDeFogo.h"
#include "Mago.h"
#include "Tritao.h"
#include "Esqueleto.h"
#include "Player.h"
#include "Platform.h"
#include "Caixa.h"
#include "Pedra.h"

#include "State.h"

class Lemurya;

static const float VIEW_HEIGHT = 1080.0f;

class Fase: public Entidade, public State
{
protected:
    Lemurya* jogo;

    sf::RectangleShape* body;
    GerenciadorDeColisoes gerenciadorDeColisoes;
    GerenciadorDePontuacao gerenciadorDePontuacao;
    LemuryaPrototypeFactory prototype;

    ///CRIA LISTAS
    ListaInimigos Linimigos;
    ListaPlataformas Lplataformas;
    ListaObstaculos Lobstaculos;
    ListaEntidades Lentidades;
    ListaProjeteis Lprojeteis;
public:
    Fase(sf::Vector2f tam, Lemurya* jogo);
    virtual ~Fase();
    void destruir();

    sf::RectangleShape* getBody();
    sf::RectangleShape* getPlayer1();
    sf::RectangleShape* getPlayer2();///PLAYER2

    void lancarBolaDeFogo(int x, int y);
    void spawnarEsqueleto(int x, int y);
    int getNInimigos();

    ListaEntidades* getLentidades();

    virtual void executar(float deltaTime);
    virtual void executar();
    virtual void Draw(sf::RenderWindow& window);
    void gerenciarColisoes();

	virtual void carregarPause();
    ///FAZER FUNÇÃO VIRTUAL, CADA FASE VAI GRAVAR EM UM ARQUIVO
    virtual void recuperarJogo(bool player2) = 0;
    virtual void novoJogo(bool player2) = 0;
    virtual void gravarJogo() = 0;

    virtual void draw() = 0;
	virtual void input() = 0;
	virtual void update() = 0;
};



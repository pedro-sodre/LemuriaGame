#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "GerenciadorDeColisoes.h"
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

#include "Menu.h"

#include "BolaDeFogo.h"
#include "Mago.h"
#include "Tritao.h"
#include "Esqueleto.h"
#include "Player.h"
#include "Platform.h"
#include "Caixa.h"
#include "Pedra.h"

static const float VIEW_HEIGHT = 1080.0f;

class Fase: public Entidade
{
protected:
    sf::RectangleShape* body;
    sf::Music musicaFundo;
    GerenciadorGrafico gerenciadorGrafico;
    LemuryaPrototypeFactory prototype;
	GerenciadorDeColisoes gerenciadorDeColisoes;

    Player player1;
    Player player2;

    ///CRIA LISTAS
    ListaInimigos Linimigos;
    ListaPlataformas Lplataformas;
    ListaObstaculos Lobstaculos;
    ListaEntidades Lentidades;
    ListaProjeteis Lprojeteis;
public:
    Fase(sf::Vector2f tam);
    virtual ~Fase();
    void destruir();

    sf::RectangleShape* getBody();
    sf::RectangleShape* getPlayer1();
    //sf::RectangleShape* getPlayer2();

    void lancarBolaDeFogo(int x, int y);
    void spawnarEsqueleto(int x, int y);
    int getNInimigos();


    virtual void executar(float deltaTime);
    virtual void executar();
    virtual void Draw(sf::RenderWindow& window);
    void gerenciarColisoes();

	virtual void carregarPause();
    ///FAZER FUN��O VIRTUAL, CADA FASE VAI GRAVAR EM UM ARQUIVO
    virtual void recuperarJogo() = 0;
    virtual void gravarJogo() = 0;
};



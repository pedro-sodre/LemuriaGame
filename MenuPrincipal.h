#pragma once
#include "Menu.h"

class MenuPrincipal: public Menu
{
private:
    bool escolhaDeJogadores;
    bool escolhaDeFases;
    int fase;

    sf::Music musicaMenu;
	sf::Text entradaDeTexto;
	sf::String nome;

    bool newGame;

public:
    MenuPrincipal(Lemurya* jogo);
    ~MenuPrincipal();

    //Métodos de State
    void draw();
    void input();
    void update();

    void inicializar();

    void carregarJogo();
    void abrirEscolhaDeJogadores();
	void abrirInputNome();
	void abrirEscolhaDeFases();
    void setRanking();

    void stopMusic();
};



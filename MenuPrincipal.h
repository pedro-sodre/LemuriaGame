#pragma once
#include "Menu.h"

class MenuPrincipal: public Menu
{
private:
    bool escolhaDeJogadores;

    sf::Music musicaMenu;
	sf::Text entradaDeTexto;
	sf::String nome;

    bool newGame;

public:
    MenuPrincipal(Lemurya* jogo);
    ~MenuPrincipal();

    //M�todos de State
    void draw();
    void input();
    void update();

    void inicializar();

    void carregarJogo();
    void abrirEscolhaDeJogadores();
	void abrirInputNome();

    void stopMusic();
};



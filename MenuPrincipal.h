#pragma once
#include "Menu.h"

class MenuPrincipal: public Menu
{
private:
    bool escolhaDeJogadores;

    sf::Music musicaMenu;

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

    void stopMusic();
};



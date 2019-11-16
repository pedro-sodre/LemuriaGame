#pragma once
#include "Fase.h"
#include "State.h"
#include <stack>

class Lemurya {
private:

    sf::Event eventos;

    std::stack<State*> states;
    void inicializar();
    void inicializarStates();

    sf::Clock clock;

    GerenciadorGrafico gerenciadorGrafico;
    //GerenciadorDePontuacao gerenciadorDePontuacao;

    bool p2;    ///PARA USAR NO MENU

    Player player1;
    Player player2;///PLAYER2

public:
    Lemurya();
    ~Lemurya();

    float deltaTime;            ///PECADO
    sf::RenderWindow window;    ///PECADO

    void pushState(State* state);
    void popState();
    State* stateAtual();

    void rodar();

    void encerrar();

    bool getP2() const;
    bool setP2(const bool bp);
    Player* getPlayer1();
    Player* getPlayer2();       ///PLAYER2
    GerenciadorGrafico getGerenciadorGrafico() const;
    //GerenciadorDePontuacao getGerenciadorDePontuacao();
};


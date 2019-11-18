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

    bool salvarFase1;
    bool salvarFase2;
    bool salvarFase3;

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

    bool getSalvarFase1() const;
    bool getSalvarFase2() const;
    bool getSalvarFase3() const;
    void setSalvarFase1(const bool b);
    void setSalvarFase2(const bool b);
    void setSalvarFase3(const bool b);

    bool getP2() const;
    void setP2(const bool bp);
    Player* getPlayer1();
    Player* getPlayer2();       ///PLAYER2
    GerenciadorGrafico getGerenciadorGrafico() const;
    //GerenciadorDePontuacao getGerenciadorDePontuacao();
};


#pragma once
#include "Fase.h"

class FaseAquatica1: public Fase
{
private:
	sf::View view;
public:
    FaseAquatica1(sf::Vector2f tam, Lemurya* jogo);
    ~FaseAquatica1();

	void draw();
	void input();
	void update();
	void inicializar();

    void Draw(sf::RenderWindow& window);
    void executar();

	void carregarPause();

    void recuperarJogo();
    void gravarJogo();

};


#pragma once
#include "Fase.h"

class FaseAquatica2: public Fase
{
private:
	sf::View view;
public:
    FaseAquatica2(sf::Vector2f tam, Lemurya* jogo);
    ~FaseAquatica2();

    void Draw(sf::RenderWindow& window);
    void executar();

	void draw();
	void input();
	void update();
	void inicializar();

	void carregarPause();
	void carregarMorte();
	void carregarProxFase();

    void recuperarJogo(bool player2 = false);
    void novoJogo(bool player2 = false);
    void gravarJogo();
};


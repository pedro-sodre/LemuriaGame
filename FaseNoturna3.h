#pragma once
#include "Fase.h"

class FaseNoturna3 : public Fase
{
private:
	sf::View view;

public:
	FaseNoturna3(sf::Vector2f tam, Lemurya* jogo);
	~FaseNoturna3();

	void draw();
	void input();
	void update();
	void inicializar();

	void carregarPause();
	void carregarMorte();

	void Draw(sf::RenderWindow& window);
	void executar();

	void recuperarJogo();
	void gravarJogo();
};



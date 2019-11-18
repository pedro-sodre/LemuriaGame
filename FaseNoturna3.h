#pragma once
#include "Fase.h"

class FaseNoturna3 : public Fase
{
private:
	sf::View view;
	float spawnInimigo;
public:
	FaseNoturna3(sf::Vector2f tam, Lemurya* jogo, bool newGame = true, bool player2 = false, int pont = 0);
	~FaseNoturna3();

	void draw();
	void input();
	void update();
	void inicializar(bool player2 = false);
	void carregar(bool player2 = false);

    void Draw(sf::RenderWindow& window);
    void executar();

	void carregarPause();
	void carregarMorte();
    void carregarProxFase();

    void gerarInimigos();
	void gerarObstaculos();

    void recuperarJogo(bool player2 = false);
    void novoJogo(bool player2 = false);
    void gravarJogo();
};



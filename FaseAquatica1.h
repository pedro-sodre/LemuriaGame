#pragma once
#include "Fase.h"

class FaseAquatica1: public Fase
{
private:
	sf::View view;
	float spawnInimigo;
public:
    FaseAquatica1(sf::Vector2f tam, Lemurya* jogo, bool newGame = true, bool player2 = false);
    ~FaseAquatica1();

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

    void checkFimDaFase();
	void checkSalvarJogo();
    void checkPlayerVivo();

	void gerarInimigos();
	void gerarObstaculos();

    void recuperarJogo(bool player2 = false);
    void novoJogo(bool player2 = false);
    void gravarJogo();

};


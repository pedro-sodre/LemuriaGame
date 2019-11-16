#pragma once
#include "State.h"
#include "Entidade.h"
#include "Lemurya.h"

class MenuMorte :
	public State, public Entidade
{
private:
	int selectedItem;
	int num_de_itens;
	Lemurya* jogo;

	sf::Font font;
	sf::Font font2;
	sf::Text menu[2];
	sf::Color cor1;
	sf::Color cor2;
	sf::Text tituloDoJogo;
	sf::Texture textura1;
	sf::RectangleShape* body; //O body virá do entidade depois
	
	sf::Event event;
	sf::View viewMenu;
public:
	MenuMorte(Lemurya* jogo);
	~MenuMorte();
	//Métodos de Entidade
	void executar(float deltaTime);
	//void executar();
	void destruir();
	void Draw(sf::RenderWindow& window);
	//Métodos de State
	void draw();
	void input();
	void update();

	void inicializar();

	void MoveUp();
	void MoveDown();
	int getPressedItem();
};


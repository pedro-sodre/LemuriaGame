#pragma once
#include "State.h"
#include "Entidade.h"
#include "Lemurya.h"
 
class MenuPause :
	public State, public Entidade
{
	private:
		int selectedItem;
		int num_de_itens;
		Lemurya* jogo;

		sf::Font font;
		sf::Font font2;
		sf::Text menu[MAX_NUMBER_ITEMS];
		sf::Color cor1;
		sf::Color cor2;
		sf::Text tituloDoJogo;
		sf::Texture textura1;
		sf::RectangleShape LogoDoJogo;
		sf::RectangleShape* body; //O body virá do entidade depois
		sf::View viewMenu;
		sf::Event event;
	public:
		MenuPause(Lemurya* jogo);
		~MenuPause();
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
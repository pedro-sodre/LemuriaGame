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
		sf::RectangleShape* body; //O body vir� do entidade depois
		sf::View viewMenu;
		sf::Event event;
	public:
		MenuPause(Lemurya* jogo);
		~MenuPause();
		//M�todos de Entidade
		void executar(float deltaTime);
		//void executar();
		void destruir();
		void Draw(sf::RenderWindow& window);
		//M�todos de State
		void draw();
		void input();
		void update();

		void inicializar();

		void MoveUp();
		void MoveDown();
		int getPressedItem();
};
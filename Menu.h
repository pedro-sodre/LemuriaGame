#pragma once
#include <SFML/Audio.hpp>
#include "Entidade.h"
#include "Lemurya.h"
#include "State.h"
#define MAX_NUMBER_ITEMS 4

class Lemurya;
class Menu: public Entidade, public State
{
	private:
		int selectedItem;
		Lemurya* jogo;

		sf::Font font;
		sf::Font font2;
		sf::Text menu[MAX_NUMBER_ITEMS];
		sf::Color cor1;
		sf::Color cor2;
		sf::Text tituloDoJogo;
		sf::Texture textura1;
		sf::RectangleShape LogoDoJogo;
		sf::RectangleShape* body;
		sf::Music musicaMenu;


	public:
		Menu(Lemurya* jogo);
		~Menu();
		//M�todos de Entidade
		void executar(float deltaTime);
		void executar();
		void destruir();
		void Draw(sf::RenderWindow& window);
		//M�todos de State
		void draw();
		void input();
		void update();

		void carregarJogo();

		void MoveUp();
		void MoveDown();
		int getPressedItem();
		void stopMusic();

		

	
};

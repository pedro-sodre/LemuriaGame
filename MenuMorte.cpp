#include "MenuMorte.h"
#include "MenuPause.h"
#include "FaseAquatica1.h"
MenuMorte::MenuMorte(Lemurya* jogo)
{
	this->jogo = jogo;
	this->inicializar();
}

MenuMorte::~MenuMorte()
{
	destruir();
}

void MenuMorte::executar(float deltaTime)
{
}

void MenuMorte::destruir()
{
	delete body;
}

void MenuMorte::Draw(sf::RenderWindow& window)
{
}

void MenuMorte::draw()
{
	jogo->window.draw(*body);
	jogo->window.draw(tituloDoJogo);
	int i;
	for (i = 0; i < 2; i++) {

		jogo->window.draw(menu[i]);
	}
}

void MenuMorte::input()
{
	while (jogo->window.pollEvent(event))
	{
		switch (event.type)
		{
			/* Fecha a Janela */
		case sf::Event::Closed:
			jogo->window.close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				jogo->window.close();
			else if (event.key.code == sf::Keyboard::Up) {
				this->MoveUp();
				printf("Item Selecionado: %d \n", getPressedItem());
			}
			else if (event.key.code == sf::Keyboard::Down) {
				this->MoveDown();
				printf("Item Selecionado: %d \n", getPressedItem());
			}
			else if (event.key.code == sf::Keyboard::W) {
				this->MoveUp();
				printf("Item Selecionado: %d \n", getPressedItem());
			}
			else if (event.key.code == sf::Keyboard::S) {
				this->MoveDown();
				printf("Item Selecionado: %d \n", getPressedItem());
			}
			else if (event.key.code == sf::Keyboard::Enter) {
				switch (getPressedItem())
				{
				case 0:
					/*State * ultimoState;
					while (!jogo->stateAtual()) {
						ultimoState = jogo->stateAtual();
						jogo->popState();
					}
					jogo->pushState(ultimoState);*/
					jogo->popState();
					jogo->popState();
					break;
				case 1:
					jogo->window.close();
					break;
				}
			}
			break;

		}
	}
}

void MenuMorte::update()
{
	jogo->window.setView(viewMenu);
}

void MenuMorte::inicializar()
{
	viewMenu.setSize(jogo->window.getSize().x, jogo->window.getSize().y);
	viewMenu.setCenter(jogo->window.getSize().x / 2, jogo->window.getSize().y / 2);
	if (!font.loadFromFile("data/BlackCastleMF.ttf"))
		printf("Fonte Não Carregou");

	if (!font2.loadFromFile("data/game_over.ttf"))
		printf("Fonte Não Carregou");

	if (!texture.loadFromFile("data/FundoGameOver.png"))
		printf("Erro ao carregar a textura do Menu");

	//Define a cor do texto
	cor1.r = 6;
	cor1.g = 59;
	cor1.b = 255;

	//Define a cor do título
	cor2.r = 1;
	cor2.g = 8;
	cor2.b = 34;


	//Opções do Menu
	menu[0].setFont(font);
	menu[0].setString("Voltar ao Menu");
	menu[0].setFillColor(cor1);
	menu[0].setStyle(sf::Text::Style::Bold);
	menu[0].setPosition(sf::Vector2f(jogo->window.getSize().x -400.0, 500.0));

	menu[1].setFont(font);
	menu[1].setString("Sair");
	menu[1].setFillColor(sf::Color::White);
	//menu[1].setStyle(sf::Text::Style::Bold);
	menu[1].setPosition(sf::Vector2f(jogo->window.getSize().x -400.0, 600.0));

	tituloDoJogo.setFont(font2);
	tituloDoJogo.setString("GAME OVER");
	tituloDoJogo.setFillColor(cor2);
	//tituloDoJogo.setStyle(sf::Text::Style::Bold);
	tituloDoJogo.setPosition(sf::Vector2f(jogo->window.getSize().x / 2 - 300, -100.0));

	tituloDoJogo.setCharacterSize(300);

	body = new sf::RectangleShape();
	body->setTexture(&texture);
	body->setSize(sf::Vector2f(jogo->window.getSize().x, jogo->window.getSize().y));
	body->setPosition(body->getSize() / 2.0f);
	body->setOrigin(body->getSize() / 2.0f);

	selectedItem = 0;
}
void MenuMorte::MoveUp()
{
	if (selectedItem - 1 >= 0)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		menu[selectedItem].setStyle(sf::Text::Style::Regular);
		selectedItem--;
		menu[selectedItem].setFillColor(cor1);
		menu[selectedItem].setStyle(sf::Text::Style::Bold);
	}
}

void MenuMorte::MoveDown()
{
	if (selectedItem + 1 < 2)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		menu[selectedItem].setStyle(sf::Text::Style::Regular);
		selectedItem++;

		menu[selectedItem].setStyle(sf::Text::Style::Bold);
		menu[selectedItem].setFillColor(cor1);
	}
}


int MenuMorte::getPressedItem()
{
	return selectedItem;
}
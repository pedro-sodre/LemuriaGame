#include "MenuPause.h"
#include "FaseAquatica1.h"
MenuPause::MenuPause(Lemurya* jogo)
{
	this->jogo = jogo;
	this->inicializar();
}

MenuPause::~MenuPause()
{
	destruir();
}

void MenuPause::executar(float deltaTime)
{
}

void MenuPause::destruir()
{
	delete body;
}

void MenuPause::Draw(sf::RenderWindow& window)
{
}

void MenuPause::draw()
{
	jogo->window.draw(*body);
	jogo->window.draw(tituloDoJogo);
	jogo->window.draw(LogoDoJogo);
	int i;
	for (i = 0; i < MAX_NUMBER_ITEMS; i++) {

		jogo->window.draw(menu[i]);
	}
}

void MenuPause::input()
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
					printf("Deu Resume");
					jogo->popState();
					printf("Passou do pop");
					break;
				case 1:
					//Salvar Jogo
					break;
				case 2:
					voltarAoMenu();
					//jogo->popState();
					
					//jogo->popState();
					break;
				case 3:
					jogo->window.close();
					break;
				}
			}
			break;

		}
	}
}

void MenuPause::update()
{
}

void MenuPause::inicializar()
{
	if (!font.loadFromFile("data/BlackCastleMF.ttf"))
		printf("Fonte Não Carregou");

	if (!font2.loadFromFile("data/Audiowide.ttf"))
		printf("Fonte Não Carregou");
	//if (jogo->stateAtual()== FaseAquatica1)
	if (!texture.loadFromFile("data/Pause.jpg"))
		printf("Erro ao carregar a textura do Menu");

	if (!textura1.loadFromFile("data/LemuryaIcon.jpg"))
		printf("Erro ao carregar a do Logo");

	num_de_itens = MAX_NUMBER_ITEMS;
	//Define a cor do texto
	cor1.r = 6;
	cor1.g = 59;
	cor1.b = 255;

	//Define a cor do título
	cor2.r = 6;
	cor2.g = 59;
	cor2.b = 103;


	//Opções do Menu
	menu[0].setFont(font);
	menu[0].setString("Resume");
	menu[0].setFillColor(cor1);
	menu[0].setStyle(sf::Text::Style::Bold);
	menu[0].setPosition(sf::Vector2f(jogo->window.getSize().x / 2 - 40.0, 400.0));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Save Game");
	menu[1].setPosition(sf::Vector2f(jogo->window.getSize().x / 2 - 40.0, 460.0));

	menu[2].setFont(font);
	menu[2].setString("Main Menu");
	menu[2].setFillColor(sf::Color::White);
	menu[2].setPosition(sf::Vector2f(jogo->window.getSize().x / 2 - 40.0, 520.0));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Exit");
	menu[3].setPosition(sf::Vector2f(jogo->window.getSize().x / 2 - 40.0, 580.0));

	tituloDoJogo.setFont(font2);
	tituloDoJogo.setString("PAUSE");
	tituloDoJogo.setFillColor(cor2);
	//tituloDoJogo.setStyle(sf::Text::Style::Bold);
	tituloDoJogo.setPosition(sf::Vector2f(jogo->window.getSize().x / 2 - 200, 250.0));

	tituloDoJogo.setCharacterSize(80);

	LogoDoJogo.setSize(sf::Vector2f(200.0f, 200.0f));
	LogoDoJogo.setPosition(sf::Vector2f(jogo->window.getSize().x / 2 - 65, 50.0f));
	LogoDoJogo.setTexture(&textura1);

	body = new sf::RectangleShape();
	body->setTexture(&texture);
	body->setSize(sf::Vector2f(jogo->window.getSize().x, jogo->window.getSize().y));
	body->setPosition(body->getSize() / 2.0f);
	body->setOrigin(body->getSize() / 2.0f);

	selectedItem = 0;
}

void MenuPause::voltarAoMenu()
{
	jogo->pushState(new Menu(jogo));
}

void MenuPause::voltarAFase()
{
	jogo->pushState(new FaseAquatica1(sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT), jogo));
}

void MenuPause::MoveUp()
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

void MenuPause::MoveDown()
{
	if (selectedItem + 1 < num_de_itens)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		menu[selectedItem].setStyle(sf::Text::Style::Regular);
		selectedItem++;

		menu[selectedItem].setStyle(sf::Text::Style::Bold);
		menu[selectedItem].setFillColor(cor1);
	}
}

int MenuPause::getPressedItem()
{
	return selectedItem;
}
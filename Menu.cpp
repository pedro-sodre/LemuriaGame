#include "Menu.h"
Menu::Menu(Lemurya* jogo): Entidade(), State()
{

	this->jogo = jogo;

}
Menu::~Menu()
{
}

void Menu::destruir()
{
	delete body;
}

void Menu::Draw(sf::RenderWindow& window)
{
}

void Menu::draw()
{
	if (!font.loadFromFile("data/BlackCastleMF.ttf"))
		printf("Fonte Não Carregou");

	if (!font2.loadFromFile("data/Audiowide.ttf"))
		printf("Fonte Não Carregou");

	if (!texture.loadFromFile("data/Menu.jpg"))
		printf("Erro ao carregar a textura do Menu");

	if (!textura1.loadFromFile("data/LemuryaIcon.jpg"))
		printf("Erro ao carregar a do Logo");

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
	menu[0].setString("New Game");
	menu[0].setFillColor(cor1);
	menu[0].setStyle(sf::Text::Style::Bold);
	menu[0].setPosition(sf::Vector2f(jogo->window.getSize().x / 2 - 40.0, 400.0));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Load Game");
	menu[1].setPosition(sf::Vector2f(jogo->window.getSize().x / 2 - 40.0, 460.0));

	menu[2].setFont(font);
	menu[2].setString("Ranking");
	menu[2].setFillColor(sf::Color::White);
	menu[2].setPosition(sf::Vector2f(jogo->window.getSize().x / 2 - 40.0, 520.0));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Exit");
	menu[3].setPosition(sf::Vector2f(jogo->window.getSize().x / 2 - 40.0, 580.0));

	tituloDoJogo.setFont(font2);
	tituloDoJogo.setString("LEMURYA");
	tituloDoJogo.setFillColor(cor2);
	//tituloDoJogo.setStyle(sf::Text::Style::Bold);
	tituloDoJogo.setPosition(sf::Vector2f(jogo->window.getSize().x / 2 - 200, 250.0));

	tituloDoJogo.setCharacterSize(80);

	LogoDoJogo.setSize(sf::Vector2f(200.0f, 200.0f));
	LogoDoJogo.setPosition(sf::Vector2f(jogo->window.getSize().x / 2 - 65, 50.0f));
	LogoDoJogo.setTexture(&textura1);

	musicaMenu.openFromFile("data/MusicaMenu.wav");
	musicaMenu.setLoop(true);
	///musicaMenu.play();

	body = new sf::RectangleShape();
	body->setTexture(&texture);
	body->setSize(sf::Vector2f(jogo->window.getSize().x, jogo->window.getSize().y));
	body->setPosition(body->getSize() / 2.0f);
	body->setOrigin(body->getSize() / 2.0f);
	selectedItem = 0;
	this->executar();
	int i;
    jogo->window.draw(*body);
	jogo->window.draw(tituloDoJogo);
	jogo->window.draw(LogoDoJogo);
	for (i = 0; i < MAX_NUMBER_ITEMS; i++) {

		jogo->window.draw(menu[i]);
	}


}
void Menu::input()
{
	sf::Event event;

	while (jogo->window.pollEvent(event))
	{
		switch (event.type)
		{
			/* Fecha a Janela */
		case sf::Event::Closed:
			jogo->window.close();
			break;

			/* Mudança entre estados do jogo */
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				jogo->window.close();
			else if (event.key.code == sf::Keyboard::Up)
				this->MoveUp();
			else if (event.key.code == sf::Keyboard::Down)
				this->MoveDown();
			else if (event.key.code == sf::Keyboard::Enter)
				switch (this->getPressedItem())
				{
				case 0:
					musicaMenu.stop();
					//carregarJogo();
					break;
				case 1:
					//carregarLoadGame();
					break;
				case 2:
					//carregarRanking();
					break;
				case 3:
					break;
				}
			break;


		}
	}
}
void Menu::update()
{
}
void Menu::carregarJogo()
{
	//jogo->pushState(new FaseAquatica1(jogo));
}
void Menu::MoveUp()
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
void Menu::MoveDown()
{
	if (selectedItem + 1 < MAX_NUMBER_ITEMS)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		menu[selectedItem].setStyle(sf::Text::Style::Regular);
		selectedItem++;
		menu[selectedItem].setFillColor(cor1);
		menu[selectedItem].setStyle(sf::Text::Style::Bold);
	}

}
void Menu::executar(float deltaTime)
{
}
void Menu::executar()
{
	sf::Image icon;
	icon.loadFromFile("data/LemuryaIcon.JPG");
	sf::RenderWindow windowMenu(sf::VideoMode(1280.0f, 720.0f), "Lemurya");
	windowMenu.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	while (windowMenu.isOpen())
	{
		sf::Event eventMenu;
		while (windowMenu.pollEvent(eventMenu))
		{
			switch (eventMenu.type)
			{
			case sf::Event::KeyReleased:
				switch (eventMenu.key.code)
				{
				case sf::Keyboard::Up:
					this->MoveUp();
					break;
				case sf::Keyboard::Down:
					this->MoveDown();
					break;
				case sf::Keyboard::W:
					this->MoveUp();
					break;
				case sf::Keyboard::S:
					this->MoveDown();
					break;
				case sf::Keyboard::Return:
					switch (this->getPressedItem())
					{
					case 0:
						this->stopMusic();
						windowMenu.close();
						//musicaFundo.play();
						break;
					case 1:
						//
						break;
					case 2:
						windowMenu.close();
						break;
					}
				}
				break;
			case sf::Event::Closed:
				windowMenu.close();
				break;
			}
		}
		windowMenu.clear();
		this->Draw(windowMenu);
		windowMenu.display();
	}
}
int Menu::getPressedItem()
{
	return selectedItem;

}

void Menu::stopMusic()
{
    musicaMenu.stop();
}

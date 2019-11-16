#include "MenuPrincipal.h"
#include "FaseAquatica1.h"

MenuPrincipal::MenuPrincipal(Lemurya* jogo):
Menu(jogo)
{
    newGame = false;
	this->jogo = jogo;
	this->inicializar();
}
MenuPrincipal::~MenuPrincipal()
{
}

void MenuPrincipal::draw()
{
    jogo->window.draw(*body);
	jogo->window.draw(tituloDoJogo);
	jogo->window.draw(LogoDoJogo);
	int i;
	for (i = 0; i < MAX_NUMBER_ITEMS; i++) {

		jogo->window.draw(menu[i]);
	}


}
void MenuPrincipal::input()
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
			}
			else if (event.key.code == sf::Keyboard::Down) {
				this->MoveDown();
			}
			else if (event.key.code == sf::Keyboard::W) {
				this->MoveUp();
			}
			else if (event.key.code == sf::Keyboard::S) {
				this->MoveDown();
			}
			else if (event.key.code == sf::Keyboard::Enter) {
				//Verifica se o submenu est� ativo
				if (getPressedItem() == 0 && escolhaDeJogadores)
				{
				    jogo->setP2(false);
					musicaMenu.stop();
					carregarJogo();
				}
				else if (getPressedItem() == 1 && escolhaDeJogadores)
				{
				    jogo->setP2(true);
					musicaMenu.stop();
					carregarJogo();
				}
				else if (getPressedItem() == 2 && escolhaDeJogadores)
				{
					this->inicializar();
				}
				//Verifica do menu Principal
				else if (getPressedItem() == 0)
				{
				    newGame = true;
					abrirEscolhaDeJogadores();
				}
				else if (getPressedItem() == 1)
				{
				    newGame = false;
                    musicaMenu.stop();
					carregarJogo();
				}
				else if (getPressedItem() == 2)
				{
					//abre o ranking
				}
				else if (getPressedItem() == 3)
				{
					jogo->window.close();
				}

			}
			break;

		}
	}
}

void MenuPrincipal::update()
{
    jogo->window.setView(viewMenu);
}

void MenuPrincipal::inicializar()
{
    viewMenu.setSize(jogo->window.getSize().x, jogo->window.getSize().y);
    viewMenu.setCenter(jogo->window.getSize().x/2, jogo->window.getSize().y/2);

    font    = jogo->getGerenciadorGrafico().getFontBlackCastle();
	font2   = jogo->getGerenciadorGrafico().getFontAudiowide();
    texture = jogo->getGerenciadorGrafico().getMenuPrincipalTexture();
    textura1 = jogo->getGerenciadorGrafico().getLogoTexture();

	escolhaDeJogadores = false;

	num_de_itens = MAX_NUMBER_ITEMS;
	//Define a cor do texto
	cor1.r = 6;
	cor1.g = 59;
	cor1.b = 255;

	//Define a cor do t�tulo
	cor2.r = 6;
	cor2.g = 59;
	cor2.b = 103;


	//Op��es do Menu
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
	musicaMenu.play();

	body = new sf::RectangleShape();
	body->setTexture(&texture);
	body->setSize(sf::Vector2f(jogo->window.getSize().x, jogo->window.getSize().y));
	body->setPosition(body->getSize() / 2.0f);
	body->setOrigin(body->getSize() / 2.0f);

	selectedItem = 0;
}
void MenuPrincipal::carregarJogo()
{
	//Coloca a Fase na pilha
	jogo->pushState(new FaseAquatica1(sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT), jogo, newGame, jogo->getP2()));
}
void MenuPrincipal::abrirEscolhaDeJogadores()
{
	escolhaDeJogadores = true;
	num_de_itens = 3;
	tituloDoJogo.setFont(font);
	tituloDoJogo.setString("Selecionar n�mero de jogadores");
	tituloDoJogo.setCharacterSize(40);
	tituloDoJogo.setPosition(sf::Vector2f(jogo->window.getSize().x / 2 - 200, 300.0));
	tituloDoJogo.setFillColor(sf::Color::White);

	menu[0].setString("1 Jogador");
	menu[1].setString("2 Jogadores");
	menu[2].setString("Voltar");
	menu[3].setString("");

}

void MenuPrincipal::stopMusic()
{
    musicaMenu.stop();
}


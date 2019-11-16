#include "FaseNoturna3.h"
#include "Lemurya.h"
#include "MenuMorte.h"
#include "MenuPause.h"

FaseNoturna3::FaseNoturna3(sf::Vector2f tam, Lemurya* jogo) :
	Fase(tam, jogo)
{
	if (!texture.loadFromFile("data/Fase3.png"))
		std::cout << "Erro ao carregar a textura da FaseNoturna3" << std::endl;

	body->setTexture(&texture);
	this->executar();
}

FaseNoturna3::~FaseNoturna3()
{

}
void FaseNoturna3::draw()
{
	jogo->window.draw(*body);
	gerenciadorDePontuacao.draw();
	Lentidades.Draw(jogo->window);
}

void FaseNoturna3::input()
{
	sf::Event event;

	while (jogo->window.pollEvent(event))
	{
		switch (event.type)
		{
			/* Se Sair da Janela Vai pro Pause*/
		case sf::Event::LostFocus:
			carregarPause();
			break;
			/* Fecha a Janela */
		case sf::Event::Closed:
			jogo->window.close();
			break;

			/* Mudan�a entre estados do jogo */
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				carregarPause();
			break;


		}
	}
}

void FaseNoturna3::update()
{
	///UPDATE NA VIEW
	view.setCenter(jogo->getPlayer1()->getPosition().x, 200.0f);
	jogo->window.setView(view);
	///UPDATE BACKGROUND
	this->getBody()->setPosition(jogo->getPlayer1()->getPosition().x, 200.0f);

	gerenciadorDePontuacao.executar();

	///GERENCIA COLIS�ES
	gerenciadorDeColisoes.executar();
	///EXECUTA
	Lentidades.executar(jogo->deltaTime);

	///VERIFICA SE PLAYER EST� VIVO PARA PASSAR PARA O PR�XIMO FRAME
	if (!jogo->getPlayer1()->estaVivo())
	{
		jogo->pushState(new MenuMorte(jogo));
	}
	if (jogo->getPlayer1()->getPosition().x > 4000.0f) {

	}
	///GRAVA O JOGO (TIRAR DAQUI NA VERS�O FINAL)
	Lentidades.gravarJogo();
}

void FaseNoturna3::inicializar()
{
	recuperarJogo();
	gerenciadorDeColisoes.inicializa((jogo->getPlayer1()), &Lplataformas, &Lobstaculos, &Linimigos, &Lentidades, &Lprojeteis);
	gerenciadorDePontuacao.inicializa(jogo);

	view.setCenter(sf::Vector2f(0, 0));
	view.setSize(sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
}

void FaseNoturna3::carregarPause()
{
	jogo->pushState(new MenuPause(jogo));
}

void FaseNoturna3::carregarMorte()
{
	jogo->pushState(new MenuMorte(jogo));
}


void FaseNoturna3::Draw(sf::RenderWindow& window)
{
	window.draw(*body);
}

void FaseNoturna3::executar()
{
}

void FaseNoturna3::gravarJogo()
{
	ofstream Gravador("data/Fase3Gravando.txt", ios::out);

	if (!Gravador)
	{
		cerr << "Arquivo n�o pode ser aberto" << endl;
		fflush(stdin);
		getchar();
		return;
	}

	for (Entidade* aux = Lentidades.reiniciar(); aux != NULL; aux = Lentidades.percorrer())
	{
		Gravador << aux->getID() << " "
			<< aux->getX() << " "
			<< aux->getY() << endl;
	}

	Gravador.close();
}

void FaseNoturna3::recuperarJogo()
{

	ifstream Recuperador("data/Fase3Base.txt", ios::in);
	if (!Recuperador)
	{
		cerr << "Arquivo n�o pode ser aberto" << endl;
		fflush(stdin);
		getchar();
		return;
	}

	while (!Recuperador.eof())
	{
		int ID;
		float x, y;
		Recuperador >> ID >> x >> y;

		switch (ID)
		{
		case 1:
			Lplataformas.incluir(prototype.MakeChao(x, y));
			break;
		case 2:
			Lplataformas.incluir(prototype.MakePlataforma(x, y));
			break;
		case 3:
			Lobstaculos.incluir(static_cast<Obstaculo*> (prototype.MakeCaixa(x, y)));
			break;
		case 4:
			Lobstaculos.incluir(static_cast<Obstaculo*> (prototype.MakePedra(x, y)));
			break;
		case 5:
			Lobstaculos.incluir(static_cast<Obstaculo*> (prototype.MakePedra2(x, y)));
			break;
		case 6:
			Linimigos.incluir(static_cast<Inimigo*> (prototype.MakeEsqueleto(x, y)));
			break;
		case 7:
			Linimigos.incluir(static_cast<Inimigo*> (prototype.MakeMago(x, y)));
			break;
		case 8:
			Linimigos.incluir(static_cast<Inimigo*> (prototype.MakeTritao(x, y)));
			break;
		case 9:
			jogo->getPlayer1()->getBody()->setPosition(x, y);
			///PLAYER
			break;
		case 10:
			Lprojeteis.incluir(prototype.MakeBolaDeFogo(x, y));
			break;
		}
	}

	for (int i = 0; i < Lobstaculos.getLTObstaculos().size(); i++)
		Lentidades.incluir(static_cast<Entidade*> ((Lobstaculos.getLTObstaculos()[i])));

	for (int i = 0; i < Linimigos.getLTInimigos().size(); i++)
		Lentidades.incluir(static_cast<Entidade*> ((Linimigos.getLTInimigos()[i])));

	for (int i = 0; i < Lprojeteis.getLTProjeteis().size(); i++)
		Lentidades.incluir(static_cast<Entidade*> ((Lprojeteis.getLTProjeteis()[i])));

	for (Platform* aux = Lplataformas.reiniciar(); aux != NULL; aux = Lplataformas.percorrer())
		Lentidades.incluir(static_cast<Entidade*> (aux));

	Lentidades.incluir(static_cast<Entidade*> (jogo->getPlayer1()));

	Recuperador.close();
}


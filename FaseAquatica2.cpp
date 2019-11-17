#include "FaseAquatica2.h"
#include "Lemurya.h"
#include "MenuMorte.h"
#include "MenuPause.h"
#include "FaseNoturna3.h"

FaseAquatica2::FaseAquatica2(sf::Vector2f tam, Lemurya* jogo, bool newGame, bool player2):
Fase(tam, jogo)
{
	texture = jogo->getGerenciadorGrafico().getFase2Texture();
    body->setTexture(&texture);

    musicaFundo.openFromFile("data/MusicaFundo.wav");
    musicaFundo.setLoop(true);

    if(newGame)
        inicializar(player2);
    else
        carregar(player2);
}

FaseAquatica2::~FaseAquatica2()
{

}

void FaseAquatica2::draw()
{
	jogo->window.draw(*body);
	gerenciadorDePontuacao.draw();
	Lentidades.Draw(jogo->window);
}

void FaseAquatica2::input()
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

			/* Mudança entre estados do jogo */
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				carregarPause();
			break;


		}
	}
}

void FaseAquatica2::update()
{
	///UPDATE NA VIEW
	view.setCenter(jogo->getPlayer1()->getPosition().x, 200.0f);
	jogo->window.setView(view);
	///UPDATE BACKGROUND
	this->getBody()->setPosition(jogo->getPlayer1()->getPosition().x, 200.0f);

	gerenciadorDePontuacao.executar();

	///GERENCIA COLISÕES
	gerenciadorDeColisoes.executar();
	///EXECUTA
	Lentidades.executar(jogo->deltaTime);

	///VERIFICA SE PLAYER ESTÁ VIVO PARA PASSAR PARA O PRÓXIMO FRAME
	if (!jogo->getPlayer1()->estaVivo())
	{
		jogo->pushState(new MenuMorte(jogo));
	}
	if (jogo->getPlayer1()->getPosition().x > 4000.0f)
    {
		carregarProxFase();
	}
	///GRAVA O JOGO (TIRAR DAQUI NA VERSÃO FINAL)
	Lentidades.gravarJogo();
}

void FaseAquatica2::inicializar(bool player2)
{
	novoJogo(player2);
    gerenciadorDeColisoes.inicializa((jogo->getPlayer1()), jogo->getPlayer2(), &Lplataformas, &Lobstaculos, &Linimigos, &Lentidades, &Lprojeteis);
    gerenciadorDePontuacao.inicializa(jogo);

	view.setCenter(sf::Vector2f(0, 0));
	view.setSize(sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
}

void FaseAquatica2::carregar(bool player2)
{
	recuperarJogo(player2);
    gerenciadorDeColisoes.inicializa((jogo->getPlayer1()), jogo->getPlayer2(), &Lplataformas, &Lobstaculos, &Linimigos, &Lentidades, &Lprojeteis);
    gerenciadorDePontuacao.inicializa(jogo);

	view.setCenter(sf::Vector2f(0, 0));
	view.setSize(sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
}

void FaseAquatica2::Draw(sf::RenderWindow& window)
{
    window.draw(*body);
}

void FaseAquatica2::executar()
{
	/*
    ///INICIALIZA JANELA
    sf::RenderWindow window(sf::VideoMode(1280.0f, 720.0f), "Lemurya");

	///COLOCA OS ÍCONES
	sf::Image icon;
	icon.loadFromFile("data/LemuryaIcon.JPG");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    sf::View view(sf::Vector2f(0,0), sf::Vector2f(VIEW_HEIGHT,VIEW_HEIGHT));

    ///CARREGA O MAPA
    recuperarJogo();

    ///CRIA GERENCIADOR DE COLISÕES
    GerenciadorDeColisoes gerenciadorDeColisoes(jogo->getPlayer1(), jogo->getPlayer2(), &Lplataformas, &Lobstaculos, &Linimigos, &Lentidades, &Lprojeteis);

    ///CLOCK DO JOGO
    float deltaTime = 0.0f;
    sf::Clock clock;

    ///JANELA JOGO
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        if(deltaTime > 1.0f / 20.0f)
            deltaTime = 1.0f / 20.0f;

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        ///SETA AS COISAS DA JANELA
        view.setCenter(jogo->getPlayer1()->getPosition().x, 200.0f);
        window.clear();       //LIMPA BUFFER
        window.setView(view);
        this->getBody()->setPosition(jogo->getPlayer1()->getPosition().x, 200.0f );
        this->Draw(window);

        ///GERENCIA COLISÕES
        gerenciadorDeColisoes.executar();

        ///EXECUTA E DESENHA
        Lentidades.executar(deltaTime);
        Lentidades.Draw(window);

        ///VERIFICA SE PLAYER ESTÁ VIVO PARA PASSAR PARA O PRÓXIMO FRAME
        if(!jogo->getPlayer1()->estaVivo())
        {
            break;
            printf("VOCE MORREU\n");
            ///VOLTA PRO MENU
        }

        ///SALVA O JOGO
        Lentidades.gravarJogo();
     ///gravarJogo(Lentidades);              POR ALGUM MOTIVO NÃO FUNCIONA
        window.display();
    }*/
}

void FaseAquatica2::carregarPause()
{
	jogo->pushState(new MenuPause(jogo));
}

void FaseAquatica2::carregarMorte()
{
	jogo->pushState(new MenuMorte(jogo));
}

void FaseAquatica2::carregarProxFase()
{
	jogo->popState();
	//jogo->pushState(new FaseNoturna3(sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT), jogo));
}

void FaseAquatica2::gravarJogo()
{
    ofstream Gravador("data/Fase2Gravando.txt", ios::out);

    if ( !Gravador )
    {
        cerr << "Arquivo não pode ser aberto" << endl;
        fflush ( stdin );
        getchar ( );
        return;
    }

    for(Entidade* aux = Lentidades.reiniciar(); aux != NULL; aux = Lentidades.percorrer())
    {
        Gravador    << aux->getID() << " "
                    << aux->getX() << " "
                    << aux->getY() << endl;
    }

    Gravador.close();
}

void FaseAquatica2::recuperarJogo(bool player2)
{

    ifstream Recuperador("data/Fase2Gravando.txt", ios::in);
    if ( !Recuperador )
    {
        cerr << "Arquivo não pode ser aberto" << endl;
        fflush ( stdin );
        getchar ( );
        return;
    }

    while(!Recuperador.eof())
    {
        int ID;
        float x, y;
        Recuperador >> ID >> x >> y;

        switch(ID)
        {
            case 1:
                Lplataformas.incluir(prototype.MakeChao(x,y));
                break;
            case 2:
                Lplataformas.incluir(prototype.MakePlataforma(x,y));
                break;
            case 3:
                Lobstaculos.incluir(static_cast<Obstaculo*> (prototype.MakeCaixa(x,y)));
                break;
            case 4:
                Lobstaculos.incluir(static_cast<Obstaculo*> (prototype.MakePedra(x,y)));
                break;
            case 5:
                Lobstaculos.incluir(static_cast<Obstaculo*> (prototype.MakePedra2(x,y)));
                break;
            case 6:
                Linimigos.incluir(static_cast<Inimigo*> (prototype.MakeEsqueleto(x,y)));
                break;
            case 7:
                Linimigos.incluir(static_cast<Inimigo*> (prototype.MakeMago(x,y)));
                break;
            case 8:
                Linimigos.incluir(static_cast<Inimigo*> (prototype.MakeTritao(x,y)));
                break;
            case 101:
                jogo->getPlayer1()->getBody()->setPosition(x,y);
                break;
            case 102:
                if(player2)
                    jogo->getPlayer2()->getBody()->setPosition(x,y);///PLAYER2
                break;
            case 10:
                Lprojeteis.incluir(prototype.MakeBolaDeFogo(x,y));
                break;
        }
    }

    for(int i=0; i < Lobstaculos.getLTObstaculos().size(); i++)
        Lentidades.incluir(static_cast<Entidade*> ((Lobstaculos.getLTObstaculos()[i])));

    for(int i=0; i < Linimigos.getLTInimigos().size(); i++)
        Lentidades.incluir(static_cast<Entidade*> ((Linimigos.getLTInimigos()[i])));

    for(int i=0; i < Lprojeteis.getLTProjeteis().size(); i++)
        Lentidades.incluir(static_cast<Entidade*> ((Lprojeteis.getLTProjeteis()[i])));

    for(Platform* aux = Lplataformas.reiniciar(); aux != NULL; aux = Lplataformas.percorrer())
        Lentidades.incluir(static_cast<Entidade*> (aux));

    Lentidades.incluir(static_cast<Entidade*> (jogo->getPlayer1()));

    if(player2)
    {
        Lentidades.incluir(static_cast<Entidade*> (jogo->getPlayer2()));///PLAYER2
    }

    Recuperador.close();
}

void FaseAquatica2::novoJogo(bool player2)
{

    ifstream Recuperador("data/Fase2Base.txt", ios::in);
    if ( !Recuperador )
    {
        cerr << "Arquivo não pode ser aberto" << endl;
        fflush ( stdin );
        getchar ( );
        return;
    }

    while(!Recuperador.eof())
    {
        int ID;
        float x, y;
        Recuperador >> ID >> x >> y;

        switch(ID)
        {
            case 1:
                Lplataformas.incluir(prototype.MakeChao(x,y));
                break;
            case 2:
                Lplataformas.incluir(prototype.MakePlataforma(x,y));
                break;
            case 3:
                Lobstaculos.incluir(static_cast<Obstaculo*> (prototype.MakeCaixa(x,y)));
                break;
            case 4:
                Lobstaculos.incluir(static_cast<Obstaculo*> (prototype.MakePedra(x,y)));
                break;
            case 5:
                Lobstaculos.incluir(static_cast<Obstaculo*> (prototype.MakePedra2(x,y)));
                break;
            case 6:
                Linimigos.incluir(static_cast<Inimigo*> (prototype.MakeEsqueleto(x,y)));
                break;
            case 7:
                Linimigos.incluir(static_cast<Inimigo*> (prototype.MakeMago(x,y)));
                break;
            case 8:
                Linimigos.incluir(static_cast<Inimigo*> (prototype.MakeTritao(x,y)));
                break;
            case 101:
                jogo->getPlayer1()->getBody()->setPosition(x,y);
                break;
            case 102:
                if(player2)
                    jogo->getPlayer2()->getBody()->setPosition(x,y);///PLAYER2
                break;
            case 10:
                Lprojeteis.incluir(prototype.MakeBolaDeFogo(x,y));
                break;
        }
    }

    for(int i=0; i < Lobstaculos.getLTObstaculos().size(); i++)
        Lentidades.incluir(static_cast<Entidade*> ((Lobstaculos.getLTObstaculos()[i])));

    for(int i=0; i < Linimigos.getLTInimigos().size(); i++)
        Lentidades.incluir(static_cast<Entidade*> ((Linimigos.getLTInimigos()[i])));

    for(int i=0; i < Lprojeteis.getLTProjeteis().size(); i++)
        Lentidades.incluir(static_cast<Entidade*> ((Lprojeteis.getLTProjeteis()[i])));

    for(Platform* aux = Lplataformas.reiniciar(); aux != NULL; aux = Lplataformas.percorrer())
        Lentidades.incluir(static_cast<Entidade*> (aux));

    Lentidades.incluir(static_cast<Entidade*> (jogo->getPlayer1()));

    if(player2)
    {
        Lentidades.incluir(static_cast<Entidade*> (jogo->getPlayer2()));///PLAYER2
    }

    Recuperador.close();
}


#include "FaseAquatica1.h"
#include "MenuPause.h"
#include "MenuMorte.h"

FaseAquatica1::FaseAquatica1(sf::Vector2f tam, Lemurya* jogo):
Fase(tam, jogo)
{
	texture = jogo->getGerenciadorGrafico().getFase1Texture();
    body->setTexture(&texture);

    musicaFundo.openFromFile("data/MusicaFundo.wav");
    musicaFundo.setLoop(true);

    inicializar();      ///AQUI??????

}

FaseAquatica1::~FaseAquatica1()
{

}

void FaseAquatica1::draw()
{
	jogo->window.draw(*body);
	gerenciadorDePontuacao.draw();
	Lentidades.Draw(jogo->window);
}

void FaseAquatica1::input()
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
				carregarPause();
			else if (event.key.code == sf::Keyboard::Up) {
				//Pulo do Player
			}
			else if (event.key.code == sf::Keyboard::Down) {

			}
			else if (event.key.code == sf::Keyboard::Enter) {

			}
			break;


		}
	}
}

void FaseAquatica1::update()
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
		printf("VOCE MORREU\n");
		///VOLTA PRO MENU
	}

	///GRAVA O JOGO (TIRAR DAQUI NA VERSÃO FINAL)
	Lentidades.gravarJogo();
}

void FaseAquatica1::inicializar()
{
	recuperarJogo();
    gerenciadorDeColisoes.inicializa((jogo->getPlayer1()), &Lplataformas, &Lobstaculos, &Linimigos, &Lentidades, &Lprojeteis);
    gerenciadorDePontuacao.inicializa(jogo);

	view.setCenter(sf::Vector2f(0, 0));
	view.setSize(sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
}

void FaseAquatica1::Draw(sf::RenderWindow& window)
{
    window.draw(*body);
}

void FaseAquatica1::executar()
{
    ///INICIALIZA JANELA
    //sf::RenderWindow window(sf::VideoMode(1280.0f, 720.0f), "Lemurya");

	///COLOCA OS ÍCONES
	/*sf::Image icon;
	icon.loadFromFile("data/LemuryaIcon.JPG");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    sf::View view(sf::Vector2f(0,0), sf::Vector2f(VIEW_HEIGHT,VIEW_HEIGHT));
	*/
    ///CARREGA O MAPA
    //recuperarJogo(Lentidades, Linimigos, Lobstaculos, Lplataformas, Lprojeteis, prototype, player1);

    ///CRIA GERENCIADOR DE COLISÕES
    //GerenciadorDeColisoes gerenciadorDeColisoes(&player1, &Lplataformas, &Lobstaculos, &Linimigos, &Lentidades, &Lprojeteis);

    ///CLOCK DO JOGO
   /* float deltaTime = 0.0f;
    sf::Clock clock;*/

    ///JANELA JOGO
    /*while (window.isOpen())
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
        }*/

        ///SETA AS COISAS DA JANELA
        /*view.setCenter(player1.getPosition().x, 200.0f);
        window.clear();       //LIMPA BUFFER
        window.setView(view);
        this->getBody()->setPosition(player1.getPosition().x, 200.0f );
        this->Draw(window);
		*/
        ///INICIALIZA RANKING
        /*sf::Text Rank;      //dando mensagens de erro qunado compiila
        sf::Font font1;     //
        if (!font1.loadFromFile("data/BlackCastleMF.ttf")) {
            printf("Fonte Não Carregou");
        }
        Rank.setFont(font1);

        stringstream pRank;
        pRank << "Pontuação: " << player1.ranking;
        string p1Rank = pRank.str();

        Rank.setString(p1Rank);
        Rank.setPosition(sf::Vector2f(player1.getPosition().x+300.0f, -300.0f));
        Rank.setCharacterSize(40);
        window.draw(Rank);
		*/
        ///GERENCIA COLISÕES
        //gerenciadorDeColisoes.executar();

        ///EXECUTA E DESENHA
        //Lentidades.executar(deltaTime);
        //Lentidades.Draw(window);

        ///VERIFICA SE PLAYER ESTÁ VIVO PARA PASSAR PARA O PRÓXIMO FRAME
        /*if(!player1.estaVivo())
        {
            break;
            printf("VOCE MORREU\n");
            ///VOLTA PRO MENU
        }*/

        ///SALVA O JOGO
        //Lentidades.gravarJogo();
     ///gravarJogo(Lentidades);              POR ALGUM MOTIVO NÃO FUNCIONA
        //window.display();
    //}
}

void FaseAquatica1::carregarPause()
{
	jogo->pushState(new MenuPause(jogo));
}

void FaseAquatica1::gravarJogo()
{
    ofstream Gravador("data/Fase1Gravando.txt", ios::out);

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

void FaseAquatica1::recuperarJogo()
{

    ifstream Recuperador("data/Fase1Base.txt", ios::in);
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
            case 9:
                jogo->getPlayer1()->getBody()->setPosition(x,y);
                ///PLAYER
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

    Recuperador.close();
}


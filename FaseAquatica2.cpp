#include "FaseAquatica2.h"
#include "Lemurya.h"
#include "MenuMorte.h"
#include "MenuPause.h"
#include "FaseNoturna3.h"

FaseAquatica2::FaseAquatica2(sf::Vector2f tam, Lemurya* jogo, bool newGame, bool player2, int pont):
Fase(tam, jogo)
{
	texture = jogo->getGerenciadorGrafico().getFase2Texture();
    body->setTexture(&texture);
    spawnInimigo = 0;

    musicaFundo.openFromFile("data/MusicaFundo.wav");
    musicaFundo.setLoop(true);
    //musicaFundo.play();

    jogo->setSalvarFase2(false);

    if(newGame)
        inicializar(player2);
    else
        carregar(player2);

    jogo->getPlayer1()->setRanking(pont);
}

FaseAquatica2::~FaseAquatica2()
{
    musicaFundo.stop();
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
    ///GERENCIA PONTUAÇÃO
    gerenciadorDePontuacao.executar();
	///GERENCIA COLISÕES
    gerenciadorDeColisoes.executar();
    ///SOMENTE TESTE, PODE SER FEITO NO PRÓPRIO EXECUTAR DO PLAYER, PORÉM, ACHO QUE DESSA FORMA FICA MAIS BONITO (QUANDO INCLUIR PLAYER2 DEVE FICAR MAIS FÁCIL FAZER PELO PLAYER)
    ///GERENCIA VIDA
    jogo->getPlayer1()->getLife()->setPosition(sf::Vector2f(jogo->getPlayer1()->getPosition().x - 430.0f, -300.0f));
    jogo->getPlayer1()->getDamage()->setPosition(sf::Vector2f(jogo->getPlayer1()->getPosition().x + std::max(0, (jogo->getPlayer1()->getVida()*20)) - 430.0f, -300.0f));
    jogo->getPlayer1()->getLifeIcon()->setPosition(sf::Vector2f(jogo->getPlayer1()->getPosition().x - 520.0f, -330.0f));

    jogo->getPlayer2()->getLife()->setPosition(sf::Vector2f(jogo->getPlayer1()->getPosition().x - 430.0f, -150.0f));
    jogo->getPlayer2()->getDamage()->setPosition(sf::Vector2f(jogo->getPlayer1()->getPosition().x + std::max(0, (jogo->getPlayer2()->getVida()*20)) - 430.0f, -150.0f));
    jogo->getPlayer2()->getLifeIcon()->setPosition(sf::Vector2f(jogo->getPlayer1()->getPosition().x - 520.0f, -180.0f));
    ///EXECUTA
	Lentidades.executar(jogo->deltaTime);

    ///SPAWN DE INIMIGOS
    spawnInimigo -= jogo->deltaTime;
    if(spawnInimigo <= 0)
        gerarInimigos();

	///VERIFICA SE PLAYER ESTÁ VIVO PARA PASSAR PARA O PRÓXIMO FRAME
	if (!jogo->getPlayer1()->estaVivo())
	{
		carregarMorte();
	}
    if (jogo->getPlayer1()->getPosition().x > 6000.0f)
    {
		carregarProxFase();
	}

    if(jogo->getSalvarFase2())
    {
        jogo->setSalvarFase2(false);
        Lentidades.gravarJogo2();
    }
}

void FaseAquatica2::inicializar(bool player2)
{
	novoJogo(player2);
	gerarObstaculos();
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

void FaseAquatica2::gerarInimigos()
{
    spawnInimigo = 1.5;
    srand(time(NULL));
    int nada = rand(); ///PARA O RAND DAR CERTO (?????)
    int coord = (rand()%300)+100;
    int chance = (rand()%100)+1;

    if((chance >= 55 && chance <= 65 ) || (chance >= 80 && chance <= 88))
        coord *= -1;

    if(chance >= 50 && chance <= 80)
    {
        Inimigo* inimigo = static_cast<Inimigo*> (prototype.MakeEsqueleto(jogo->getPlayer1()->getPosition().x+coord, std::max(coord, 0)));
        Linimigos.incluir(inimigo);
        Lentidades.incluir(static_cast<Entidade*> (inimigo));
    }
    else if(chance > 80)
    {
        Inimigo* inimigo = prototype.MakeTritao(jogo->getPlayer1()->getPosition().x+coord, 0);
        Linimigos.incluir(inimigo);
        Lentidades.incluir(static_cast<Entidade*> (inimigo));
    }

}

void FaseAquatica2::gerarObstaculos()
{
    srand(time(NULL));
    int nObstaculos = (rand()%6)+3;
    int obstaculosGerados = 0;
    ///ACHAR UMA FORMA DE DEIXAR A ORDEM QUE SÃO INICIALIZADOS ALEATÓRIA
/*    srand(time(NULL));
    int nObstaculos = (rand()%4)+3;
    int obstaculosGerados = 0;
    int v[6];
    int sorteio = (rand()%6)+1;
    printf("Primeiro sorteio: %d\n",sorteio);
    v[obstaculosGerados] = sorteio;
    while(obstaculosGerados < nObstaculos)
    {
        if(v[obstaculosGerados] == 1)
        {
            Obstaculo* ob1 = static_cast<Obstaculo*> (prototype.MakeCaixa(1175, 0));
            Lobstaculos.incluir(ob1);
            Lentidades.incluir(static_cast<Entidade*> (ob1));
        }
        else if(v[obstaculosGerados] == 2)
        {
            Obstaculo* ob2 = static_cast<Obstaculo*> (prototype.MakeCaixa(5300, 0));
            Lobstaculos.incluir(ob2);
            Lentidades.incluir(static_cast<Entidade*> (ob2));
        }
        else if(v[obstaculosGerados] == 3)
        {
            Obstaculo* ob3 = static_cast<Obstaculo*> (prototype.MakeCaixa(1925, 0));
            Lobstaculos.incluir(ob3);
            Lentidades.incluir(static_cast<Entidade*> (ob3));
        }
        else if(v[obstaculosGerados] == 4)
        {
            Obstaculo* ob4 = static_cast<Obstaculo*> (prototype.MakeCaixa(3525, 0));
            Lobstaculos.incluir(ob4);
            Lentidades.incluir(static_cast<Entidade*> (ob4));
        }
        else if(v[obstaculosGerados] == 5)
        {
            Obstaculo* ob5 = static_cast<Obstaculo*> (prototype.MakeCaixa(4425, 0));
            Lobstaculos.incluir(ob5);
            Lentidades.incluir(static_cast<Entidade*> (ob5));
        }
        else
        {
            Obstaculo* ob6 = static_cast<Obstaculo*> (prototype.MakeCaixa(5625, 0));
            Lobstaculos.incluir(ob6);
            Lentidades.incluir(static_cast<Entidade*> (ob6));
        }

        obstaculosGerados++;

        sorteio = (rand()%6)+1;
        printf("Sorteio antes: %d\n", sorteio);
        int i = 0;
        while(i < obstaculosGerados)
        {
            if(sorteio == v[i])
            {
                sorteio = (rand()%6)+1;
                i = 0;
            }
            else
                i++;
        }

        printf("Sorteio depois: %d\n", sorteio);
        v[obstaculosGerados] = sorteio;
    }
    for(int i=0; i<6; i++)
        printf("%d  ", v[i]);*/


    if(obstaculosGerados < nObstaculos)
    {
        Obstaculo* ob1 = static_cast<Obstaculo*> (prototype.MakeCaixa(2075, 0));
        Lobstaculos.incluir(ob1);
        Lentidades.incluir(static_cast<Entidade*> (ob1));
        obstaculosGerados++;
    }
    if(obstaculosGerados < nObstaculos)
    {
        Obstaculo* ob2 = static_cast<Obstaculo*> (prototype.MakeCaixa(975, 0));
        Lobstaculos.incluir(ob2);
        Lentidades.incluir(static_cast<Entidade*> (ob2));
        obstaculosGerados++;
    }
    if(obstaculosGerados < nObstaculos)
    {
        Obstaculo* ob3 = static_cast<Obstaculo*> (prototype.MakeCaixa(2525, 0));
        Lobstaculos.incluir(ob3);
        Lentidades.incluir(static_cast<Entidade*> (ob3));
        obstaculosGerados++;
    }
    if(obstaculosGerados < nObstaculos)
    {
        Obstaculo* ob4 = static_cast<Obstaculo*> (prototype.MakeCaixa(2700, 0));
        Lobstaculos.incluir(ob4);
        Lentidades.incluir(static_cast<Entidade*> (ob4));
        obstaculosGerados++;
    }
    if(obstaculosGerados < nObstaculos)
    {
        Obstaculo* ob5 = static_cast<Obstaculo*> (prototype.MakeCaixa(4650, 0));
        Lobstaculos.incluir(ob5);
        Lentidades.incluir(static_cast<Entidade*> (ob5));
        obstaculosGerados++;
    }
    if(obstaculosGerados < nObstaculos)
    {
        Obstaculo* ob6 = static_cast<Obstaculo*> (prototype.MakeCaixa(1475, 0));
        Lobstaculos.incluir(ob6);
        Lentidades.incluir(static_cast<Entidade*> (ob6));
        obstaculosGerados++;
    }
    if(obstaculosGerados < nObstaculos)
    {
        Obstaculo* ob7 = static_cast<Obstaculo*> (prototype.MakeCaixa(4125, 0));
        Lobstaculos.incluir(ob7);
        Lentidades.incluir(static_cast<Entidade*> (ob7));
        obstaculosGerados++;
    }
    if(obstaculosGerados < nObstaculos)
    {
        Obstaculo* ob8 = static_cast<Obstaculo*> (prototype.MakeCaixa(3750, 0));
        Lobstaculos.incluir(ob8);
        Lentidades.incluir(static_cast<Entidade*> (ob8));
        obstaculosGerados++;
    }
}

void FaseAquatica2::Draw(sf::RenderWindow& window)
{
    window.draw(*body);
}

void FaseAquatica2::executar()
{

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
	jogo->pushState(new FaseNoturna3(sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT), jogo, true, jogo->getP2(), gerenciadorDePontuacao.getPontuacao()));
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
        jogo->getPlayer2()->reiniciar();
    }

    jogo->getPlayer1()->reiniciar();
    Recuperador.close();
}

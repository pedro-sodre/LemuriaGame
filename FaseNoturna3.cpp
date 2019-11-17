#include "FaseNoturna3.h"
#include "Lemurya.h"
#include "MenuMorte.h"
#include "MenuPause.h"

FaseNoturna3::FaseNoturna3(sf::Vector2f tam, Lemurya* jogo, bool newGame, bool player2) :
Fase(tam, jogo)
{
	texture = jogo->getGerenciadorGrafico().getFase3Texture();
    body->setTexture(&texture);
    spawnInimigo = 2;

    musicaFundo.openFromFile("data/MusicaFundo.wav");
    musicaFundo.setLoop(true);
    //musicaFundo.play();

    if(newGame)
        inicializar(player2);
    else
        carregar(player2);
}

FaseNoturna3::~FaseNoturna3()
{
    musicaFundo.stop();
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

			/* Mudança entre estados do jogo */
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				carregarPause();
			break;


		}
	}
}

void FaseNoturna3::update()
{

    ///**** CRIAR O BOSS EM 1000, -200 ****///

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

	///GRAVA O JOGO (TIRAR DAQUI NA VERSÃO FINAL)
	Lentidades.gravarJogo();
}

void FaseNoturna3::inicializar(bool player2)
{
	novoJogo(player2);
	jogo->getPlayer1()->reiniciar();
	gerarObstaculos();
    gerenciadorDeColisoes.inicializa((jogo->getPlayer1()), jogo->getPlayer2(), &Lplataformas, &Lobstaculos, &Linimigos, &Lentidades, &Lprojeteis);
    gerenciadorDePontuacao.inicializa(jogo);

	view.setCenter(sf::Vector2f(0, 0));
	view.setSize(sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
}

void FaseNoturna3::carregar(bool player2)
{
	recuperarJogo(player2);
    gerenciadorDeColisoes.inicializa((jogo->getPlayer1()), jogo->getPlayer2(), &Lplataformas, &Lobstaculos, &Linimigos, &Lentidades, &Lprojeteis);
    gerenciadorDePontuacao.inicializa(jogo);

	view.setCenter(sf::Vector2f(0, 0));
	view.setSize(sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
}

void FaseNoturna3::gerarInimigos()
{
    spawnInimigo = 1.5;
    srand(time(NULL));
    int nada = rand(); ///PARA O RAND DAR CERTO (?????)
    int coord = (rand()%300)+100;
    int chance = (rand()%100)+1;

    if(chance >= 50 && chance <= 68 )
        coord *= -1;

    if(chance >= 50)
    {
        Inimigo* inimigo = static_cast<Inimigo*> (prototype.MakeEsqueleto(jogo->getPlayer1()->getPosition().x+coord, std::max(coord, 0)));
        Linimigos.incluir(inimigo);
        Lentidades.incluir(static_cast<Entidade*> (inimigo));
    }


}

void FaseNoturna3::gerarObstaculos()
{
    srand(time(NULL));
    int n = (rand()%2)+1;

    if(n == 1)
    {
        Obstaculo* ob1 = static_cast<Obstaculo*> (prototype.MakeCaixa(-255, 0));
        Lobstaculos.incluir(ob1);
        Lentidades.incluir(static_cast<Entidade*> (ob1));
    }
    if(n == 2)
    {
        Obstaculo* ob2 = static_cast<Obstaculo*> (prototype.MakeCaixa(1690, 0));
        Lobstaculos.incluir(ob2);
        Lentidades.incluir(static_cast<Entidade*> (ob2));
    }

}

void FaseNoturna3::carregarPause()
{
	jogo->pushState(new MenuPause(jogo));
}

void FaseNoturna3::carregarMorte()
{
	jogo->pushState(new MenuMorte(jogo));
}

void FaseNoturna3::carregarProxFase()
{
	jogo->popState();
	///MENU DE FIM DE JOGO
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

void FaseNoturna3::recuperarJogo(bool player2)
{

    ifstream Recuperador("data/Fase3Gravando.txt", ios::in);
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

void FaseNoturna3::novoJogo(bool player2)
{

    ifstream Recuperador("data/Fase3Base.txt", ios::in);
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

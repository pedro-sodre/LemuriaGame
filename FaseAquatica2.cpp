#include "FaseAquatica2.h"
#include "Lemurya.h"

FaseAquatica2::FaseAquatica2(sf::Vector2f tam, Lemurya* jogo):
Fase(tam, jogo)
{
    if(!texture.loadFromFile("data/Fase2.png"))
        std::cout << "Erro ao carregar a textura da FaseAquatica2" << std::endl;

    body->setTexture(&texture);

    musicaFundo.openFromFile("data/MusicaFundo.wav");
    musicaFundo.setLoop(true);

    this->executar();
}

FaseAquatica2::~FaseAquatica2()
{

}

void FaseAquatica2::Draw(sf::RenderWindow& window)
{
    window.draw(*body);
}

void FaseAquatica2::executar()
{

    ///INICIALIZA JANELA
    sf::RenderWindow window(sf::VideoMode(1280.0f, 720.0f), "Lemurya");

	///COLOCA OS �CONES
	sf::Image icon;
	icon.loadFromFile("data/LemuryaIcon.JPG");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    sf::View view(sf::Vector2f(0,0), sf::Vector2f(VIEW_HEIGHT,VIEW_HEIGHT));

    ///CARREGA O MAPA
    recuperarJogo(Lentidades, Linimigos, Lobstaculos, Lplataformas, Lprojeteis, prototype, *jogo->getPlayer1());

    ///CRIA GERENCIADOR DE COLIS�ES
    GerenciadorDeColisoes gerenciadorDeColisoes(jogo->getPlayer1(), &Lplataformas, &Lobstaculos, &Linimigos, &Lentidades, &Lprojeteis);

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

        ///GERENCIA COLIS�ES
        gerenciadorDeColisoes.executar();

        ///EXECUTA E DESENHA
        Lentidades.executar(deltaTime);
        Lentidades.Draw(window);

        ///VERIFICA SE PLAYER EST� VIVO PARA PASSAR PARA O PR�XIMO FRAME
        if(!jogo->getPlayer1()->estaVivo())
        {
            break;
            printf("VOCE MORREU\n");
            ///VOLTA PRO MENU
        }

        ///SALVA O JOGO
        Lentidades.gravarJogo();
     ///gravarJogo(Lentidades);              POR ALGUM MOTIVO N�O FUNCIONA
        window.display();
    }
}

void FaseAquatica2::gravarJogo(ListaEntidades& Lentidades)
{
    ofstream Gravador("data/Fase2Gravando.txt", ios::out);

    if ( !Gravador )
    {
        cerr << "Arquivo n�o pode ser aberto" << endl;
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

void FaseAquatica2::recuperarJogo(ListaEntidades& Lent, ListaInimigos& Lin, ListaObstaculos& Lobs, ListaPlataformas& Lplat, ListaProjeteis& Lproj, LemuryaPrototypeFactory prototype, Player& p1)
{

    ifstream Recuperador("data/Fase2Base.txt", ios::in);
    if ( !Recuperador )
    {
        cerr << "Arquivo n�o pode ser aberto" << endl;
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
                Lplat.incluir(prototype.MakeChao(x,y));
                break;
            case 2:
                Lplat.incluir(prototype.MakePlataforma(x,y));
                break;
            case 3:
                Lobs.incluir(static_cast<Obstaculo*> (prototype.MakeCaixa(x,y)));
                break;
            case 4:
                Lobs.incluir(static_cast<Obstaculo*> (prototype.MakePedra(x,y)));
                break;
            case 5:
                Lobs.incluir(static_cast<Obstaculo*> (prototype.MakePedra2(x,y)));
                break;
            case 6:
                Lin.incluir(static_cast<Inimigo*> (prototype.MakeEsqueleto(x,y)));
                break;
            case 7:
                Lin.incluir(static_cast<Inimigo*> (prototype.MakeMago(x,y)));
                break;
            case 8:
                Lin.incluir(static_cast<Inimigo*> (prototype.MakeTritao(x,y)));
                break;
            case 9:
                p1.getBody()->setPosition(x,y);
                ///PLAYER
                break;
            case 10:
                Lproj.incluir(prototype.MakeBolaDeFogo(x,y));
                break;
        }
    }

    for(int i=0; i < Lobs.getLTObstaculos().size(); i++)
        Lent.incluir(static_cast<Entidade*> ((Lobs.getLTObstaculos()[i])));

    for(int i=0; i < Lin.getLTInimigos().size(); i++)
        Lent.incluir(static_cast<Entidade*> ((Lin.getLTInimigos()[i])));

    for(int i=0; i < Lproj.getLTProjeteis().size(); i++)
        Lent.incluir(static_cast<Entidade*> ((Lproj.getLTProjeteis()[i])));

    for(Platform* aux = Lplat.reiniciar(); aux != NULL; aux = Lplat.percorrer())
        Lent.incluir(static_cast<Entidade*> (aux));

    Lent.incluir(static_cast<Entidade*> (&p1));

    Recuperador.close();
}


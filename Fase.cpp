#include "Fase.h"
#include "Lemurya.h"

Fase::Fase(sf::Vector2f tam, Lemurya* jogo):
Entidade(),
State()
{
    this->jogo = jogo;
    body = new sf::RectangleShape();

    body->setSize(tam);
    body->setOrigin(body->getSize() / 2.0f);

    ///CRIA PROTOTYPE
    prototype.inicializa(             new Caixa(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(300.0f, 0.0f), jogo->getGerenciadorGrafico().getBoxTexture(), 0.3f),
                                      new Pedra(sf::Vector2f(90.0f, 90.0f), sf::Vector2f(4700.0f, 605.0f), jogo->getGerenciadorGrafico().getStoneTexture1(), 0.7f),
                                      new Pedra(sf::Vector2f(90.0f, 90.0f), sf::Vector2f(3200.0f, 600.0f), jogo->getGerenciadorGrafico().getStoneTexture2(), 0.7f, 5),
                                      new Esqueleto(jogo->getGerenciadorGrafico().getTextureEsqueleto(), jogo->getGerenciadorGrafico().getVecEsqueleto(), sf::Vector2f(600.0f, 600.0f), static_cast<Fase*> (this)),
                                      new Mago(jogo->getGerenciadorGrafico().getTextureMago(), jogo->getGerenciadorGrafico().getVecMago(), sf::Vector2f(200.0f, 600.0f), static_cast<Fase*> (this)),
                                      new Platform(sf::Vector2f(250.0f, 40.0f), sf::Vector2f(600.0f, 400.0f), jogo->getGerenciadorGrafico().getPlatTexture(), 2),
                                      new Platform(sf::Vector2f(500.0f, 100.0f), sf::Vector2f(250.0f, 695.0f), jogo->getGerenciadorGrafico().getChaoTexture()),
                                      new Tritao(jogo->getGerenciadorGrafico().getTextureTritao(), jogo->getGerenciadorGrafico().getVecTritao(), sf::Vector2f(900.0f, 600.0f), static_cast<Fase*> (this)),
                                      new BolaDeFogo(jogo->getGerenciadorGrafico().getFireballTexture(), sf::Vector2f(1000.0f,1000.0f), jogo->getPlayer1()->getBody()),
                                      new Tronco(sf::Vector2f(150.0f, 90.0f), sf::Vector2f(3200.0f, 600.0f), jogo->getGerenciadorGrafico().getLogTexture(), 0.99));

}

Fase::~Fase()
{
    destruir();
}

void Fase::destruir()
{
    delete body;
}

void Fase::gerenciarColisoes()
{

}

void Fase::carregarPause()
{

}

sf::RectangleShape* Fase::getBody()
{
    return body;
}

void Fase::Draw(sf::RenderWindow& window)
{
    window.draw(*body);
}

void Fase::executar(float deltaTime)
{
}

void Fase::executar()
{
}

sf::RectangleShape* Fase::getPlayer1()
{
    return jogo->getPlayer1()->getBody();
}
sf::RectangleShape* Fase::getPlayer2()
{
    return jogo->getPlayer2()->getBody();///PLAYER2
}

void Fase::lancarBolaDeFogo(int x, int y)
{
    BolaDeFogo* fireball = prototype.MakeBolaDeFogo(x,y);
    Lprojeteis.incluir(fireball);
    Lentidades.incluir(static_cast<Entidade*>(fireball));
}

void Fase::spawnarEsqueleto(int x, int y)
{
    Esqueleto* esq1 = prototype.MakeEsqueleto(x+250,y);
    Esqueleto* esq2 = prototype.MakeEsqueleto(x-250,y);

    Linimigos.incluir(static_cast<Inimigo*>(esq1));
    Linimigos.incluir(static_cast<Inimigo*>(esq2));
    Lentidades.incluir(static_cast<Entidade*> (esq1));
    Lentidades.incluir(static_cast<Entidade*> (esq2));
}

int Fase::getNInimigos()
{
    return Linimigos.getTamanho();
}

ListaEntidades* Fase::getLentidades()
{
    return &(Lentidades);
}

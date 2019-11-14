#include "Fase.h"

Fase::Fase(sf::Vector2f tam):
Entidade()
{
    body = new sf::RectangleShape();

    body->setSize(tam);
    body->setOrigin(body->getSize() / 2.0f);

    ///INSTANCIA PLAYER
   // player2.inicializa
    player1.inicializa(200.0f, 200.0f, gerenciadorGrafico.texturePlayer1, gerenciadorGrafico.vecPlayer1, 0.2f);

    ///CRIA PROTOTYPE
    prototype.inicializa(             new Caixa(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(300.0f, 0.0f), gerenciadorGrafico.boxTexture, 0.3f),
                                      new Pedra(sf::Vector2f(90.0f, 90.0f), sf::Vector2f(4700.0f, 605.0f), gerenciadorGrafico.stoneTexture1, 0.7f),
                                      new Pedra(sf::Vector2f(90.0f, 90.0f), sf::Vector2f(3200.0f, 600.0f), gerenciadorGrafico.stoneTexture2, 0.7f, 5),
                                      new Esqueleto(gerenciadorGrafico.textureEsqueleto, gerenciadorGrafico.vecEsqueleto, sf::Vector2f(600.0f, 600.0f), player1.getBody()),
                                      new Mago(gerenciadorGrafico.textureMago, gerenciadorGrafico.vecMago, sf::Vector2f(200.0f, 600.0f), new BolaDeFogo(gerenciadorGrafico.fireballTexture, sf::Vector2f(1000.0f,1000.0f), player1.getBody()), player1.getBody()),
                                      new Platform(sf::Vector2f(250.0f, 40.0f), sf::Vector2f(600.0f, 400.0f), gerenciadorGrafico.platTexture, 2),
                                      new Platform(sf::Vector2f(500.0f, 100.0f), sf::Vector2f(250.0f, 695.0f), gerenciadorGrafico.chaoTexture),
                                      new Tritao(gerenciadorGrafico.textureTritao, gerenciadorGrafico.vecTritao, sf::Vector2f(900.0f, 600.0f), player1.getBody()),
                                      new BolaDeFogo(gerenciadorGrafico.fireballTexture, sf::Vector2f(1000.0f,1000.0f), player1.getBody()));

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

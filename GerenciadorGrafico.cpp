#include "GerenciadorGrafico.h"

GerenciadorGrafico::GerenciadorGrafico()
{
    inicializar();
}

GerenciadorGrafico::~GerenciadorGrafico()
{
}

void GerenciadorGrafico::inicializar()
{
    sf::RenderWindow window(sf::VideoMode(0.0f, 0.0f), "Lemurya");      ///CRIADO PARA EVITAR WARNINGS AO INICIAR O JOGO
    ///Necessita de janela pra textura carregar
    ///REPTILIANO REI


    sf::Texture p1Parado;
    if(!p1Parado.loadFromFile("data/Parado.png"))
        std::cout << "Erro ao carregar a textura do jogador" << std::endl;
    texturePlayer1.push_back(p1Parado);
    vecPlayer1.push_back(sf::Vector2u(2,1));

    sf::Texture p1Andando;
    if(!p1Andando.loadFromFile("data/Andando.png"))
        std::cout << "Erro ao carregar a textura do jogador" << std::endl;
    texturePlayer1.push_back(p1Andando);
    vecPlayer1.push_back(sf::Vector2u(6,1));

    sf::Texture p1Pulando;
    if(!p1Pulando.loadFromFile("data/Pulando.png"))
        std::cout << "Erro ao carregar a textura do jogador" << std::endl;
    texturePlayer1.push_back(p1Pulando);
    vecPlayer1.push_back(sf::Vector2u(5,1));

    sf::Texture p1Atacando;
    if(!p1Atacando.loadFromFile("data/Atacando.png"))
        std::cout << "Erro ao carregar a textura do jogador" << std::endl;
    texturePlayer1.push_back(p1Atacando);
    vecPlayer1.push_back(sf::Vector2u(4,1));

    sf::Texture p1Morrendo;
    if(!p1Morrendo.loadFromFile("data/Morrendo.png"))
        std::cout << "Erro ao carregar a textura do jogador" << std::endl;
    texturePlayer1.push_back(p1Morrendo);
    vecPlayer1.push_back(sf::Vector2u(4,1));



    ///ESQUELETO



    sf::Texture esqueletoParado;
    esqueletoParado.loadFromFile("data/EsqueletoParado.png");
    textureEsqueleto.push_back(esqueletoParado);
    vecEsqueleto.push_back(sf::Vector2u(2,1));

    sf::Texture esqueletoAndando;
    esqueletoAndando.loadFromFile("data/EsqueletoAndando.png");
    textureEsqueleto.push_back(esqueletoAndando);
    vecEsqueleto.push_back(sf::Vector2u(6,1));

    sf::Texture esqueletoAtacando;
    esqueletoAtacando.loadFromFile("data/EsqueletoAtacando1.png");
    textureEsqueleto.push_back(esqueletoAtacando);
    vecEsqueleto.push_back(sf::Vector2u(5,1));



    ///TRITÃO



    sf::Texture tritaoParado;
    tritaoParado.loadFromFile("data/TritaoTeste.png");
    textureTritao.push_back(tritaoParado);
    vecTritao.push_back(sf::Vector2u(1,1));



    ///MAGO



    sf::Texture magoParado;
    magoParado.loadFromFile("data/MagoTeste.png");
    textureMago.push_back(magoParado);
    vecMago.push_back(sf::Vector2u(1,1));

    sf::Texture magoAndando;
    magoAndando.loadFromFile("data/magoAndando.png");
    textureMago.push_back(magoAndando);
    vecMago.push_back(sf::Vector2u(4,1));


    ///BOLA DE FOGO
    if(!fireballTexture.loadFromFile("data/BolaDeFogo.png"))
        std::cout << "Erro ao carregar a textura da bola de fogo" << std::endl;



    ///OBSTÁCULOS



    if(!boxTexture.loadFromFile("data/Caixa.png"))
        std::cout << "Erro ao carregar a textura da caixa" << std::endl;

    if(!stoneTexture1.loadFromFile("data/Pedra1.png"))
        std::cout << "Erro ao carregar a textura da pedra" << std::endl;

    if(!stoneTexture2.loadFromFile("data/Pedra2.png"))
        std::cout << "Erro ao carregar a textura da pedra" << std::endl;

    if(!platTexture.loadFromFile("data/BGplat.png"))
        std::cout << "Erro ao carregar a textura da plataforma" << std::endl;

    if(!chaoTexture.loadFromFile("data/Chao.png"))
        std::cout << "Erro ao carregar a textura do chao" << std::endl;
}

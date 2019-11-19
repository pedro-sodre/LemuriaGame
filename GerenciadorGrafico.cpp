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
    sf::Texture p1Andando;
    sf::Texture p1Pulando;
    sf::Texture p1Atacando;
    sf::Texture p1Morrendo;
    sf::Texture iconeVida;
    ///ESQUELETO
    sf::Texture esqueletoParado;
    sf::Texture esqueletoAndando;
    sf::Texture esqueletoAtacando;
    ///TRIT�O
    sf::Texture tritaoParado;
    ///MAGO
    sf::Texture magoParado;
    sf::Texture magoAndando;
    sf::Texture magoAtacando;
    sf::Texture magoSpawnando;

    try
    {
        ///FONTES
        if(!fontBlackCastle.loadFromFile("data/BlackCastleMF.ttf"))
            throw 1;
        if (!fontAudiowide.loadFromFile("data/Audiowide.ttf"))
            throw 1;
        if (!fontGameOver.loadFromFile("data/game_over.ttf"))
            throw 1;

        ///TEXTURAS MENU
    	if (!menuPrincipalTexture.loadFromFile("data/Menu.jpg"))
            throw 2;
        if (!menuPauseTexture.loadFromFile("data/Pause.jpg"))
            throw 2;
        if (!menuMorteTexture.loadFromFile("data/FundoGameOver.png"))
            throw 2;
        if (!logoTexture.loadFromFile("data/LemuryaIcon.jpg"))
            throw 2;

        ///TEXTURAS DAS FASES
        if(!fase1Texture.loadFromFile("data/Fase1.png"))
            throw 3;
        if(!fase2Texture.loadFromFile("data/Fase2.png"))
            throw 3;
        if(!fase3Texture.loadFromFile("data/Fase3.png"))
            throw 3;

        ///TEXTURAS PLAYER
        if(!p1Parado.loadFromFile("data/Parado.png"))
            throw 4;
        if(!p1Andando.loadFromFile("data/Andando.png"))
            throw 4;
        if(!p1Pulando.loadFromFile("data/Pulando.png"))
            throw 4;
        if(!p1Atacando.loadFromFile("data/Atacando.png"))
            throw 4;
        if(!p1Morrendo.loadFromFile("data/Morrendo.png"))
            throw 4;
        if(!iconeVida.loadFromFile("data/LemuryaIcon.png"))
            throw 4;

        ///ESQUELETO
        if(!esqueletoParado.loadFromFile("data/EsqueletoParado.png"))
            throw 5;
        if(!esqueletoAndando.loadFromFile("data/EsqueletoAndando.png"))
            throw 5;
        if(!esqueletoAtacando.loadFromFile("data/EsqueletoAtacando1.png"))
            throw 5;

        ///TRIT�O
        if(!tritaoParado.loadFromFile("data/TritaoTeste.png"))
            throw 6;

        ///MAGO
        if(!magoParado.loadFromFile("data/MagoTeste.png"))
            throw 7;
        if(!magoAndando.loadFromFile("data/magoAndando.png"))
            throw 7;
        if(!magoAtacando.loadFromFile("data/magoAtacando.png"))
            throw 7;
        if(!magoSpawnando.loadFromFile("data/magoSpawnando.png"))
            throw 7;
        if(!fireballTexture.loadFromFile("data/BolaDeFogo.png"))
            throw 7;

        ///OBST�CULOS
        if(!boxTexture.loadFromFile("data/Caixa.png"))
            throw 8;
        if(!stoneTexture1.loadFromFile("data/Pedra1.png"))
            throw 8;
        if(!stoneTexture2.loadFromFile("data/Pedra2.png"))
            throw 8;
        if(!platTexture.loadFromFile("data/BGplat.png"))
            throw 8;
        if(!chaoTexture.loadFromFile("data/Chao.png"))
            throw 8;
        if(!logTexture.loadFromFile("data/Tronco.png"))
            throw 8;

    }
    catch(int i)
    {
        if(i == 1)
            std::cout << "Erro ao carregar Fontes" << std::endl;
        if(i == 2)
            std::cout << "Erro ao carregar as texturas do Menu" << std::endl;
        if(i == 3)
            std::cout << "Erro ao carregar a texturas das Fases" << std::endl;
        if(i == 4)
            std::cout << "Erro ao carregar a textura do jogador" << std::endl;
        if(i == 5)
            std::cout << "Erro ao carregar a textura do esqueleto" << std::endl;
        if(i == 6)
            std::cout << "Erro ao carregar a textura do tritao" << std::endl;
        if(i == 7)
            std::cout << "Erro ao carregar a textura do mago" << std::endl;
        if(i == 8)
            std::cout << "Erro ao carregar as texturas dos obstaculos" << std::endl;

        exit(1);
    }


    ///REPTILIANO REI
    texturePlayer1.push_back(p1Parado);
    vecPlayer1.push_back(sf::Vector2u(2,1));

    texturePlayer1.push_back(p1Andando);
    vecPlayer1.push_back(sf::Vector2u(6,1));

    texturePlayer1.push_back(p1Pulando);
    vecPlayer1.push_back(sf::Vector2u(5,1));

    texturePlayer1.push_back(p1Atacando);
    vecPlayer1.push_back(sf::Vector2u(4,1));

    texturePlayer1.push_back(p1Morrendo);
    vecPlayer1.push_back(sf::Vector2u(4,1));

    texturePlayer1.push_back(iconeVida);

    ///ESQUELETO
    textureEsqueleto.push_back(esqueletoParado);
    vecEsqueleto.push_back(sf::Vector2u(2,1));

    textureEsqueleto.push_back(esqueletoAndando);
    vecEsqueleto.push_back(sf::Vector2u(6,1));

    textureEsqueleto.push_back(esqueletoAtacando);
    vecEsqueleto.push_back(sf::Vector2u(5,1));

    ///TRIT�O
    textureTritao.push_back(tritaoParado);
    vecTritao.push_back(sf::Vector2u(1,1));

    ///MAGO
    textureMago.push_back(magoParado);
    vecMago.push_back(sf::Vector2u(1,1));

    textureMago.push_back(magoAndando);
    vecMago.push_back(sf::Vector2u(4,1));

    textureMago.push_back(magoAtacando);
    vecMago.push_back(sf::Vector2u(3,1));

    textureMago.push_back(magoSpawnando);
    vecMago.push_back(sf::Vector2u(7,1));

}

vector<sf::Texture> GerenciadorGrafico::getTexturePlayer1() const
{
    return texturePlayer1;
}

vector<sf::Vector2u> GerenciadorGrafico::getVecPlayer1() const
{
    return vecPlayer1;
}

vector<sf::Texture> GerenciadorGrafico::getTextureEsqueleto() const
{
    return textureEsqueleto;
}

vector<sf::Vector2u> GerenciadorGrafico::getVecEsqueleto() const
{
    return vecEsqueleto;
}

vector<sf::Texture> GerenciadorGrafico::getTextureTritao() const
{
    return textureTritao;
}

vector<sf::Vector2u> GerenciadorGrafico::getVecTritao() const
{
    return vecTritao;
}

vector<sf::Texture> GerenciadorGrafico::getTextureMago() const
{
    return textureMago;
}

vector<sf::Vector2u> GerenciadorGrafico::getVecMago() const
{
    return vecMago;
}

sf::Texture GerenciadorGrafico::getBoxTexture() const
{
    return boxTexture;
}

sf::Texture GerenciadorGrafico::getStoneTexture1() const
{
    return stoneTexture1;
}

sf::Texture GerenciadorGrafico::getStoneTexture2() const
{
    return stoneTexture2;
}

sf::Texture GerenciadorGrafico::getPlatTexture() const
{
    return platTexture;
}

sf::Texture GerenciadorGrafico::getChaoTexture() const
{
    return chaoTexture;
}

sf::Texture GerenciadorGrafico::getFireballTexture() const
{
    return fireballTexture;
}

sf::Texture GerenciadorGrafico::getFase1Texture() const
{
    return fase1Texture;
}

sf::Texture GerenciadorGrafico::getFase2Texture() const
{
    return fase2Texture;
}

sf::Texture GerenciadorGrafico::getFase3Texture() const
{
    return fase3Texture;
}

sf::Font GerenciadorGrafico::getFontBlackCastle() const
{
    return fontBlackCastle;
}

sf::Font GerenciadorGrafico::getFontAudiowide() const
{
    return fontAudiowide;
}

sf::Font GerenciadorGrafico::getFontGameOver() const
{
    return fontGameOver;
}

sf::Texture GerenciadorGrafico::getMenuPauseTexture() const
{
    return menuPauseTexture;
}

sf::Texture GerenciadorGrafico::getMenuMorteTexture() const
{
    return menuMorteTexture;
}

sf::Texture GerenciadorGrafico::getMenuPrincipalTexture() const
{
    return menuPrincipalTexture;
}

sf::Texture GerenciadorGrafico::getLogoTexture() const
{
    return logoTexture;
}

sf::Texture GerenciadorGrafico::getLogTexture() const
{
    return logTexture;
}

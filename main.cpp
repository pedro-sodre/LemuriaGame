#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Platform.h"
#include <vector>
using std::vector;

int Platform::Nplat(0);

static const float VIEW_HEIGHT = 720.0f;

void resizeView(const sf::RenderWindow& window, sf::View& view)   //UTILIZADO PARA DEIXAR O PERSONAGEM PROPORCIONAL QUANDO MUDAR O TAMANHO DA TELA
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{
    //INICIALIZA JANELA, PLAYER E PLATAFORMAS
    sf::RenderWindow window(sf::VideoMode(1280.0f, 720.0f), "Lemurya");
    sf::SoundBuffer soundBuffer;
    sf::Music musicaFundo;
    musicaFundo.openFromFile("data/MusicaFundo.wav");

    sf::View view(sf::Vector2f(0,0), sf::Vector2f(VIEW_HEIGHT,VIEW_HEIGHT));   //FAZER ASSIM SE FOR DEIXAR A VIEW QUADRADA, SENÃO MUDAR OS VALORES

    sf::Texture p1Texture;
    p1Texture.loadFromFile("data/tux_from_linux.png");
    Player player1(100.0f, p1Texture, sf::Vector2u(3, 9), 0.3f);

    Platform chao(sf::Vector2f(1280.0f, 50.0f), sf::Vector2f(640.0f, 695.0f));
    Platform plat1(sf::Vector2f(250.0f, 40.0f), sf::Vector2f(500.0f, 500.0f));

    vector<Platform*> plataformas;
    plataformas.push_back(&plat1);
    plataformas.push_back(&chao);

    float deltaTime = 0.0f;
    sf::Clock clock;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    resizeView(window, view);
                    break;
            }
        }

        //TOCAR MÚSICA DE FUNDO
        if(musicaFundo.getStatus()!=2)
            musicaFundo.play();

        //COLISÃO COM AS PAREDES
        if(player1.getBody()->getPosition().x < player1.getBody()->getSize().x/2)
                player1.getBody()->setPosition(player1.getBody()->getSize().x/2, player1.getBody()->getPosition().y);
        /**COLISÃO COM A PAREDE DA DIREITA
        **/
        if(player1.getBody()->getPosition().y < 0)
            player1.getBody()->setPosition(player1.getBody()->getPosition().x, 0);
        if(player1.getBody()->getPosition().y > 720.0f - ((player1.getBody()->getSize().y/2)) - chao.getBody()->getSize().y)
            player1.getBody()->setPosition(player1.getBody()->getPosition().x, 720.0f - (player1.getBody()->getSize().y/2) - chao.getBody()->getSize().y);

        //TESTE DE COLISÕES
       if(player1.getBody()->getGlobalBounds().intersects(chao.getBody()->getGlobalBounds()))
        {
            printf("Collision\n");
        }
        if(player1.getBody()->getGlobalBounds().intersects(plat1.getBody()->getGlobalBounds()))
        {
            printf("Collision\n");
        }

        player1.Update(deltaTime);                  //ATUALIZA E SETA A VISÃO
        view.setCenter(player1.getPosition());

        window.clear(sf::Color(150,150,150));       //LIMPA BUFFER
        window.setView(view);

        for(int i=0; i<Platform::Nplat; i++)        //DESENHA
            plataformas[i]->Draw(window);

        player1.Draw(window);
        window.display();
    }

    return 0;
}

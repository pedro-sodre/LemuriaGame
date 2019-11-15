#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>
using namespace std;

#include <vector>
using std::vector;

class GerenciadorGrafico
{
private:
    vector<sf::Texture> texturePlayer1;
    vector<sf::Vector2u> vecPlayer1;

    vector<sf::Texture> textureEsqueleto;
    vector<sf::Vector2u> vecEsqueleto;

    vector<sf::Texture> textureTritao;
    vector<sf::Vector2u> vecTritao;

    vector<sf::Texture> textureMago;
    vector<sf::Vector2u> vecMago;

    sf::Texture boxTexture;
    sf::Texture stoneTexture1;
    sf::Texture stoneTexture2;
    sf::Texture platTexture;
    sf::Texture chaoTexture;
    sf::Texture fireballTexture;         //POR ENQUANTO SEM ANIMAÇÃO

    sf::Texture fase1Texture;
    sf::Texture fase2Texture;
    sf::Texture fase3Texture;

    sf::Texture menuTexture;
    sf::Texture logoTexture;

    sf::Font fontBlackCastle;
    sf::Font fontAudiowide;

public:
    GerenciadorGrafico();
    ~GerenciadorGrafico();
    void inicializar();

    vector<sf::Texture> getTexturePlayer1() const;
    vector<sf::Vector2u> getVecPlayer1() const;

    vector<sf::Texture> getTextureEsqueleto() const;
    vector<sf::Vector2u> getVecEsqueleto() const;

    vector<sf::Texture> getTextureTritao() const;
    vector<sf::Vector2u> getVecTritao() const;

    vector<sf::Texture> getTextureMago() const;
    vector<sf::Vector2u> getVecMago() const;

    sf::Texture getBoxTexture() const;
    sf::Texture getStoneTexture1() const;
    sf::Texture getStoneTexture2() const;
    sf::Texture getPlatTexture() const;
    sf::Texture getChaoTexture() const;
    sf::Texture getFireballTexture() const;

    sf::Texture getFase1Texture() const;
    sf::Texture getFase2Texture() const;
    sf::Texture getFase3Texture() const;

    sf::Texture getMenuTexture() const;
    sf::Texture getLogoTexture() const;

    sf::Font getFontBlackCastle() const;
    sf::Font getFontAudiowide() const;
};

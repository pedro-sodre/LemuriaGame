#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>
using namespace std;

#include <vector>
using std::vector;

class GerenciadorGrafico
{
public:///DEIXAR PRIVADO
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

    sf::Font fontRanking;

public:
    GerenciadorGrafico();
    ~GerenciadorGrafico();

    void inicializar();

};

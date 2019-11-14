#pragma once
#include "Inimigo.h"

class Tritao: public Inimigo
{
private:

public:
    Tritao(vector<sf::Texture> textureTritao, vector<sf::Vector2u> vecTritao, sf::Vector2f posicao, sf::RectangleShape* p1=NULL, sf::RectangleShape* p2=NULL, int ID = 8);
    Tritao(const Tritao& other, float x, float y);
    ~Tritao();

    Tritao* clone(float x, float y) const;

    void inicializa(vector<sf::Texture> textureTritao, vector<sf::Vector2u> vecTritao, sf::Vector2f posicao, sf::RectangleShape* p1=NULL, sf::RectangleShape* p2=NULL, int ID = 8);

    void executar(float deltaTime);
};

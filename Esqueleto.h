#pragma once
#include "Inimigo.h"

class Esqueleto: public Inimigo
{
private:

public:
    Esqueleto(vector<sf::Texture> textureEsqueleto, vector<sf::Vector2u> vecEsqueleto, sf::Vector2f posicao, sf::RectangleShape* p1=NULL, sf::RectangleShape* p2=NULL, int ID = 6);
    Esqueleto(const Esqueleto& other, float x, float y);
    ~Esqueleto();

    Esqueleto* clone(float x, float y) const;

    void inicializa(vector<sf::Texture> textureEsqueleto, vector<sf::Vector2u> vecEsqueleto, sf::Vector2f posicao, sf::RectangleShape* p1=NULL, sf::RectangleShape* p2=NULL, int ID = 6);

    void executar(float deltaTime);

};

#pragma once
#include "Inimigo.h"
#include "BolaDeFogo.h"

class Mago: public Inimigo
{
private:
    BolaDeFogo* fireball;
public:
    Mago(vector<sf::Texture> textureMago, vector<sf::Vector2u> vecMago, sf::Vector2f posicao, BolaDeFogo* bfogo = NULL, sf::RectangleShape* p1=NULL, sf::RectangleShape* p2=NULL, int ID = 7);
    Mago(const Mago& other, float x, float y);
    ~Mago();

    Mago* clone(float x, float y) const;

    void inicializa(vector<sf::Texture> textureMago, vector<sf::Vector2u> vecMago, sf::Vector2f posicao, BolaDeFogo* bfogo = NULL, sf::RectangleShape* p1=NULL, sf::RectangleShape* p2=NULL, int ID = 7);

    void executar(float deltaTime);

};

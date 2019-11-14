#pragma once
#include "EntidadeColidivel.h"

class BolaDeFogo: public EntidadeColidivel
{
private:
    int vida;
    sf::RectangleShape* player1;
    sf::RectangleShape* player2;
    sf::Vector2f direcao;
public:
    BolaDeFogo(sf::Texture t, sf::Vector2f posicao, sf::RectangleShape* p1=NULL, sf::RectangleShape* p2=NULL, int ID = 10);
    BolaDeFogo(const BolaDeFogo& other, float x, float y);
    ~BolaDeFogo();

    BolaDeFogo* clone(float x, float y) const;

    void inicializa(sf::Texture t, sf::Vector2f posicao, sf::RectangleShape* p1=NULL, sf::RectangleShape* p2=NULL, int ID = 10);

    void executar(float deltaTime);

    void setVida(int v);
    int getVida();
};

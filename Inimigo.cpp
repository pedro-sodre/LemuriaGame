#include "Inimigo.h"
#include "Fase.h"

Inimigo::Inimigo():
Personagem()
{
    player1 = NULL;
    player2 = NULL;
}

Inimigo::Inimigo(sf::RectangleShape* p1, sf::RectangleShape* p2):
Personagem()
{
    player1 = p1;
    player2 = p2;
}

Inimigo::Inimigo(sf::RectangleShape* p1):
Personagem()
{
    player1 = p1;
    player2 = NULL;
}

Inimigo::~Inimigo()
{
    player1 = NULL;
    player2 = NULL;
}

void Inimigo::executar(float deltaTime)
{
}

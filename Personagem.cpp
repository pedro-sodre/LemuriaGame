#include "Personagem.h"

Personagem::Personagem():
EntidadeColidivel()
{
   vida = 10;
}

void Personagem::setVida(int v)
{
    vida = v;
}

int Personagem::getVida()
{
    return vida;
}

Personagem::~Personagem()
{
}

void Personagem::executar(float deltaTime)
{
}

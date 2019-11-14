#pragma once
#include "EntidadeColidivel.h"
#include "Animation.h"
#include <vector>
using std::vector;

class Personagem: public EntidadeColidivel
{
protected:
    int vida;
    bool canJump;
    float jumpHeight;
    unsigned int row;
    bool faceRight;

    vector<sf::Texture> vecTexture;
    vector<sf::Vector2u> vecVector;
    vector<Animation*> animacao;

public:
    Personagem();
    virtual ~Personagem();

    void setVida(int v);
    int getVida();

    virtual void executar(float deltaTime);
};

#include "Esqueleto.h"

void Esqueleto::inicializa(vector<sf::Texture> textureEsqueleto, vector<sf::Vector2u> vecEsqueleto, sf::Vector2f posicao, sf::RectangleShape* p1, sf::RectangleShape* p2, int ID)
{
    id = ID;
    player1 = p1;
    player2 = p2;

    this->vecTexture = textureEsqueleto;
    this->vecVector  = vecEsqueleto;

    speed = 50.0f;
    body->setSize(sf::Vector2f(80.f, 120.0f));
    body->setOrigin(body->getSize() / 2.0f);
    body->setPosition(posicao);

    x = posicao.x;
    y = posicao.y;

    setTexture(vecTexture[0]);

    animacao.push_back(new Animation(&vecTexture[0], vecVector[0], 0.2f));
    animacao.push_back(new Animation(&vecTexture[1], vecVector[1], 0.2f));
    animacao.push_back(new Animation(&vecTexture[2], vecVector[2], 0.2f));

}

Esqueleto::Esqueleto(vector<sf::Texture> textureEsqueleto, vector<sf::Vector2u> vecEsqueleto, sf::Vector2f posicao, sf::RectangleShape* p1, sf::RectangleShape* p2, int ID):
Inimigo(p1, p2)
{
    inicializa(textureEsqueleto, vecEsqueleto, posicao, p1, p2, ID);
}

Esqueleto::Esqueleto(const Esqueleto& other, float x, float y)
{
   inicializa(other.vecTexture, other.vecVector, sf::Vector2f(x,y), other.player1, other.player2, other.id);
}


Esqueleto::~Esqueleto()
{
    for(int i=0; i<2; i++)
        delete animacao[i];
}

void Esqueleto::executar(float deltaTime)
{
    row = 0;
    velocity.x = 0.0f;
    if(player1)
    {
        if(player1->getPosition().x > body->getPosition().x)
        {
            row = 1;
            body->setTexture(&vecTexture[row]);
            faceRight = true;
            velocity.x += speed;
        }
        else if(player1->getPosition().x < body->getPosition().x)
        {
            row = 1;
            body->setTexture(&vecTexture[row]);
            faceRight = false;
            velocity.x -= speed;
        }
/*        if(abs(player1->getPosition().x - body->getPosition().x) < body->getSize().x && abs(player1->getPosition().y - body->getPosition().y) < body->getSize().y)
            row = 2;
 */
        velocity.y += 981.0f * deltaTime;                    //GRAVIDADE

        animacao[row]->Update(deltaTime, faceRight);
        body->setTextureRect(animacao[row]->uvRect);
        body->move(velocity * deltaTime);

        x = this->getPosition().x;
        y = this->getPosition().y;
    }

}

Esqueleto* Esqueleto::clone(float x, float y) const
{
    return new Esqueleto(*this, x, y);
}

#include "Tritao.h"

void Tritao::inicializa(vector<sf::Texture> textureTritao, vector<sf::Vector2u> vecTritao, sf::Vector2f posicao, sf::RectangleShape* p1, sf::RectangleShape* p2, int ID)
{
    id = ID;
    player1 = p1;
    player2 = p2;

    this->vecTexture = textureTritao;
    this->vecVector  = vecTritao;

    speed = 35.0f;
    body->setSize(sf::Vector2f(80.f, 120.0f));
    body->setOrigin(body->getSize() / 2.0f);
    body->setPosition(posicao);

    x = posicao.x;
    y = posicao.y;

    setTexture(vecTexture[0]);

    animacao.push_back(new Animation(&vecTexture[0], vecVector[0], 0.2f));
}

Tritao::Tritao(const Tritao& other, float x, float y)
{
    inicializa(other.vecTexture, other.vecVector, sf::Vector2f(x,y), other.player1, other.player2, other.id);
}

Tritao::Tritao(vector<sf::Texture> textureTritao, vector<sf::Vector2u> vecTritao, sf::Vector2f posicao, sf::RectangleShape* p1, sf::RectangleShape* p2, int ID):
Inimigo(p1, p2)
{
    inicializa(textureTritao, vecTritao,posicao, p1, p2, ID);
}

Tritao::~Tritao()
{

}

void Tritao::executar(float deltaTime)
{
    row = 0;
    velocity.x = 0.0f;
    if(player1)
    {
            if(player1->getPosition().x > body->getPosition().x)
        {
            faceRight = true;
            velocity.x += speed;
        }
        else
        {
            faceRight = false;
            velocity.x -= speed;
        }

        velocity.y += 981.0f * deltaTime;                    //GRAVIDADE

        animacao[row]->Update(deltaTime, faceRight);
        body->setTextureRect(animacao[row]->uvRect);
        body->move(velocity * deltaTime);

        x = this->getPosition().x;
        y = this->getPosition().y;
    }
}

Tritao* Tritao::clone(float x, float y) const
{
    return new Tritao(*this, x, y);
}

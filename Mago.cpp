#include "Mago.h"

void Mago::inicializa(vector<sf::Texture> textureMago, vector<sf::Vector2u> vecMago, sf::Vector2f posicao, BolaDeFogo* bfogo, sf::RectangleShape* p1, sf::RectangleShape* p2, int ID)
{
    id = ID;
    player1 = p1;
    player2 = p2;
    fireball = bfogo;

    this->vecTexture = textureMago;
    this->vecVector  = vecMago;

    speed = 50.0f;
    body->setSize(sf::Vector2f(120.f, 160.0f));
    body->setOrigin(body->getSize() / 2.0f);
    body->setPosition(posicao);

    x = posicao.x;
    y = posicao.y;

    setTexture(vecTexture[0]);

    animacao.push_back(new Animation(&vecTexture[0], vecVector[0], 0.3f));
    animacao.push_back(new Animation(&vecTexture[1], vecVector[1], 0.3f));
}

Mago::Mago(const Mago& other, float x, float y)
{
    inicializa(other.vecTexture, other.vecVector, sf::Vector2f(x,y), other.fireball, other.player1, other.player2, other.id);
}

Mago::Mago(vector<sf::Texture> textureMago, vector<sf::Vector2u> vecMago, sf::Vector2f posicao, BolaDeFogo* bfogo, sf::RectangleShape* p1, sf::RectangleShape* p2, int ID):
Inimigo(p1, p2)
{
    inicializa(textureMago, vecMago, posicao, bfogo, p1, p2, ID);
}

Mago::~Mago()
{
    fireball = NULL;
}

void Mago::executar(float deltaTime)
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

Mago* Mago::clone(float x, float y) const
{
    return new Mago(*this, x, y);
}

#include "BolaDeFogo.h"

BolaDeFogo::BolaDeFogo(sf::Texture t, sf::Vector2f posicao, sf::RectangleShape* p1, sf::RectangleShape* p2, int ID)
{
    inicializa(t, posicao, p1, p2, ID);
}

BolaDeFogo::~BolaDeFogo()
{
}

void BolaDeFogo::inicializa(sf::Texture t, sf::Vector2f posicao, sf::RectangleShape* p1, sf::RectangleShape* p2, int ID)
{
    player1 = p1;
    player2 = p2;
    vida = 1;
    id = ID;
    texture = t;
    setTexture(texture);

    speed = 500.0f;
    body->setSize(sf::Vector2f(30.f, 30.0f));
    body->setOrigin(body->getSize() / 2.0f);
    body->setPosition(posicao);

    x = posicao.x;
    y = posicao.y;

    ///FAZER PRO PLAYER2 TAMBÉM
    if(player1)
    {
        float distanciax = player1->getPosition().x - x;
        float distanciay = player1->getPosition().y - y;
        float norma      = sqrt(distanciax*distanciax + distanciay*distanciay);
        direcao          = sf::Vector2f(distanciax/norma, distanciay/norma);
    }

}

BolaDeFogo::BolaDeFogo(const BolaDeFogo& other, float x, float y)
{
    inicializa(other.texture, sf::Vector2f(x,y), other.player1, other.player2, other.id);
}

BolaDeFogo* BolaDeFogo::clone(float x, float y) const
{
    return new BolaDeFogo(*this, x, y);
}

void BolaDeFogo::executar(float deltaTime)
{
    //função para ir em direção ao player;
    velocity.x = 0.0f;
    velocity.y = 0.0f;
    velocity.x += speed * direcao.x;
    velocity.y += speed * direcao.y;// * direcao.y;

    body->move(velocity * deltaTime);

    x = this->getPosition().x;
    y = this->getPosition().y;
}

void BolaDeFogo::setVida(int v)
{
    vida = v;
}
int BolaDeFogo::getVida()
{
    return vida;
}


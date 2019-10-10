#include "Player.h"

Player::Player(float speed, const sf::Texture pTexture, sf::Vector2u imageCount, float switchTime)
//TERIA COMO INICIALIZAR A ANIMA플O AQUI
{
    this->speed = speed;
    row = 0;
    faceRight = true;

    body = new sf::RectangleShape();

    body->setSize(sf::Vector2f(100.f, 150.0f));
    body->setOrigin(body->getSize() / 2.0f);
    body->setPosition(0.0f, 720.0f);

    setTexture(pTexture);

    animation = new Animation(&playerTexture, imageCount, switchTime);
}

Player::~Player()
{
    delete body;
    delete animation;
}

void Player::setTexture(const sf::Texture pTexture)
{
    playerTexture = pTexture;
    body->setTexture(&playerTexture);
}

Animation* Player::getAnimation()
{
    return animation;
}

void Player::setBody(sf::RectangleShape* b)
{
    body = b;
}

sf::RectangleShape* Player::getBody()
{
    return body;
}

void Player::Update(float deltaTime)
{
       /** animation->Update(0, deltaTime, faceRight);
        body->setTextureRect(animation->uvRect);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            body->move(0.0f, -speed);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            body->move(0.0f, speed);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            body->move(-speed, 0.0f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            body->move(speed, 0.0f);**/

        sf::Vector2f movement(0.0f, 0.0f);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            movement.x -= speed * deltaTime;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            movement.x += speed * deltaTime;

        if(movement.x == 0.0f)
            row = 0;            //SELECIONA COLUNA DE ANIMA플O EM QUE EST� PARADO
        else
        {
            row = 1;            //ANIMA플O SE MOVENDO

            if(movement.x > 0.0f)
                faceRight = true;       //MOVENDO PARA A DIREITA
            else
                faceRight = false;      //MOVENDO PARA A ESQUERDA
        }

        animation->Update(row, deltaTime, faceRight);
        body->setTextureRect(animation->uvRect);
        body->move(movement);

}

void Player::inicializa(sf::RectangleShape* player)
{
    body = player;
}
void Player::Draw(sf::RenderWindow& window)
{
    window.draw(*body);
}

#pragma once
#include "Entidade.h"
#include "Collider.h"

class EntidadeColidivel: public Entidade
{
protected:
    sf::RectangleShape* body;   ///TRANSFERIR GET E SET DE PLAYER.H
    sf::Vector2f velocity;        ///TRANSFERIR GET E SET DE PLAYER.H
    float speed;

public:
    EntidadeColidivel();
    EntidadeColidivel(sf::RectangleShape* body);
    virtual ~EntidadeColidivel();

    void destruir();

    void setBody(sf::RectangleShape* b);
    sf::RectangleShape* getBody();

    void setTexture(const sf::Texture pTexture);

    virtual void onCollision(sf::Vector2f direction);           //REDEFINIÇÃO PARA O PLAYER
    virtual Collider getCollider() { return Collider(*body); }

    sf::Vector2f getPosition() const { return body->getPosition(); }

    virtual void Draw(sf::RenderWindow& window);    //VIRTUAL PRA DESENHAR OS DOIS BODYS DO PLAYER

    virtual void executar(float deltaTime);
};

#pragma once
#include "Personagem.h"

#include <vector>
using std::vector;

#include "Animation.h"
#include "Collider.h"

class Player: public Personagem
{
public:
    Player(const float speed, const float jumpHeight, vector<sf::Texture> playerTexture, vector<sf::Vector2u> playerVector, float switchTime, const bool p2 = false);
    Player();
    ~Player();

    void inicializa(const float speed, const float jumpHeight, vector<sf::Texture> playerTexture, vector<sf::Vector2u> playerVector, float switchTime, const bool p2 = false);
    void reiniciar();

    void onCollision(sf::Vector2f direction);       //REDEFINIÇÃO DA FUNÇÃO VOID, POIS O JOGADOR PRECISA TER O CANJUMP RESETADO

    void Update(float deltaTime);

    void knockback(sf::Vector2f direction);

    void executar(float deltaTime);

    bool estaVivo() const;
    void morreu(float deltaTime);

    Collider getCollider() const;
    void Draw(sf::RenderWindow& window);

    bool isAtacking() const;

    int getRanking() const;
    void setRanking(const int r);

    sf::RectangleShape* getDamage() const;
    sf::RectangleShape* getLife() const;
    sf::RectangleShape* getLifeIcon() const;

private:
    sf::RectangleShape* atackBody;
    sf::RectangleShape* animationBody;
    bool atacking;

    sf::RectangleShape* lifeIcon;
    sf::RectangleShape* life;
    sf::RectangleShape* damage;

    int ranking;
    bool player2;
};


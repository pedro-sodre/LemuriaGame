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

    void onCollision(sf::Vector2f direction);       //REDEFINIÇÃO DA FUNÇÃO VOID, POIS O JOGADOR PRECISA TER O CANJUMP RESETADO

    void Update(float deltaTime);

    void setCanJump(const bool canJump);
    bool getCanJump() const;

    void knockback(sf::Vector2f direction);

    void executar(float deltaTime);

    bool estaVivo() const;
    void morreu(float deltaTime);

    Collider getCollider() const;
    void Draw(sf::RenderWindow& window);

    bool isAtacking() const;

    int getRanking() const;
    void setRanking(const int r);


private:
    sf::RectangleShape* atackBody;
    sf::RectangleShape* animationBody;
    bool atacking;
    int nImagem;

    int ranking;
    bool player2;
};


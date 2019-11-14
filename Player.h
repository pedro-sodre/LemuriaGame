#pragma once
#include "Personagem.h"

#include <vector>
using std::vector;

#include "Animation.h"
#include "Collider.h"

class Player: public Personagem
{
public:
    Player(float speed, float jumpHeight, vector<sf::Texture> playerTexture, vector<sf::Vector2u> playerVector, float switchTime);
    Player();
    ~Player();

    void inicializa(float speed, float jumpHeight, vector<sf::Texture> playerTexture, vector<sf::Vector2u> playerVector, float switchTime);

    void onCollision(sf::Vector2f direction);       //REDEFINIÇÃO DA FUNÇÃO VOID, POIS O JOGADOR PRECISA TER O CANJUMP RESETADO

    void Update(float deltaTime);

    void setCanJump(bool canJump);
    bool getCanJump();

    void knockback(sf::Vector2f direction);

    void executar(float deltaTime);

    bool estaVivo();
    void morreu(float deltaTime);


    ///TESTE PARA FAZER O ATAQUE

    sf::RectangleShape* atackBody;
    sf::RectangleShape* animationBody;
    bool atacking;

    bool isAtacking() const;

    int nImagem;

    int ranking;

    Collider getCollider() ;

    void Draw(sf::RenderWindow& window);

private:

};

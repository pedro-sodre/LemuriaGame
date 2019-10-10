#pragma once
#include "SFML/Graphics.hpp"
#include "Animation.h"

class Player
{
public:
    Player(float speed, const sf::Texture pTexture, sf::Vector2u imageCount, float switchTime);
    ~Player();

    void Update(float deltaTime);
    void inicializa(sf::RectangleShape* player);
    void Draw(sf::RenderWindow& window);

    void setBody(sf::RectangleShape* b);
    sf::RectangleShape* getBody();

    void setTexture(const sf::Texture pTexture);
    //getTexture

    Animation* getAnimation();
    //

    sf::Vector2f getPosition() const { return body->getPosition(); }

private:
    sf::RectangleShape* body;
    float speed;
    unsigned int row;
    sf::Texture playerTexture;
    Animation* animation;
    bool faceRight;
};

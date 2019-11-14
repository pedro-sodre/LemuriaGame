#pragma once
#include <SFML/Graphics.hpp>

#include "Animation.h"

#include <vector>
using std::vector;

class TexturePack
{
public:
    TexturePack(vector<sf::Texture> textura, vector<sf::Vector2u> vector2u, vector<Animation *> animacao);
    virtual ~TexturePack();

    TexturePack();

    void setTexture(const vector<sf::Texture> text);
    vector<sf::Texture> getTexture();

    void setVector(const vector<sf::Vector2u> vec);
    vector<sf::Vector2u> getVector();

    void setAnimation(const vector<Animation *> anima);
    vector<Animation *> getAnimation();

private:
    vector<sf::Texture> textura;
    vector<sf::Vector2u> vector2u;
    vector<Animation *> animacao;

};

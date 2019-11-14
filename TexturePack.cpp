#include "TexturePack.h"

TexturePack::TexturePack(vector<sf::Texture> textura, vector<sf::Vector2u> vector2u, vector<Animation *> animacao)
{
    this->textura  = textura;
    this->vector2u = vector2u;
    this->animacao = animacao;
}

TexturePack::TexturePack()
{
}

TexturePack::~TexturePack()
{
}

void TexturePack::setTexture(const vector<sf::Texture> text)
{
    textura = text;
}

vector<sf::Texture> TexturePack::getTexture()
{
    return textura;
}

void TexturePack::setVector(const vector<sf::Vector2u> vec)
{
    vector2u = vec;
}

vector<sf::Vector2u> TexturePack::getVector()
{
    return vector2u;
}

void TexturePack::setAnimation(const vector<Animation *> anima)
{
    animacao = anima;
}

vector<Animation *> TexturePack::getAnimation()
{
    return animacao;
}

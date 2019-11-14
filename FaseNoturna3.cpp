#include "FaseNoturna3.h"

FaseNoturna3::FaseNoturna3(sf::Vector2f tam):
Fase(tam)
{
    if(!texture.loadFromFile("data/Fase3.png"))
        std::cout << "Erro ao carregar a textura da FaseNoturna3" << std::endl;

    body->setTexture(&texture);
    this->executar();
}

FaseNoturna3::~FaseNoturna3()
{

}

void FaseNoturna3::Draw(sf::RenderWindow& window)
{
    window.draw(*body);
}

void FaseNoturna3::executar()
{
}



#pragma once
#include <SFML/Graphics.hpp>

class Entidade
{
protected:
    int x;
    int y;
    int id;
    sf::Texture texture;
	//sf::RectangleShape* body;
public:
    Entidade();
    virtual ~Entidade();

    void setX(const int X);
    void setY(const int Y);
    void setID(const int ID);
    int getX() const;
    int getY() const;
    int getID() const;

    virtual int getVida();
    virtual void destruir() = 0;
    virtual void executar(float deltaTime) = 0;
    virtual void Draw(sf::RenderWindow& window) = 0;
};


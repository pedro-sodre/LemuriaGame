#include "Lemurya.h"


Lemurya::Lemurya()
{
	this->inicializar();
	this->inicializarStates();
	deltaTime = 0;
}
Lemurya::~Lemurya()
{
	//Remove o estado e o ponteiro dele
	while (!states.empty()) {
		popState();
	}
}

void Lemurya::pushState(State* state)
{
	states.push(state);
}

void Lemurya::popState()
{
	this->states.top();
	delete this->states.top();
	this->states.pop();
}

State* Lemurya::stateAtual()
{
	if (states.empty())
		return nullptr;
	else
		return states.top();
}

void Lemurya::inicializar()
{
	window.create(sf::VideoMode(1280.0f, 720.0f), "Lemurya");
	window.setFramerateLimit(60);

	sf::Image icon;
	icon.loadFromFile("data/LemuryaIcon.JPG");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void Lemurya::inicializarStates()
{
	states.push(new Menu(this));
}

void Lemurya::rodar()
{
	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		if (stateAtual() == nullptr)
			continue;

		//Pega os inputs do state atual
		stateAtual()->input();

		//Atualiza o state atual
		stateAtual()->update();

		//clear window
		window.clear();

		//draw anything in the current game state
		stateAtual()->draw();

		window.display();
	}

}

void Lemurya::encerrar()
{
	//cout para encerrar
}


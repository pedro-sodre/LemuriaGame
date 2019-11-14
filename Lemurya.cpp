#include "Lemurya.h"


Lemurya::Lemurya()
{
	this->inicializar();
	//this->inicializarStates();
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
	states.top();
	delete states.top();
	states.pop();
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
}

void Lemurya::inicializarStates()
{
	//states.push(new Menu(this));
}

void Lemurya::atualizarEventosSfml()
{
	while (window.pollEvent(eventos))
	{
		if (eventos.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

void Lemurya::rodar()
{	
	while (window.isOpen())
	{
		this->atualizarEventosSfml();

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

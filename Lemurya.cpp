#include "Lemurya.h"
#include "MenuPrincipal.h"

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
	//delete this->states.top();
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

    player1.inicializa(200.0f, 200.0f, gerenciadorGrafico.getTexturePlayer1(), gerenciadorGrafico.getVecPlayer1(), 0.2f);
   // gerenciadorDePontuacao.inicializa(this);         EST� SENDO FEITO NA FASE
}

void Lemurya::inicializarStates()
{
	states.push(new MenuPrincipal(this));
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

GerenciadorGrafico Lemurya::getGerenciadorGrafico() const
{
    return gerenciadorGrafico;
}

Player* Lemurya::getPlayer1()
{
    return &(player1);
}
/*
GerenciadorDePontuacao* Lemurya::getGerenciadorDePontuacao()
{
    return gerenciadorDePontuacao;
}*/

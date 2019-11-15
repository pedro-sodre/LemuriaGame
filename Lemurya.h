#pragma once
#include "Fase.h"
#include "State.h"
#include <stack>

class Lemurya {
	private:

		sf::Event eventos;

		std::stack<State*> states;
		void inicializar();
		void inicializarStates();

		sf::Clock clock;

	public:
		Lemurya();
		~Lemurya();

		float deltaTime;            ///PECADO
		sf::RenderWindow window;    ///PECADO

		void pushState(State* state);
		void popState();
		State* stateAtual();

		void rodar();

		void encerrar();
};


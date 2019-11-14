#pragma once
#include "FaseAquatica1.h"
#include "FaseAquatica2.h"
#include "FaseNoturna3.h"
#include "State.h"
#include <stack>
class State;

class Lemurya {
	private:
		
		sf::Event eventos;

		std::stack<State*> states;
		void inicializar();
		void inicializarStates();
	public:
		Lemurya();
		~Lemurya();

		sf::RenderWindow window;

		void pushState(State* state);
		void popState();
		State* stateAtual();

		void atualizarEventosSfml();
		void rodar();

		void encerrar();
};
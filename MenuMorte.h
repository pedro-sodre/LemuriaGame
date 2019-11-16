#pragma once
#include "Menu.h"

class MenuMorte: public Menu
{
private:

public:
	MenuMorte(Lemurya* jogo);
	~MenuMorte();

	//Métodos de State
	void draw();
	void input();
	void update();

	void inicializar();

	void MoveDown();
};

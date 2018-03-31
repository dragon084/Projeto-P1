// Projeto-P1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Veiculos.h"
#include "Carro.h"
#include "Moto.h"
#include "Caminhao.h"
#include "Mundo.h"


int main()
{
	// redimensiona console
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, 1090, 745, TRUE); // 1100 width, 600 height

	// impede que usuario redimensione console
	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

	// instancia mundo
	Mundo m = Mundo();
	int max_x = m.get_tamanho_x();
	int max_y = m.get_tamanho_y();

	// intancia objetos dinâmicos (heap)
	vector<Carro*> car;
	vector<Caminhao*> truck;
	vector<Moto*> bike;

	for (int i = 0; i < 10; i++)
	{
		Carro *c = new Carro(max_x, max_y);
		car.push_back(c);

		Caminhao *t = new Caminhao(max_x, max_y);
		truck.push_back(t);

		Moto *b = new Moto(max_x, max_y);
		bike.push_back(b);
	}
	
	// loop principal
	while (1)
	{
		m.resetMap();
		m.setVeiculos(car, truck, bike);
		m.printMundo();
		m.movimenta(car, truck, bike);

		Sleep(14);
	}

	// deleta os elementos dos vector

    return 0;
}
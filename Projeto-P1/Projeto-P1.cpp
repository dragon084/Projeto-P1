// Projeto-P1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Veiculos.h"
#include "Carro.h"
#include "Moto.h"
#include "Caminhao.h"
#include "Mundo.h"
#include "Random.h"


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

	// instancia objetos
	Random rnd = Random();
	Mundo m = Mundo();
	Carro car = Carro(rnd.generate(0, m.get_tamanho_x()), 
					  rnd.generate(0, m.get_tamanho_y()));
	Caminhao truck = Caminhao(rnd.generate(0, m.get_tamanho_x()),
							  rnd.generate(0, m.get_tamanho_y()));
	Moto bike = Moto(rnd.generate(0, m.get_tamanho_x()), 
					 rnd.generate(0, m.get_tamanho_y()));

	// loop principal
	while (1)
	{
		m.setMundo();
		m.setVeiculos(&car, &truck, &bike);

		m.printMundo();

		m.movimenta(&car, &truck, &bike);

		Sleep(500);
	}

    return 0;
}
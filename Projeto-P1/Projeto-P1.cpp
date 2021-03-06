// Projeto-P1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Veiculos.h"
#include "Carro.h"
#include "Moto.h"
#include "Caminhao.h"
#include "Mundo.h"
#include "Hardware.h"


int main()
{
	// console
	Hardware hw = Hardware();
	hw.init();

	// mundo
	Mundo m = Mundo();

	// vector
	vector<Carro> car;
	vector<Caminhao> truck;
	vector<Moto> bike;

	int max_x = m.get_tamanho_x();
	int max_y = m.get_tamanho_y();

	int n = 10;
	for (int i = 0; i < n; i++)
	{
		Carro c = Carro(max_x, max_y);
		car.push_back(c);

		Caminhao t = Caminhao(max_x, max_y);
		truck.push_back(t);

		Moto b = Moto(max_x, max_y);
		bike.push_back(b);
	}
	
	// loop principal
	while (1)
	{
		m.fabricaVeiculo(car, truck, bike);
		m.colisao(car, truck, bike);

		m.setVeiculos(car, truck, bike);
		m.printMundo(car.size(), truck.size(), bike.size());

		m.movimenta(car, truck, bike);
		m.colisao(car, truck, bike);

		m.resetMap();

		Sleep(16);
		//Sleep(500);
	}

    return 0;
}
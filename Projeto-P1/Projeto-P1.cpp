// Projeto-P1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Random.h"
#include "Veiculos.h"
#include "Carro.h"
#include "Moto.h"
#include "Caminhao.h"


int main()
{
	Carro car = Carro(2, 3, 2, 4);
	Caminhao truck = Caminhao(5, 2, 1, 2000);
	Moto bike = Moto(8, 2, 3, "corrida");
	
	system("pause");
    return 0;
}
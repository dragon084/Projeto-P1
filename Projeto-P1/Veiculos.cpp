#include "stdafx.h"
#include "Veiculos.h"
#include "Random.h"


Veiculos::Veiculos(int tamanho_x, int tamanho_y)
{
	/* cria o ve�culo com posicao (x,y) aleat�ria
	*/
	Random rnd = Random();
	x = rnd.generate(1, tamanho_x-2);
	y = rnd.generate(1, tamanho_y-2);

	v = 0;
	num = 0;
	fabrica = true;
}


Veiculos::~Veiculos()
{
}


int Veiculos::getX()
{
	return x;
}


int Veiculos::getY()
{
	return y;
}


int Veiculos::getV()
{
	return v;
}

bool Veiculos::getFabrica()
{
	return fabrica;
}


void Veiculos::setFabrica(bool f)
{
	fabrica = f;
}

void Veiculos::setX(int x)
{
	this->x = x;
}


void Veiculos::setY(int y)
{
	this->y = y;
}


void Veiculos::setVelocidade(int v)
{
	this->v = v;
}


void Veiculos::move()
{
	/* movimenta o ve�culo aleatoriamente
	   com velocidade v */

	Random rnd = Random();
	int d = rnd.generate(1, 4);

	if (d == 1) 
	{
		for (int i = 0; i < v; i++)
		{
			x++;				// move baixo
		}					
	}
	else if (d == 2) 
	{
		for (int i = 0; i < v; i++)
		{
			x--;				// move cima
		}
	} 
	else if (d == 3)
	{
		for (int i = 0; i < v; i++)
		{
			y++;				// move direita
		}
	}
	else if (d == 4)
	{
		for (int i = 0; i < v; i++)
		{
			y--;				// move esquerda
		}
	}
}

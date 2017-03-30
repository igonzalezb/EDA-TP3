#include "Piso.h"
#include <stdio.h>

bool **nastyGlobalPointer;
unsigned int wp;
unsigned int hp;


Piso::Piso(){}

Piso::Piso(unsigned int width, unsigned int height)
{
	w = width;
	h = height;
	wp = width;
	hp = height;

	//Se reserva la memoria para la matriz de baldozas que componen el piso
	baldo = new bool *[w];
	for (unsigned int i = 0; i < w; i++)
	{
		baldo[i] = new bool[h];
	}
	nastyGlobalPointer = baldo;
	setFloorDirty();

	return;
}

void Piso::setFloorDirty()
{
	for (unsigned int i = 0; i < w; i++)
	{
		for (unsigned int j = 0; j < h; j++)
		{
			baldo[i][j] = false;
		}
	}
	return;
}

bool Piso::getTileState(unsigned int x, unsigned int y)
{
	return nastyGlobalPointer[x][y];
}

bool Piso::isDirty()
{
	for (unsigned int i = 0; i < wp; i++)
	{
		for (unsigned int j = 0; j < hp; j++)
		{
			if (!nastyGlobalPointer[i][j])
			{
				return true;
			}
		}
	}
	return false;
}

void Piso::cleanTile(unsigned int x, unsigned int y)
{
	nastyGlobalPointer[x][y] = true;
}

unsigned int Piso::getH()
{
	return h;
}

unsigned int Piso::getW()
{
	return w;
}

bool Piso::isValid()
{
	if (baldo == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}
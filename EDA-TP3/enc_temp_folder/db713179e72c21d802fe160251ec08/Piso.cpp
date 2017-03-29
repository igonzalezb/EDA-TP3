#include "Piso.h"
#include <stdio.h>

Piso::Piso()
{
	return;
}

Piso::Piso(unsigned int width, unsigned int height)
{
	unsigned int i;
	w = width;
	h = height;

	//Se reserva la memoria para la matriz de baldozas que componen el piso
	baldo = new bool [h * w];
	//for (unsigned int i = 0; i < h; i++)
	//{
	//	baldo[i] = new bool[w];
	//}

	setFloorDirty();

	return;
}

void Piso::setFloorDirty()
{
	for (unsigned int i = 0; i < w * h; i++)
	{
		baldo[i] = false;
	}
	return;
}

bool Piso::getTileState(unsigned int x, unsigned int y)
{
	return baldo[w * y +x];
}

bool Piso::isDirty()
{
	unsigned int i, j;
	for (i = 0; i < w * h; i++)
	{
		if (baldo[i])
		{
			return false;
		}
	}
	return true;
}

void Piso::cleanTile(unsigned int x, unsigned int y)
{
	baldo[w * y + x] = true;
}

unsigned int Piso::getH()
{
	return h;
}

unsigned int Piso::getW()
{
	return w;
}
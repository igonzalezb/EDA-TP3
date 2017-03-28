#include "Piso.h"


Piso::Piso(unsigned int width, unsigned int height)
{
	int i;
	w = width;
	h = height;

	//Se reserva la memoria para la matriz de baldozas que componen el piso
	baldo = new bool *[h];
	for (i = 0; i < w; i++)
	{
		baldo[i] = new bool[w];
	}

	setFloorDirty;

	return;
}

void Piso::setFloorDirty()
{
	int i, j;
	for (i = 0; i < w; i++)
	{
		for (j = 0; j < h; j++)
		{
			baldo[i][j] = false;
		}
	}
	return;
}

bool Piso::getTileState(unsigned int x, unsigned int y)
{
	return baldo[x][y];
}

bool Piso::isDirty()
{
	int i, j;
	for (i = 0; i < w; i++)
	{
		for (j = 0; j < h; j++)
		{
			if (baldo[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

void Piso::cleanTile(unsigned int x, unsigned int y)
{
	baldo[x][y] = true;
	return;
}

unsigned int Piso::getH()
{
	return h;
}

unsigned int Piso::getW()
{
	return w;
}
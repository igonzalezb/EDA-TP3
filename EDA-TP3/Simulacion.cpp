#include "Simulacion.h"

bool Simulacion::nextSimulationStep()
{
	int r;

	if (floor.isDirty)
	{
		for (r = 0; r < robotCount; r++)
		{

		}
	}
}

unsigned long Simulacion::getTicks()
{
	return ticks;
}

unsigned int Simulacion::getRobotCount()
{
	return robotCount;
}

unsigned int Simulacion::getFloorWidth()
{
	return floor.getW;
}

unsigned int Simulacion::getFloorHeight()
{
	return floor.getH;
}

Simulacion::Simulacion(unsigned int robotNumber, unsigned int width, unsigned int height, Graphics *g = NULL)
{
	int i;

	Piso floor(width, height);

	robotCount = robotNumber;
	robot = new Robot[robotCount];
	for (i = 0; i < robotCount; i++)
	{
		robot[i] = Robot(width, height);
	}
	if (g == NULL)
	{
		wantToGraphic = false;
	}
	else
	{
		wantToGraphic = true;
	}
	return;
}
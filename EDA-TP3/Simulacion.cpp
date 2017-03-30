#include "Simulacion.h"
#include "Graphics.h"
#include <stdio.h>

Simulacion::Simulacion(unsigned int _robotCount, unsigned int width, unsigned int height, Graphics *g)
{
	unsigned int i;

	Piso floor(width, height);
	robotCount = _robotCount;

	robot = new Robot[robotCount];
	for (i = 0; i < robotCount; i++)
	{
		robot[i] = Robot(width, height);
	}
	if (g != NULL)
	{
		graph = g;
	}
}

bool Simulacion::nextSimulationStep()
{
	unsigned int i;

	//Al comenzar el "paso" de la simulacion pregunta si esta sucio.
	//si el piso esta sucio incrementa el tick, pq quiere decir que al menos
	//un robot se va a mover (o cambiar el angulo)
	if (wantToGraphic)
	{
		(*graph).graphFloor(floor);
		(*graph).graphRobots(robot, robotCount);
	}
	if (floor.isDirty())
	{
		ticks++;
		for (i = 0; i < robotCount; i++)
		{
			//Pregunta si la baldoza en la que se encuentra el robot esta sucia. Si esta sucia la limpia
			if (!(floor.getTileState((unsigned int)robot[i].getX(), (unsigned int)robot[i].getY())))
			{
				floor.cleanTile((unsigned int)robot[i].getX(), (unsigned int)robot[i].getY());
			}
			//mueve el siguiente robot
			robot[i].moveRobot();
		}
		//LLama a graficar el estado de la simulacion si wantToGraphic = true
		if (wantToGraphic)
		{

			(*graph).graphFloor(floor);
			(*graph).graphRobots(robot, robotCount);
			al_rest(0.1);
		}
		return false;
	}
	else
	{
		//Si el piso esta limpio devuelve TRUE
		/*destroySimulation();*/
		return true;
	}

}

void Simulacion::startGraphing()
{
	wantToGraphic = true;
	return;
}

void Simulacion::stopGraphing()
{
	wantToGraphic = false;
	return;
}

bool Simulacion::amIgraphing()
{
	return wantToGraphic;
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
	return floor.getW();
}

unsigned int Simulacion::getFloorHeight()
{
	return floor.getH();
}

void Simulacion::destroySimulation()
{
	if (wantToGraphic)
	{
		(*graph).destroyGraphics();
	}
}
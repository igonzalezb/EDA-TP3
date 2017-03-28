#include "Simulacion.h"

bool Simulacion::nextSimulationStep()
{
	int i;

	//Al comenzar el "paso" de la simulacion pregunta si esta sucio.
	//si el piso esta sucio incrementa el tick, pq quiere decir que al menos
	//un robot se va a mover (o cambiar el angulo)
	if (floor.isDirty)
	{
		ticks++;
	}

	for (i = 0; i < robotCount; i++)
	{
		//antes de mover cada robot, pregunta si el piso esta sucio
		if (floor.isDirty)
		{
			//mueve el siguiente robot
			robot[i].moveRobot;
			//Pregunta si la baldoza en la que se encuentra el robot esta sucia. Si esta sucia la limpia
			if (!(floor.getTileState((unsigned int)robot[i].getX, (unsigned int)robot[i].getY)))
			{
				floor.cleanTile((unsigned int)robot[i].getX, (unsigned int)robot[i].getY);
			}
		}
		else
		{
			//Si el piso esta limpio, devuelve true para indicar que finaliza la simulacion.
			return true;
		}
	}
	//Si el piso sigue sucio al moverse el ultimo robot, devuelve false para indicar que
	//se debe seguir limpiano
	return false;

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
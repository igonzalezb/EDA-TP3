#ifndef _SIMULACION_H
#define _SIMULACION_H

#include "Robot.h"
#include "Piso.h"
#include "Graphics.h"

class simulacion
{

private:
	unsigned int robotCount;
	unsigned long ticks;
	piso p;
	Robot *r;						//arreglo de clases de robot
	bool wantToGraphic;
	graphics *graph;

public:

	bool nextSimulationStep();		//if finished -> true
	unsigned long getTicks();
	unsigned int getRobotCount();
	unsigned int getFloorWidth();
	unsigned int getFloorHeight();
	void startGraphing();
	void stopGraphing();
	bool amIgraphing();

	simulacion(unsigned int robotCount, unsigned int width, unsigned int height, graphics* g = NULL);		//Dos constructores distintos uno con los tres primeros y otro con todos

};


#endif // !_SIMULACION_H


#ifndef _SIMULACION_H
#define _SIMULACION_H

#include "Robot.h"
#include "Piso.h"
#include "Graphics.h"

class Simulacion
{

private:
	unsigned int robotCount;
	unsigned long ticks;
	Piso p;
	Robot *r;						//arreglo de clases de robot
	bool wantToGraphic;
	Graphics *graph;

public:

	bool nextSimulationStep();		//if finished -> true
	unsigned long getTicks();
	unsigned int getRobotCount();
	unsigned int getFloorWidth();
	unsigned int getFloorHeight();
	void startGraphing();
	void stopGraphing();
	bool amIgraphing();
	Simulacion(unsigned int robotCount, unsigned int width, unsigned int height, Graphics* g = NULL);		//Dos constructores distintos uno con los tres primeros y otro con todos

};


#endif // !_SIMULACION_H


#pragma once

#ifndef _SIMULACION_H
#define _SIMULACION_H

#include "Piso.h"
#include "Robot.h"
#include "Graphics.h"

class Simulacion
{
private:

	unsigned int robotCount;
	unsigned long ticks;
	Piso floor;
	Robot *robot;
	Graphics *graph;
	bool wantToGraphic;

public:

	Simulacion(unsigned int _robotCount, unsigned int width, unsigned int height, Graphics* g = NULL);		//Dos constructores distintos uno con los tres primeros y otro con todos

	bool nextSimulationStep();		//if finished -> true
	unsigned long getTicks();
	unsigned int getRobotCount();
	unsigned int getFloorWidth();
	unsigned int getFloorHeight();
	void startGraphing();
	void stopGraphing();
	bool amIgraphing();
};
#endif // !_SIMULACION_H





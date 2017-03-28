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
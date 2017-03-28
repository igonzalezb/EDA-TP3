
#include "Simulacion.h"


Simulacion::Simulacion(unsigned int robot, unsigned int w, unsigned int h, Graphics* = NULL)
{
	r = new Robot(w, h)[rc];
	p = new Piso(w, h);


	//Obj* array = new Obj[size]; for (int i = 0; i < size; i++) { array[i] = Obj(whatever); }

	if (p.isValid() && (r != NULL))
	{

	}

	else
	{
		delete r[];
		p.destroy();
	}

}

bool Simulacion::nextSimulationStep()	//if finished -> true
{

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
	return p.ancho;

}
unsigned int Simulacion::getFloorHeight()
{
	return p.altura;
}
void Simulacion::startGraphing()
{

}
void Simulacion::stopGraphing()
{

}
bool Simulacion::amIgraphing()
{
	return wantToGraphic;	//???
}

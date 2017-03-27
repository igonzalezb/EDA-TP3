#ifndef _ROBOT_H
#define _ROBOT_H

#include <stdlib.h>
#include "Point.h"

class Robot
{
private:
	Point robotPoint;
	double angle;
	float stepDistance;
	unsigned int xMax;
	unsigned int yMax;

public:
	//moveRobotToPoint mueve el robot hacia un punto p. Serviria para inicializar el robot
	void moveRobotToPoint(const Point& p);
	//moveRobot toma la info(Angle y p) y mueve el robot al siguiente Punto
	//toda la info esta contenida dentro de la clase una vez que se inicializo
	void moveRobot();
	//Setea el parametro "stepDistance". Si stepDist es mayor a la distancia del centro del piso a un extremo, devuelve 0 y no asigna
	int setStepDistance(float stepDist);
	//El siguiente contructor Robot inicializa el robot en un punto aleatorio 
	Robot(unsigned int w, unsigned int h);
	//Setea "angle" en un angulo aleatorio
	void setRandAngle();
	//setea "angle" en un angulo indicado. Si es invalido devuelve 0 y no asigna, de lo contrario asigna y devuelve 1.
	int setAngle(float ang);
	double getX();
	double getY();
};

#endif // !_ROBOT_H

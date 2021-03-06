#include "Robot.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>

Robot::Robot() {};

Robot::Robot(unsigned int w, unsigned int h)
{
	Point p;

	stepDistance = 1;
	//srand(time(NULL));
	xMax = w;	//setea xMax
	yMax = h;	//setea yMax
	setRandAngle();	//setea random angle
	setRandomPoint();
	
	return;
}

void Robot::moveRobotToPoint(Point& p)
{
	robotPoint.setPoint(p.getX(), p.getY());
	return;
}

void Robot::moveRobot()
{
	//Inicializo un punto auxiliar en el puto a donde deberia moverse el robot.
	Point auxPoint(robotPoint.getX(), robotPoint.getY());
	auxPoint.translatePoint(stepDistance, angle);
	//Verifico si el punto se encuentra dentro del "rectangulo" del piso.
	if ((auxPoint.getX() < 0 || auxPoint.getX() > xMax) || (auxPoint.getY() < 0 || auxPoint.getY() > yMax))
	{
		//Si no se encuentra en el rectangulo del piso, seteo angulo aleatorio
		setRandAngle();
		return;
	}
	else
	{
		//Si el punto es valido (dentro del rectuangulo) translado el robot.
		robotPoint.translatePoint(stepDistance, angle);
		return;
	}
}

void Robot::setRandomPoint()
{
	Point auxPoint;
	auxPoint.randomPoint(xMax, yMax);
	moveRobotToPoint(auxPoint);
}

double Robot::getX()
{
	return robotPoint.getX();
}

double Robot::getY()
{
	return robotPoint.getY();
}

int Robot::setAngle(float ang)
{
	if (ang < 360)
	{
		angle = ang;
		return 1;
	}
	else
	{
		return 0;
	}
}

void Robot::setRandAngle()
{
	//srand(time(NULL));
	angle = rand() % 360;

	return;
}

int Robot::setStepDistance(float stepDist)
{
	if (stepDist < (sqrt((xMax)*(xMax)+(yMax)*(yMax)) / 2))
	{
		stepDistance = stepDist;
		return 1;
	}
	else
	{
		return 0;
	}
}

double Robot::getAngle()
{
	return angle;
}

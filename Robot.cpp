#include "Robot.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>

Robot::Robot(unsigned int w, unsigned int h)
{
	Point p;

	srand(time(NULL));
	xMax = w;	//setea xMax
	yMax = h;	//setea yMax
	setRandAngle;	//setea random angle
	p.randomPoint(xMax, yMax);	//setea p random
	moveRobotToPoint(p);	//setea robotPoint en punto random

	return;
}

void Robot::moveRobotToPoint(const Point& p)
{
	robotPoint.setPoint(p.getX, p.getY);

	return;
}

void Robot::moveRobot()
{
	robotPoint.translatePoint(stepDistance, angle);
	return;
}

double Robot::getX()
{
	return robotPoint.getX;
}

double Robot::getY()
{
	return robotPoint.getY;
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
	srand(time(NULL));
	angle = 360 * ((double)rand() / RAND_MAX);

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
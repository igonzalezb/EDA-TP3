#include "Point.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>

Point::Point()
{
	x = 0;
	y = 0;
	return;
}

Point::Point(double xCord, double yCord)
{
	setPoint(xCord, yCord);
	return;
}
 
double Point::getDistanceBetweenPoints(Point p)
{
	double distance;
	distance = sqrt((x - p.x)*(x - p.x) + (y - p.y)*(y - p.y));
	return distance;
}

double Point::getAngleBetweenPoints(Point p)
{
	double alpha, op, ady;
	op = (p.x - x);
	ady = (p.y - y);
	alpha = atan(op / ady);
	if (alpha < 0 || op < 0 || ady < 0)
	{
		alpha += 180;
	}
	return alpha;
}

void Point::translatePoint(double distance, double angle)
{
	x += distance*sin(angle);
	y += distance*cos(angle);
}

bool Point::isPointEqual(Point p)
{
	if (getAngleBetweenPoints(p) < E)
	{
		return true;
	}
	return false;
}

double Point::getX()
{
	return x;
}

double Point::getY()
{
	return y;
}

void Point::randomPoint(unsigned int xMax, unsigned int yMax)
{
	srand(time(NULL));

	x = xMax*((double)rand() / RAND_MAX);
	y = yMax*((double)rand() / RAND_MAX);

	return;
}

void Point::setPoint(double xCord, double yCord)
{
	x = xCord;
	y = yCord;

	return;
}
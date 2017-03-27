#ifndef _POINT_H
#define	_POINT_H

#define E 0.0000001

class Point
{
private:

	double x;
	double y;

public:

	double getAngleBetweenPoints(Point p);
	double getDistanceBetweenPoints(Point p);
	void translatePoint(double distance, double angle);
	bool isPointEqual(Point p);
	double getX();
	double getY();
	void setPoint(double xCord, double yCord);
	//randomPoint genera un punto aleatorio con x < xMax e y < yMax
	void randomPoint(unsigned int xMax, unsigned int yMax);
	//El constructor Point inicializa el punto en x = 0, y = 0
	Point();
	//El siguiente constructor inicializa x = xCord, y = yCord;
	Point(double xCord, double yCord);
};
#endif // !_POINT_H


#include <iostream>


class point
{
public:
	double x;
	double y;
	
};


class Robot
{

private:
	point p;
	double angle;
	unsigned int xmax;
	unsigned int ymax;

public:
	void moveRobotToPoint (const point& p);
	void moveRobot ();
	Robot(unsigned int xmax, unsigned int ymax);
	double getX ();
	double getY ();

};



void graf ()
{
	al_draw_bitmap(roboImg, 
				(r[0].getX()) * tamaño X de Baldosa,
				(r[0].getY()) * tamaño Y de Baldosa);
}

class piso
{

private:
	bool * baldo;
	unsigned int ancho;
	unsigned int alto;

public:


	 piso(unsigned int ancho, unsigned int alto);
	 bool isDirty();									//devuelve si esta limpio o sucio
	 bool cleanTile (unsigned int x, unsigned int y);
	 bool getTileState (unsigned int x, unsigned int y);
	 bool isValid();		//dice si baldose da NULL

	
};
//=============================================================================================================================
//simulacion.h
//==============================================================================================================================

#include <robot.h>
#include <piso.h>
#include <graphics.h>

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

//=========================================================================================================================
//simulacion.cpp
//=========================================================================================================================

#include <simulacion.h>


simulacion :: simulacion(unsigned int robot, unsigned int w, unsigned int h, graphics* = NULL)
{
	r = new Robot(w,h)[rc];
	p = new piso(w,h);

	if(p.isValid() && (r != NULL))
	{

	}

	else
	{
		delete r[];
		p.destroy();
	}

}



int main (int argc, char* argv[])
{
	
	//valido parametros

	//inicializo allegro

	srand(time(NULL));		//en otro lado

	if (modo == 1)
	{
		simulacion s(a.robot, a.ancho, a.alto, &g);	//A=Argumentos
		s.startGraphing();
		while(!s.nextSimulationStep());
		cout << "tardo " << s.getTicksCount() << endl;
		s.destroy();
	}

	else if (modo == 2)
	{
		
		double meanTicks[100] = {0........0};

		for (int robs=1; (robs<100) && (n y n+1 sean mayor de...0.1); robs++)
		{

			for(int ciclos = 0; ciclos < 1000; ciclos++)
			{
				simulacion S(robs, arg_ancho, arg_largo);
				while(!S.nextSimulationStep());
				meanTicks[robs-1] += getTicksCount();
				s.destroy();
			}

			meanTicks[robs-1] /= 1000.0;
			graficoParcial(meanTicks);

		}
	}




	////////////////////////////////////////////
	graphics g(???);
	simulacion s1(1,5,5);
	simulacion s2(1,5,5, &graphics);
	/////////////////////////////////////////////

	return 0;
}
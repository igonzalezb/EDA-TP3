#include <iostream>


void graf ()
{
	al_draw_bitmap(roboImg, 
				(r[0].getX()) * tamaño X de Baldosa,
				(r[0].getY()) * tamaño Y de Baldosa);
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
extern "C" 
{
	#include "parseCmdLine.h"
}
#include <iostream>
#include <time.h>
#include "Simulacion.h"
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_color.h>
#include <allegro5\allegro_image.h>

#define ERROR		-1
#define SCREEN_W	800
#define SCREEN_H	600

int allegro_setup(void);
void al_configuration_end(void);


using namespace std;

//void graf ()
//{
//	al_draw_bitmap(roboImg, 
//				(r[0].getX()) * tamaño X de Baldosa,
//				(r[0].getY()) * tamaño Y de Baldosa);
//}



int main (int argc, char* argv[])
{
	
	//valido parametros

	//inicializo allegro


//============================================================================================================
	ALLEGRO_DISPLAY * display = NULL;
	ALLEGRO_DISPLAY_MODE disp_data;
	int min_w, min_h, max_w, max_h;


	ALLEGRO_BITMAP *icon = NULL;
	

	if (allegro_setup() == ERROR)
	{
		printf("Failed to configure and start the simulation");
	}

	//al_get_display_mode(al_get_num_display_modes() - 1, &disp_data);

	//al_set_new_display_flags(ALLEGRO_MAXIMIZED);
	//display = al_create_display(disp_data.width, disp_data.height);

	//al_get_window_constraints(display, &min_w, &min_h, &max_w, &max_h);
	//al_set_window_constraints(display, min_w, min_h, max_w, max_h);

	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "Failed to create display!\n");
		al_configuration_end();
		return ERROR;
	}
	icon = al_load_bitmap("resources/icon.png");
	if (!icon) {
		fprintf(stderr, "Failed to create icon!\n");
		al_destroy_display(display);
		al_configuration_end();
		return ERROR;
	}


	al_set_display_icon(display, icon);
	al_set_window_title(display, "ROBOT_CLEANER");

	al_clear_to_color(al_color_name("white"));
	al_flip_display();
	al_rest(5.0);
	al_configuration_end();

//===========================================================================================================


	////////////////

	srand(time(NULL));		//en otro lado
	int modo;

	if (modo == 1)
	{
		Simulacion s(a.robot, a.ancho, a.alto, &g);	//A=Argumentos
		s.startGraphing();
		while(!s.nextSimulationStep());
		cout << "tardo " << s.getTicks() << endl;
		s.destroy();
	}

	else if (modo == 2)
	{
		
		double meanTicks[100];
		for (int i = 0; i < 100; i++) { meanTicks[i] = 0; }

		for (int robs=1; (robs<100) && (n y n+1 sean mayor de...0.1); robs++)
		{

			for(int ciclos = 0; ciclos < 1000; ciclos++)
			{
				Simulacion S(robs, arg_ancho, arg_largo);
				while(!S.nextSimulationStep());
				meanTicks[robs-1] += getTicksCount();
				s.destroy();
			}

			meanTicks[robs-1] /= 1000.0;
			graficoParcial(meanTicks);

		}
	}




	//////////////////////////////////////////////
	//Graphics g(???);
	//simulacion s1(1,5,5);
	//simulacion s2(1,5,5, &graphics);
	///////////////////////////////////////////////

	return 0;
}










int allegro_setup(void)
{
	if (!al_init())
	{
		fprintf(stderr, "Failed to initialize allegro!\n");

		return ERROR;
	}

	if (!al_init_primitives_addon())
	{
		fprintf(stderr, "Failed to initialize the primitives!\n");

		al_uninstall_system();

		return ERROR;
	}
	if (!al_init_image_addon()) {
		fprintf(stderr, "Failed to initialize image addon !\n");
		al_shutdown_primitives_addon();
		al_uninstall_system();
		return ERROR;
	}

	return 0;
}

void al_configuration_end(void)
{
	al_uninstall_system();

	al_shutdown_primitives_addon();

	al_shutdown_image_addon();


}

extern "C" 
{
	#include "parseCmdLine.h"
}
#include <iostream>
#include <time.h>
#include "Simulacion.h"
#include "Callback.h"
#include "Graphics.h"
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_color.h>
#include <allegro5\allegro_image.h>
#include <allegro5\keyboard.h>
#include <allegro5\events.h>

#define ERROR		-1
#define SCREEN_W	800
#define SCREEN_H	600

int allegro_setup(void);
void al_configuration_end(void);
typedef int(*pCallback) (char *, char*, void *);
void waitForKeypress();

using namespace std;

int main (int argc, char* argv[])
{
	pCallback p = &Callback;
	parametros_t userData;

	userData.init_modo = false;
	userData.init_CantRobots = false;
	userData.init_h = false;
	userData.init_w = false;
	
	
	if (parseCmdLine(argc, argv, p, &userData) == ERROR)
	{
		printf("PARSER ERROR\n");
	}
	if (validacionUsuario(userData) == ERROR)
	{
		printf("INPUT ERROR\n");
		return ERROR;
	}

	srand(time(NULL));

	//inicializo allegro

//============================================================================================================
	//ALLEGRO_DISPLAY * display = NULL;
	////ALLEGRO_DISPLAY_MODE disp_data;
	//
	//ALLEGRO_BITMAP *icon = NULL;
	//ALLEGRO_BITMAP *img1 = NULL;
	//ALLEGRO_BITMAP *img2 = NULL;
	//
	//

	if (allegro_setup() == ERROR)
	{
		printf("Failed to configure and start the simulation");
	}

	//display = al_create_display(SCREEN_W, SCREEN_H);
	//if (!display) {
	//	fprintf(stderr, "Failed to create display!\n");
	//	al_configuration_end();
	//	return ERROR;
	//}
	//icon = al_load_bitmap("resources/icon.png");
	//if (!icon) {
	//	fprintf(stderr, "Failed to create icon!\n");
	//	al_destroy_display(display);
	//	al_configuration_end();
	//	return ERROR;
	//}


	//al_set_display_icon(display, icon);
	//al_set_window_title(display, "R2D2_CLEANER");

	//img1 = al_load_bitmap("resources/img1.png");
	//if (!img1) {
	//	fprintf(stderr, "Failed to create img1!\n");
	//	al_destroy_display(display);
	//	al_configuration_end();
	//	return ERROR;
	//}
	//img2 = al_load_bitmap("resources/img2.jpg");
	//if (!img2) {
	//	fprintf(stderr, "Failed to create img2!\n");
	//	al_destroy_display(display);
	//	al_configuration_end();
	//	return ERROR;
	//}


	//al_clear_to_color(al_color_name("black"));
	//al_draw_scaled_bitmap(img1, 0.0, 0.0, al_get_bitmap_width(img1), al_get_bitmap_height(img1), 0.0, 0.0, al_get_display_width(display), al_get_display_height(display), 0);
	//al_flip_display();
	//al_rest(1.5);

	//for (int i = 1; i > 0 && (al_get_bitmap_width(img2) > 1000); i++)
	//{
	//	al_clear_to_color(al_color_name("black"));
	//	al_draw_scaled_bitmap(img2, 0.0, 0.0, al_get_bitmap_width(img2), al_get_bitmap_height(img2), 0.0, 0.0, al_get_bitmap_width(img2)/i, al_get_bitmap_height(img2)/i, 0);
	//	al_rest(0.2);
	//	al_flip_display();
	//}

	//al_flip_display();

//===========================================================================================================
	


		
	if (userData.modo == MODO1)
	{
		Graphics g(userData.w, userData.h);
		Simulacion s(userData.cantRobots, userData.w, userData.h, &g);	//A=Argumentos
		s.startGraphing();
		while(!s.nextSimulationStep());
		waitForKeypress();
		cout << "tardo " << s.getTicks() << endl;
		s.destroySimulation();
	}

	else if (userData.modo == MODO2)
	{
		
		double meanTicks[100];
		unsigned int ticksCount;
		for (int i = 0; i < 100; i++) { meanTicks[i] = 0; }

		unsigned int robs = 1;
		ticksCount = 0;
		for (int ciclos = 0; ciclos < 1000; ciclos++)
		{
			Simulacion S(robs, userData.w, userData.h, NULL);
			while (!S.nextSimulationStep());
			ticksCount += S.getTicks();
			S.destroySimulation();
		}
		meanTicks[robs - 1] = (double)ticksCount / 1000.0;
		cout << "ticks[" << robs << "] = " << ticksCount << endl;
		cout << "meanTicks[" << robs << "] = " << meanTicks[robs - 1] << endl << endl;
		do
		{
			robs++;
			ticksCount = 0;
			for (int ciclos = 0; ciclos < 1000; ciclos++)
			{
				Simulacion S(robs, userData.w, userData.h, NULL);
				while (!S.nextSimulationStep());
				ticksCount += S.getTicks();
				S.destroySimulation();
			}
			meanTicks[robs - 1] = (double)ticksCount / 1000.0;
			cout << "ticks[" << robs << "] = " << ticksCount << endl;
			cout << "meanTicks[" << robs << "] = " << meanTicks[robs - 1] << endl;
			cout << "dif = " << fabs(meanTicks[robs - 2] - meanTicks[robs - 1]) << endl << endl;

		} while ((robs < 100) && (fabs(meanTicks[robs - 2] - meanTicks[robs - 1]) > 0.1));
		Graphics g2(robs, meanTicks);
		g2.graphHistogram();
		waitForKeypress();
	
	}
	al_configuration_end();
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

void waitForKeypress()
{
	ALLEGRO_EVENT_QUEUE *event_queue;
	ALLEGRO_EVENT event;

	al_install_keyboard();
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	do
	{
		al_wait_for_event(event_queue, &event);
	} while (event.type != ALLEGRO_EVENT_KEY_DOWN);

	al_destroy_event_queue(event_queue);
}

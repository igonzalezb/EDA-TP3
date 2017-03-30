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
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>

#define ERROR		-1

int allegro_setup(void);
void al_configuration_end(void);
typedef int(*pCallback) (char *, char*, void *);
void waitForKeypress();
void al_print_text(const char * text);

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
		return ERROR;
	}

	if (validacionUsuario(userData) == 0)
	{
		printf("INPUT ERROR\n");
		return ERROR;
	}

	srand(time(NULL));
	
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
		cout << "Tardo: " << s.getTicks() << endl;
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

	al_install_keyboard();

	al_init_font_addon();

	al_init_ttf_addon();



	return 0;
}

void al_configuration_end(void)
{
	al_uninstall_system();

	al_shutdown_primitives_addon();

	al_shutdown_image_addon();

	al_shutdown_font_addon();

}

void waitForKeypress()
{
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_EVENT event;
	
	
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_print_text("PRESS ANY KEY TO EXIT");
	
	//cout << "PRESS ANY KEY TO EXIT" << endl;

	do
	{
		al_wait_for_event(event_queue, &event);
	} while (event.type != ALLEGRO_EVENT_KEY_DOWN);

	al_destroy_event_queue(event_queue);
	

}

void al_print_text(const char * text)
{
	ALLEGRO_FONT *font = NULL;
	font = al_load_font("resources/atari.ttf", 10, 0);
	if (!font) {
		fprintf(stderr, "Could not load 'atari.ttf'.\n");
	}
	al_draw_text(font, al_color_name("black"), 100, 100, 0, text);
	al_flip_display();
	//al_destroy_font(font);
}

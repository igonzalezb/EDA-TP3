////////////////////////////////////////////////////////////////////////////////////////////////////////////////														
//
//		Instituto Tecnológico de Buenos Aires.			
//									   /////////////// 							
//		22.08 - Algoritmos y Estructura de Datos.		  //  ROBOTS   //							
//									 ///////////////							
//		Trabajo Práctico n° 3.																		
//																									
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////														
//																										
//																										
//	Consigna: 																								
//																									
//	Se pide simular un robot limpia-pisos.						
//																									
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																									
//	GRUPO 4																							
//																									
//	***********************************************														
//	||	AUTORES		        ||  LEGAJO   ||																	
//	***********************************************														
//	|| Álvarez, Lisandro		||  57.771   ||														
//	|| Gonzalez Bigliardi, Iñaki    ||  57.098   ||														
//	|| Navarro, Paulo		||  57.775   ||														
//	***********************************************														
//																									
//	Fecha de entrega: jueves 30 de marzo de 2017.												
//																									
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
#include <allegro5\keyboard.h>
#include <allegro5\events.h>

#define ERROR		-1
#define RESERVED_SAMPLES 2

int allegro_setup(void);
void al_configuration_end(void);
typedef int(*pCallback) (char *, char*, void *);
void waitForKeypress();

using namespace std;

int main (int argc, char* argv[])
{
	pCallback p = &Callback;
	parametros_t userData;

	userData.init_modo = false;		//Inicializo en falso
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
	
	if (allegro_setup() == ERROR)
	{
		printf("Failed to configure the simulation");
	}
			
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

	if (!al_install_keyboard())
	{
		fprintf(stderr, "failed to initialize audio!\n");
		al_shutdown_primitives_addon();
		al_shutdown_image_addon();
		al_uninstall_system();
		return ERROR;
	}

	if (!al_install_audio())
	{
		fprintf(stderr, "failed to initialize audio!\n");
		al_uninstall_keyboard();
		al_shutdown_primitives_addon();
		al_shutdown_image_addon();
		al_uninstall_system();
		return ERROR;
	}
	if (!al_init_acodec_addon())
	{
		fprintf(stderr, "failed to initialize audio codecs!\n");
		al_uninstall_audio();
		al_uninstall_keyboard();
		al_shutdown_primitives_addon();
		al_shutdown_image_addon();
		al_uninstall_system();
		return ERROR;
	}
	if (!al_reserve_samples(RESERVED_SAMPLES))
	{
		fprintf(stderr, "failed to reserve samples!\n");
		al_uninstall_audio();
		al_uninstall_keyboard();
		al_shutdown_primitives_addon();
		al_shutdown_image_addon();
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
	
	al_uninstall_audio();
	
	al_uninstall_keyboard();
	
}

void waitForKeypress()
{
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_EVENT event;


	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	

	cout << "PRESS ANY KEY TO EXIT" << endl;

	do
	{
		al_wait_for_event(event_queue, &event);
	} while (event.type != ALLEGRO_EVENT_KEY_DOWN);

	al_destroy_event_queue(event_queue);


}
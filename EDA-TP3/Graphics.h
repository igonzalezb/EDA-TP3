#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <allegro5\allegro.h>
#include "Robot.h"

class Graphics
{
private:

	
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_DISPLAY_MODE dispData;
	ALLEGRO_BITMAP  *robotImg = NULL;
	ALLEGRO_BITMAP *baldosaImg = NULL;
	ALLEGRO_BITMAP *baldosaSuciaImg = NULL;
	
	unsigned int width;
	unsigned int height;

	float xRes;
	float yRes;

	void loadImages();

public:
	
	Graphics();
	Graphics(unsigned int xMax, unsigned int yMax);
	//Para graficar el piso hay que tener en cuenta la cantidad de cuadrados que se van a dibujar verticlamente
	//y horizontalmente para darles formato CUADRADO

	//void graphFloor(bool *floor);
	

};


#endif // !_GRAPHICS_H


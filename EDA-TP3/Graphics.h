#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <stdio.h>
#include <allegro5\allegro.h>
#include <allegro5\display.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include "Robot.h"
#include "Piso.h"

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
	void graphFloor(Piso piso);
	void graphRobots(Robot *robot, unsigned int robotCount);
	void destroyGraphics();

};


#endif // !_GRAPHICS_H


#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <stdio.h>
#include <allegro5\allegro.h>
#include <allegro5\display.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
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
	ALLEGRO_SAMPLE *sample = NULL;
	ALLEGRO_BITMAP *icon = NULL;
	ALLEGRO_BITMAP *img1 = NULL;

	unsigned int width;
	unsigned int height;

	unsigned int robs;
	double *meanTicks;

	float xRes;
	float yRes;

	void loadImages();

public:
	
	Graphics();
	Graphics(unsigned int _robs, double *_meanTicks);
	Graphics(unsigned int xMax, unsigned int yMax);
	//Graphics(unsigned int _robs, float * _meanTicks);
	void graphFloor(Piso& piso);
	void graphRobots(Robot *robot, unsigned int robotCount);
	void graphHistogram();
	void destroyGraphics();

};


#endif // !_GRAPHICS_H


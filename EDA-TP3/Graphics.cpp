#include "Graphics.h"


Graphics::Graphics(unsigned int xMax, unsigned int yMax)
{
	width = xMax;
	height = yMax;
	
	createDisplay();
	
	xRes = width / dispData.width;
	yRes = height / dispData.height;

	loadImages();

	return;
}

void Graphics::loadImages()
{
	robotImg = al_load_bitmap("resources/r2d2.png");
	baldosaImg = al_load_bitmap("resources/baldosa.png");
	baldosaSuciaImg = al_load_bitmap("resources/baldosa_sucia.png");
	return;
}

void Graphics::createDisplay()
{
	al_get_display_mode(al_get_num_display_modes() - 1, &dispData);
	display = al_create_display(dispData.width, dispData.height);
	return;
}


#include "Graphics.h"

Graphics::Graphics() {}

Graphics::Graphics(unsigned int _robs, double * _meanTicks)
{
	double temp = 0;
	robs = _robs;
	meanTicks = new double[robs];
	for (unsigned int i = 0; i < robs; i++)
	{
		meanTicks[i] = _meanTicks[i];
		if (meanTicks[i] > temp)
		{
			temp = meanTicks[i];
		}
	}
	width = robs;
	height = temp + 2;

	al_get_display_mode(al_get_num_display_modes() - 5, &dispData);

	display = al_create_display(dispData.width, dispData.height);
	if (!display)
	{
		fprintf(stderr, "Falied to create display\n");
	}

	icon = al_load_bitmap("resources/icon.png");
	if (!icon) {
		fprintf(stderr, "Failed to create icon!\n");
		al_destroy_display(display);
	}


	al_set_display_icon(display, icon);
	al_set_window_title(display, "R2D2_CLEANER");
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();

	xRes = (double)width / (double)dispData.width;
	yRes = (double)height / (double)dispData.height;

}

Graphics::Graphics(unsigned int xMax, unsigned int yMax)
{
	unsigned int anchoPantalla, altoPantalla;
	double relation, screenRelation;
	width = xMax;
	height = yMax;
	//Obtiene la info del display
	al_get_display_mode(al_get_num_display_modes() - 5, &dispData);
	//Calcula las relaciones de las dimensiones del piso y del display
	relation = ((double)height / (double)width);
	screenRelation = ((double)dispData.height / (double)dispData.width);
	//Si la relacion del piso (y/x) es mayor a la del display, ajusta el ancho del display
	if (relation > screenRelation)
	{
		altoPantalla = dispData.height;
		anchoPantalla = altoPantalla * ((double)width / (double)height);
	}
	//Si la relacion del piso es menor a la del display, ajusta el alto del display
	else
	{
		anchoPantalla = dispData.width;
		altoPantalla = anchoPantalla * ((double)height / (double)width);
	}
	//Crea el display y lo inicializa en negro
	display = al_create_display(anchoPantalla, altoPantalla);
	if (!display)
	{
		fprintf(stderr, "Falied to create display\n");
	}
	
	
	al_set_window_title(display, "R2D2_CLEANER");
	
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	//Define las resoluciones de la pantalla
	xRes = (double)width / anchoPantalla;
	yRes = (double)height / altoPantalla;

	//Carga las imagenes
	loadImages();
	al_set_display_icon(display, icon);
}

void Graphics::loadImages()
{
	
	robotImg = al_load_bitmap("resources/r2d2.png");
	if (!robotImg)
	{
		fprintf(stderr, "Failed to load r2d2.png\n");
	}
	baldosaImg = al_load_bitmap("resources/baldosa.png");
	if (!baldosaImg)
	{
		fprintf(stderr, "Failed to load baldosa.png\n");
	}
	baldosaSuciaImg = al_load_bitmap("resources/baldosa_sucia.png");
	if (!baldosaSuciaImg)
	{
		fprintf(stderr, "Failed to load baldosa_sucia.png\n");
	}
	icon = al_load_bitmap("resources/icon.png");
	if (!icon) {
		fprintf(stderr, "Failed to create icon!\n");
	}
}

void Graphics::graphFloor(Piso& piso)
{
	for (unsigned int i = 0; i < width; i++)
	{
		for (unsigned int j = 0; j < height; j++)
		{
			if (piso.getTileState(i, j))
			{
				al_draw_scaled_bitmap(baldosaImg, 0, 0, al_get_bitmap_width(baldosaImg), al_get_bitmap_height(baldosaImg), i / xRes, j / yRes, 1 / xRes, 1 / yRes, 0);
			}
			else
			{
				al_draw_scaled_bitmap(baldosaSuciaImg, 0, 0, al_get_bitmap_width(baldosaSuciaImg), al_get_bitmap_height(baldosaSuciaImg), i / xRes, j / yRes, 1 / xRes, 1 / yRes, 0);
			}
		}
	}
}

void Graphics::graphRobots(Robot *robot, unsigned int robotCount)
{
	for (unsigned int i = 0; i < robotCount; i++)
	{
		al_draw_scaled_bitmap(robotImg, 0, 0, al_get_bitmap_width(robotImg), al_get_bitmap_height(robotImg), (robot[i].getX() - 0.25) / xRes, (robot[i].getY() - 0.25) / yRes, 1.2 / xRes, 1.2 / yRes, 0);	
	}
	al_flip_display();
}

void Graphics::graphHistogram()
{
	for (unsigned int i = 0; i < robs; i++)
	{
		al_draw_filled_rectangle(i / xRes, (height - meanTicks[i]) / yRes, (i + 1) / xRes, height / yRes, al_map_rgb(255, 0, 0));
		al_draw_rectangle(i / xRes, (height - meanTicks[i]) / yRes, (i + 1) / xRes, height / yRes, al_map_rgb(255, 255, 255), 2);
		al_flip_display();
		al_rest(0.1);
	}
}

void Graphics::destroyGraphics()
{
	al_destroy_display(display);
	al_destroy_bitmap(baldosaImg);
	al_destroy_bitmap(baldosaSuciaImg);
	al_destroy_bitmap(robotImg);
	al_destroy_bitmap(icon);
}


#include "Graphics.h"

Graphics::Graphics() {}

Graphics::Graphics(unsigned int xMax, unsigned int yMax)
{
	unsigned int anchoPantalla, altoPantalla;
	double relation, screenRelation;
	width = xMax;
	height = yMax;
	//Obtiene la info del display
	al_get_display_mode(al_get_num_display_modes() - 1, &dispData);
	//Calcula las relaciones de las dimensiones del piso y del display
	relation = ((double)height / (double)width);
	screenRelation = ((double)dispData.height / (double)dispData.width);
	//Si la relacion del piso (y/x) es mayor a la del display, ajusta el ancho del display
	if (relation > screenRelation)
	{
		altoPantalla = dispData.height;
		anchoPantalla = altoPantalla * (width / height);
	}
	//Si la relacion del piso es menor a la del display, ajusta el alto del display
	else
	{
		anchoPantalla = dispData.width;
		altoPantalla = anchoPantalla * (height / width);
	}
	//Crea el display y lo inicializa en negro
	display = al_create_display(anchoPantalla, altoPantalla);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	//Define las resoluciones de la pantalla
	xRes = (double)width / anchoPantalla;
	yRes = (double)height / altoPantalla;

	//Carga las imagenes
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

void Graphics::graphFloor(Piso piso)
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
	al_flip_display();
	return;
}

void Graphics::graphRobots(Robot *robot, unsigned int robotCount)
{
	for (unsigned int i = 0; i < robotCount; i++)
	{
		al_draw_scaled_bitmap(robotImg, 0, 0, al_get_bitmap_width(robotImg), al_get_bitmap_height(robotImg), (robot[i].getX() + 0.5) / xRes, (robot[i].getY() + 0.5) / yRes, 1 / xRes, 1 / yRes, 0);
		al_flip_display();
	}
	return;
}

void Graphics::destroyGraphics()
{
	al_destroy_bitmap(baldosaImg);
	al_destroy_bitmap(baldosaSuciaImg);
	al_destroy_bitmap(robotImg);
	al_destroy_display(display);
	return;
}
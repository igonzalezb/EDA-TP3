#include "Graphics.h"


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


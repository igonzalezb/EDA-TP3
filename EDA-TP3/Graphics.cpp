#include "Graphics.h"


Graphics::Graphics()
{

	return;
}

bool Graphics::createDisplay()
{
	al_get_display_mode(al_get_num_display_modes() - 1, &dispData);
	display = al_create_display(dispData.width, dispData.height);

	if (display == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Graphics::graphFloor()
{
	robotImg = al_load_bitmap("resources/r2d2.png");

}
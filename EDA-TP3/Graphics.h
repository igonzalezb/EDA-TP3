#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include "Robot.h"
#include <allegro5\allegro.h>

class Graphics
{
private:

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_DISPLAY_MODE dispData;
	ALLEGRO_BITMAP  *robotImg = NULL;


public:
	
	Graphics();
	Graphics();
	bool createDisplay();
	void graphFloor();
	void graphRobots();

};


#endif // !_GRAPHICS_H


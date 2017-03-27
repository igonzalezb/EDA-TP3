


#include "Simulacion.h"


simulacion::simulacion(unsigned int robot, unsigned int w, unsigned int h, graphics* = NULL)
{
	r = new Robot(w, h)[rc];
	p = new piso(w, h);

	if (p.isValid() && (r != NULL))
	{

	}

	else
	{
		delete r[];
		p.destroy();
	}

}

#ifndef _PISO_H
#define _PISO_H

#define SCREEN_W 800
#define SCREEN_H 600

class Piso
{

private:
	bool * baldo;
	unsigned int ancho;
	unsigned int alto;

public:


	Piso(unsigned int ancho, unsigned int alto);
	bool isDirty();						//devuelve si esta limpio o sucio
	bool cleanTile(unsigned int x, unsigned int y);
	bool getTileState(unsigned int x, unsigned int y);
	bool isValid();						//dice si baldose da NULL


};



#endif // !_PISO_H


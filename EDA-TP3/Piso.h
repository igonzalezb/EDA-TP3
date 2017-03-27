#ifndef _PISO_H
#define _PISO_H

class piso
{

private:
	bool * baldo;
	unsigned int ancho;
	unsigned int alto;

public:


	piso(unsigned int ancho, unsigned int alto);
	bool isDirty();									//devuelve si esta limpio o sucio
	bool cleanTile(unsigned int x, unsigned int y);
	bool getTileState(unsigned int x, unsigned int y);
	bool isValid();		//dice si baldose da NULL


};



#endif // !_PISO_H


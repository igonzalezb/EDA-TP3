class Piso
{
private:

	bool **baldo;
	unsigned int w;
	unsigned int h;
	void setFloorDirty();	//Setea TODO el piso en SUCIO

public:

	Piso(unsigned int width, unsigned int height);
	bool isDirty();									//devuelve si esta limpio o sucio
	void cleanTile(unsigned int x, unsigned int y);
	bool getTileState(unsigned int x, unsigned int y);
	unsigned int getW();
	unsigned int getH();
	bool isValid();		//dice si baldose da NULL}
};

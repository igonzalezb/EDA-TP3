class Piso
{
private:

	bool **baldo;
	unsigned int w;
	unsigned int h;
	void setFloorDirty();	//Setea TODO el piso en SUCIO

public:

	Piso(unsigned int width, unsigned int height);
	//devuelve TRUE si esta sucio, FALSE si esta limpio
	bool isDirty();									
	void cleanTile(unsigned int x, unsigned int y);
	//getTileState devuelve TRUE si esta limpio, FALSE si esta sucio
	bool getTileState(unsigned int x, unsigned int y);
	unsigned int getW();
	unsigned int getH();
	bool isValid();		//dice si baldose da NULL}
};

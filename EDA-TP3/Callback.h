#ifndef CALLBACK_H
#define CALLBACK_H

enum { MODO1, MODO2 };

typedef struct {
	int modo;
	bool init_modo;
	unsigned int h;
	bool init_h;
	unsigned int w;
	bool init_w;
	int cantRobots;
	bool init_CantRobots;
	

} parametros_t;
int Callback(char * Key, char* Value, void * Data);


#endif // _CALLBACK_H
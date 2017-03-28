#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "callback.h"
#define ERROR_CALLBACK 0
#define TERMINADOR_CALLBACK '\0'
#define MAX_STRING 100
#define OK 1


int AllMayus(char * string, char mayus[MAX_STRING]);

int Callback(char * Key, char* Value, void * Data)
{
	char key_mayus[MAX_STRING];

	if (Key != NULL)
	{
		if (AllMayus(Key, key_mayus))
		{
			if (strcmp(key_mayus, "MODO") == false && ((parametros_t *)Data)->init_modo == false)
			{
				if (AllMayus(Value, key_mayus))
				{
					if (strcmp(key_mayus, "1") == false)
					{
						((parametros_t *)Data)->modo = MODO1;
						((parametros_t *)Data)->init_modo = true;
					}
					else if (strcmp(key_mayus, "2") == false)
					{
						((parametros_t *)Data)->modo = MODO2;
						((parametros_t *)Data)->init_modo = true;
					}

				}
				else
				{
					return ERROR_CALLBACK;
				}

			}

			else if (strcmp(key_mayus, "ANCHO") == false && ((parametros_t *)Data)->init_w == false)
			{
				((parametros_t *)Data)->w = atoi(Value);
				((parametros_t *)Data)->init_w = true;
			}
			else if (strcmp(key_mayus, "LARGO") == false && ((parametros_t *)Data)->init_h == false)
			{
				((parametros_t *)Data)->h = atoi(Value);
				((parametros_t *)Data)->init_h = true;
			}
			else if (strcmp(key_mayus, "ROBOTS") == false && ((parametros_t *)Data)->init_CantRobots == false)
			{
				((parametros_t *)Data)->cantRobots = atoi(Value);
				((parametros_t *)Data)->init_CantRobots = true;
			}
			
			else
			{
				return ERROR_CALLBACK;
			}

		}
		else
		{
			return ERROR_CALLBACK;
		}

	}
	else
	{
		return ERROR_CALLBACK;
	}
	return OK;
}


int validacionUsuario(parametros_t p)
{
	switch (p.modo)
	{
	case MODO1:
		if (!(p.h <= 100 && p.w <= 70))
		{
			return ERROR_CALLBACK;
		}
		break;

	case MODO2:

		break;
	default:
		return ERROR_CALLBACK;
	}
}


int AllMayus(char * string, char mayus[MAX_STRING])
{
	int i = 0;
	while ((string[i]) != TERMINADOR_CALLBACK)
	{
		if (('a' <= string[i]) && ('z' >= string[i]))
		{
			mayus[i] = string[i] - ('a' - 'A');
		}
		else if (('A' <= string[i]) && ('Z' >= string[i]))
		{
			mayus[i] = string[i];
		}
		else if (('1' <= string[i]) && ('9' >= string[i]) || (string[i] == '-'))

		{
			mayus[i] = string[i];


		}
		else if (string[i] == TERMINADOR_CALLBACK)
		{
			mayus[i] = TERMINADOR_CALLBACK;
		}
		else
		{
			return ERROR_CALLBACK;
		}
		i++;
	}
	mayus[i] = TERMINADOR_CALLBACK;
	return OK;
}
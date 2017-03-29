#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "callback.h"
#include <ctype.h>

#define ERROR_CALLBACK 0
#define TERMINADOR_CALLBACK '\0'
#define MAX_STRING 100
#define OK 1


int AllMin(char * string, char mayus[MAX_STRING]);

int Callback(char * Key, char* Value, void * Data)
{
	char key_min[MAX_STRING];
	for (int i = 0; i < MAX_STRING; i++) { key_min[i] = NULL; }

	if (Key != NULL)
	{
		if (AllMin(Key, key_min))
		{
			if (strcmp(key_min, "modo") == false && ((parametros_t *)Data)->init_modo == false)
			{
				if (AllMin(Value, key_min))
				{
					if (strcmp(key_min, "1") == false)
					{
						((parametros_t *)Data)->modo = MODO1;
						((parametros_t *)Data)->init_modo = true;
					}
					else if (strcmp(key_min, "2") == false)
					{
						((parametros_t *)Data)->modo = MODO2;
						((parametros_t *)Data)->init_modo = true;
					}

				}
				else
					return ERROR_CALLBACK;
			}

			else if (strcmp(key_min, "ancho") == false && ((parametros_t *)Data)->init_w == false)
			{
				((parametros_t *)Data)->w = atoi(Value);
				((parametros_t *)Data)->init_w = true;
			}
			else if (strcmp(key_min, "alto") == false && ((parametros_t *)Data)->init_h == false)
			{
				((parametros_t *)Data)->h = atoi(Value);
				((parametros_t *)Data)->init_h = true;
			}
			else if (strcmp(key_min, "robots") == false && ((parametros_t *)Data)->init_CantRobots == false)
			{
				((parametros_t *)Data)->cantRobots = atoi(Value);
				((parametros_t *)Data)->init_CantRobots = true;
			}
			
			else
				return ERROR_CALLBACK;
		}
		else
			return ERROR_CALLBACK;

	}
	else
		return ERROR_CALLBACK;

	return OK;
}


int validacionUsuario(parametros_t p)
{
	if (!(p.h <= 100 && p.w <= 70))
	{
		return ERROR_CALLBACK;
	}
		
	switch (p.modo)
	{
	case MODO1:
		if (p.init_CantRobots == false)
			return ERROR_CALLBACK;
		break;

	case MODO2:
		if (p.init_CantRobots == true)
			return ERROR_CALLBACK;
		break;
	default:
		

		return ERROR_CALLBACK;
	}

	return OK;
}


int AllMin(char * string, char min[MAX_STRING])
{
	int i = 0;
	while ((string[i]) != TERMINADOR_CALLBACK)
	{
		min[i] = tolower(string[i]);
		i++;
	}

	return OK;
}
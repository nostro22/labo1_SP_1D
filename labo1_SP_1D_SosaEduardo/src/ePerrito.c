/*
 * ePerrito.c
 *
 *  Created on: 25 nov. 2021
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ePerrito.h"
#include  <ctype.h>

ePerrito* ePerrito_new()
{
	ePerrito* this = NULL;
	this = (ePerrito*) malloc (sizeof(ePerrito));
	return this;
}


ePerrito* ePerrito_newParametros(char* idStr,char* nombreStr,char* pesoStr, char* edadStr, char* razaStr)
{
	ePerrito* this = NULL;
	this = ePerrito_new();
	if(this != NULL)
	{
		ePerrito_setId( this, atoi(idStr));
		ePerrito_setNombre( this, nombreStr);
		ePerrito_setPeso(this, atof(pesoStr));
		ePerrito_setEdad(this, atoi(edadStr));
		ePerrito_setRaza( this, razaStr);
	}
	return this;
}


int ePerrito_delete(ePerrito* this)
{
	int retorno=0;
	if(this != NULL)
	{
		free(this);
		this = NULL;
		retorno=1;
	}
	return retorno;
}
////ID INT
int ePerrito_setId(ePerrito* this,int id)
{
	int seCargo = 0;
	if(this != NULL)
	{
		this->id = id;
		seCargo = 1;
	}
	return seCargo;
}

int ePerrito_getId(ePerrito* this,int* id)
{
	int retorno =0;
	if(this != NULL)
	{
		*id = this->id;
		retorno =1;
	}
	return retorno;
}
////Set nombre STRING
int ePerrito_setNombre(ePerrito* this,char* nombre)
{
	int seCargo = 0;
	if(this != NULL)
	{
		strcpy(this->nombre,nombre);
		seCargo = 1;
	}
	return seCargo;
}

int ePerrito_getNombre(ePerrito* this,char* nombre)
{
	int retorno =0;
	if(this != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno =1;
	}
	return retorno;
}

/////set sexo CHAR

int ePerrito_setRaza(ePerrito* this,char* raza)
{
	int seCargo = 0;
	if(this != NULL)
	{
		strcpy(this->raza,raza);
		seCargo = 1;
	}
	return seCargo;
}

int ePerrito_getRaza(ePerrito* this,char* raza)
{
	int retorno =0;
	if(this != NULL)
	{
		strcpy(raza,this->raza);
		retorno =1;
	}
	return retorno;
}

/////EDAD INT

int ePerrito_setEdad(ePerrito* this,int auxEdad)
{
	int seCargo = 0;
	if(this != NULL)
	{
		this->edad = auxEdad;
		seCargo = 1;
	}
	return seCargo;
}

int ePerrito_getEdad(ePerrito* this,int* edad)
{
	int retorno =0;
	if(this != NULL)
	{
		*edad = this->edad;
		retorno =1;
	}
	return retorno;
}

/////Peso FLOAT

int ePerrito_setPeso(ePerrito* this,float peso)
{
	int seCargo = 0;
	if(this != NULL)
	{
		this->peso = peso;
		seCargo = 1;
	}
	return seCargo;
}



int ePerrito_getPeso(ePerrito* this,float* peso)
{
	int retorno =0;
	if(this != NULL)
	{
		*peso = this->peso;
		retorno =1;
	}
	return retorno;
}

int ePerrito_setCantidadComidaRacion(ePerrito* this,float cantidadComidaRacion)
{
	int seCargo = 0;
	if(this != NULL)
	{
		this->cantidadComidaRacion = cantidadComidaRacion;
		seCargo = 1;
	}
	return seCargo;
}



int ePerrito_getCantidadComidaRacion(ePerrito* this,float* cantidadComidaRacion)
{
	int retorno =0;
	if(this != NULL)
	{
		*cantidadComidaRacion = this->cantidadComidaRacion;
		retorno =1;
	}
	return retorno;
}
//////////////////////////////////////////////////////////////////////

int ePerrito_printData(ePerrito* this)
{
	int retorno=0;
	int id;
	char nombre[30];
	char raza[30];
	int edad;
	float peso;

	if(this !=NULL)
	{
		ePerrito_getId(this, &id);
		ePerrito_getNombre(this,nombre);
		ePerrito_getRaza(this, raza);
		ePerrito_getEdad(this, &edad);
		ePerrito_getPeso(this, &peso);
		printf("%-10d  %-15s %-15.2f  %-15d %-15s\n", id, nombre, peso, edad, raza);
	}
	return retorno;
}

int ePerrito_printDataRacion(ePerrito* this)
{
	int retorno=0;
	int id;
	char nombre[30];
	char raza[30];
	int edad;
	float peso;
	float cantidadComidaRacion;

	if(this !=NULL)
	{
		ePerrito_getId(this, &id);
		ePerrito_getNombre(this,nombre);
		ePerrito_getRaza(this, raza);
		ePerrito_getEdad(this, &edad);
		ePerrito_getPeso(this, &peso);
		ePerrito_getCantidadComidaRacion(this, &cantidadComidaRacion);
		printf("%-10d  %-15s %-15.2f  %-15d %-15s %-25.2f\n", id, nombre, peso, edad, raza,cantidadComidaRacion);
	}
	return retorno;
}

int ePerrito_ordenarPorNombre(void* punteroUno, void* punteroDos)
{
	int retorno=-2;
	if(punteroUno!=NULL&&punteroDos!=NULL)
	{
		char auxNombreUno[128];
		char auxNombreDos[128];
		ePerrito* this = (ePerrito*)punteroUno;
		ePerrito* this2 = (ePerrito*)punteroDos;
		ePerrito_getNombre(this,auxNombreUno);
		ePerrito_getNombre(this2,auxNombreDos);

		retorno=stricmp(auxNombreUno,auxNombreDos);

		this =NULL;
		this2=NULL;
	}

	return retorno;
}



int ePerrito_ordenarPorId(void* punteroUno, void* punteroDos)
{
	int retorno=-2;
	if(punteroUno!=NULL&&punteroDos!=NULL)
	{
		int idUno;
		int idDos;
		ePerrito* this = (ePerrito*)punteroUno;
		ePerrito* this2 = (ePerrito*)punteroDos;
		ePerrito_getId(this,&idUno);
		ePerrito_getId(this2,&idDos);

		if(idUno>idDos)
		{
			retorno=1;
		}
		else if(idUno<idDos)
		{
			retorno=-1;
		}
		this =NULL;
		this2=NULL;
	}
	return retorno;
}

int ePerrito_ordenarPeso(void* punteroUno, void* punteroDos)
{
	int retorno=-2;
	if(punteroUno!=NULL&&punteroDos!=NULL)
	{
		float peso1;
		float peso2;
		ePerrito* this = (ePerrito*)punteroUno;
		ePerrito* this2 = (ePerrito*)punteroDos;
		ePerrito_getPeso(this,&peso1);
		ePerrito_getPeso(this2,&peso2);

		if(peso1>peso2)
		{
			retorno=1;
		}
		else if(peso1<peso2)
		{
			retorno=-1;
		}
		this =NULL;
		this2=NULL;
	}
	return retorno;
}

///////// Filtros




int ePerros_laQueFiltra(void* this)
{
    int retorno=-1;

    char auxRaza[128];
    float racion;
    int edad;


        ePerrito_getRaza((ePerrito*) this, auxRaza);
        ePerrito_getEdad((ePerrito*) this, &edad);
        ePerrito_getCantidadComidaRacion((ePerrito*) this, &racion);
        if( racion<200 && edad>10 && (strcmp(auxRaza,"Galgo")==0))
        {
            retorno= 1;
        }


    return retorno;
}


int ePerros_laQueMapea(void* this)
{
    int retorno=-1;

    float racion;
    float peso;

    if(this!=NULL)
    {
        ePerrito_getPeso((ePerrito*) this, &peso);
       racion=peso*23;
       ePerrito_setCantidadComidaRacion((ePerrito*) this, racion);
    }

    return retorno;
}



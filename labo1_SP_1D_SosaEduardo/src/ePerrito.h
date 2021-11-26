/*
 * ePerrito.h
 *
 *  Created on: 26 nov. 2021
 *      Author: Usuario
 */

#ifndef EPERRITO_H_
#define EPERRITO_H_
typedef struct
{
    int id;
    char nombre[21];
    float peso;
    int edad;
    char raza[21];
    float cantidadComidaRacion;

}ePerrito;

ePerrito* ePerrito_new();

ePerrito* ePerrito_newParametros(char* idStr,char* nombreStr,char* pesoStr, char* edadStr, char* razaStr);


int ePerrito_delete(ePerrito* this);


int ePerrito_setId(ePerrito* this,int id);


int ePerrito_getId(ePerrito* this,int* id);


int ePerrito_setNombre(ePerrito* this,char* nombre);


int ePerrito_getNombre(ePerrito* this,char* nombre);


int ePerrito_setEdad(ePerrito* this,int edad);


int ePerrito_getEdad(ePerrito* this,int* edad);


int ePerrito_setPeso(ePerrito* this,float peso);

int ePerrito_getPeso(ePerrito* this,float* peso);

int ePerrito_setCantidadComidaRacion(ePerrito* this,float cantidadComidaRacion);

int ePerrito_getCantidadComidaRacion(ePerrito* this,float* cantidadComidaRacion);

int ePerrito_setRaza(ePerrito* this,char* raza);

int ePerrito_getRaza(ePerrito* this,char* raza);


int ePerrito_printData(ePerrito* this);

int ePerros_laQueFiltra(void* this);

int ePerrito_ordenarPorId(void* punteroUno, void* punteroDos);

int ePerrito_ordenarPorNombre(void* punteroUno, void* punteroDos);

int ePerrito_ordenarPeso(void* punteroUno, void* punteroDos);

int ePerros_laQueMapea(void* this);

int ePerrito_printDataRacion(ePerrito* this);




#endif /* EPERRITO_H_ */

#include <stdio.h>
#include <stdlib.h>
#include "../src/LinkedList.h"
#include "ePerrito.h"
#include "parser.h"
#include "INPUTS.h"


int controller_loadFromText(char* path , LinkedList* pArrayList)
{

	int retorno=0;
	int errorParse=0;

	if(path!=NULL)
	{
		FILE* pFile = fopen(path, "r");
		if(pFile!=NULL)
		{
			errorParse=parser_FromText(pFile , pArrayList);
			if(errorParse==-1)
			{
				retorno=-1;
			}
			else if(errorParse==-2)
			{
				retorno=-2;
			}
			else
			{
				retorno=1;
			}
		}
	}
	return retorno;
}


int controller_List(LinkedList* pArrayListEmployee)
{
	int i=0;
	int retorno=0;
	if(pArrayListEmployee!=NULL)
	{
		int lenList = ll_len(pArrayListEmployee);
		printf("%-10s %-15s %-15s  %-15s %-20s\n", "ID", "NOMBRE", "PESO", "EDAD", "RAZA");
		for (i = 0; i < lenList; ++i)
		{
			ePerrito* pPerrito =(ePerrito*) ll_get(pArrayListEmployee, i);
			ePerrito_printData(pPerrito);
		}
		retorno=1;
	}

	return retorno;
}

int controller_ListRacion(LinkedList* pArrayListEmployee)
{
	int i=0;
	int retorno=0;
	if(pArrayListEmployee!=NULL)
	{
		int lenList = ll_len(pArrayListEmployee);
		printf("%-10s  %-15s %-15s  %-15s %-15s %-25s\n", "ID", "NOMBRE", "SEXO", "EDAD", "PESO","RACION");
		for (i = 0; i < lenList; ++i)
		{
			ePerrito* pPerrito =(ePerrito*) ll_get(pArrayListEmployee, i);
			ePerrito_printDataRacion(pPerrito);
		}
		retorno=1;
	}

	return retorno;
}


int controller_sort(LinkedList* pArrayList)
{


	int retorno =0;
	if(pArrayList!=NULL)
	{
		int (*pFuncionOrdenamiento)(void*,void*);

			printf("Ordenando Lista \nEspere...\n");
			pFuncionOrdenamiento = ePerrito_ordenarPorNombre;
			ll_sort(pArrayList, pFuncionOrdenamiento, 1);
	}

	return retorno;
}


int controller_saveAsText(char* path , LinkedList* pArrayList)
{

	int id;
	char nombre[21];
	char raza[21];
	int edad;
	float peso;
	float cantidadComidaRacion;
	ePerrito* pPerrito;


	printf("Guardando... Generando archivo texto\n");
	int retorno=0;
	int tamArray= ll_len(pArrayList);

	FILE* pFile;
	if(path!=NULL)
	{
		retorno=2;
		pFile = fopen(path, "w");

		if(pFile!=NULL)
		{
			fprintf(pFile,"%s,%s,%s,%s,%s,%s\n", "ID", "NOMBRE", "PESO", "EDAD", "RAZA", "RACION");

			for (int var = 0; var < tamArray; ++var)
			{
				pPerrito=(ePerrito*)ll_get(pArrayList, var);
				ePerrito_getId(pPerrito, &id);
				ePerrito_getNombre(pPerrito, nombre);
				ePerrito_getRaza(pPerrito, raza);
				ePerrito_getEdad(pPerrito, &edad);
				ePerrito_getPeso(pPerrito, &peso);
				ePerrito_getCantidadComidaRacion(pPerrito, &cantidadComidaRacion);

				fprintf(pFile,"%d,%s,%.2f,%d,%s,%.2f\n", id, nombre, peso, edad, raza, cantidadComidaRacion);

			}
			printf("Archivo escrito con exito!\n");
			retorno=1;
		}
		fclose(pFile);
	}

	return retorno;
}


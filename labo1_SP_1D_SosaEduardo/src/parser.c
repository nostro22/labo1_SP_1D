#include <stdio.h>
#include <stdlib.h>
#include "../src/LinkedList.h"
#include "ePerrito.h"


int parser_FromText(FILE* pFile , LinkedList* pArrayList)
{
	int retorno=-1;
	char id[10];
	char nombre[21];
	char peso[10];
	char edad[10];
	char raza[10];

	if(pFile != NULL && pArrayList != NULL)
	{
		/// fscanf(punteroArchivo, formato(%d, %[^,]), ...)
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]", id, nombre, peso, edad, raza); /// leer encabezado
		while(!feof(pFile))
		{
			/// traigo los datos
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]", id, nombre, peso, edad, raza);
			if(feof(pFile))
			{
				break;
			}
			ePerrito* aux = ePerrito_newParametros(id, nombre, peso, edad, raza);
			/// lo pongo en el array
			ll_add( pArrayList, aux);

		}
		fclose(pFile);
		retorno=1;
		if(ll_len(pArrayList)==0)
		{
			retorno=-2;
		}
	}

	return retorno;
}


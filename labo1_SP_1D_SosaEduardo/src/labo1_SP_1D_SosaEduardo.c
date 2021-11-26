/*
 ============================================================================
 Name        : labo1_SP_1D_SosaEduardo.c
 Author      : Eduardo Andres Sosa Segovia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include "../src/LinkedList.h"
#include "Controller.h"
#include "ePerrito.h"
#include "INPUTS.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Listar perros Ordenados de manera ascendente por nombre.
     3. generar y calcular cantidadComidadRacion
     4. Listar los perritos con sus raciones de comida.
     5. Lista filtrada raza “Galgo”, tengan más de 10 años de edad y coman menos de 200 gramos de comida diaria.
     6. Guardar archivo “galgosFlaquitos.csv”
     7. Salir
 *****************************************************/


int main(void) {

	setbuf(stdout,NULL);
	int option = 0;
	int listaCargada=0;
	int errorControllerText =0;
	char confirmacion ={' '};
	LinkedList* lista = ll_newLinkedList();
	LinkedList* listaRacion=NULL;
	LinkedList* listaGalgosFlacos=NULL;
	int (*pFuncionMapeo)(void*);
	int (*pFuncionFiltros)(void*);



	do{

		pedirEntero(&option,"---------------------------------------------------------------------------------\n"
				"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
				"2. Listar perros Ordenados de manera ascendente por nombre.\n"
				"3. generar y calcular cantidadComidadRacion.\n"
				"4. Listar los perritos con sus raciones de comida.\n"
				"5. Lista filtrada raza “Galgo”, tengan más de 10 años de edad y coman menos de 200 gramos de comida diaria.\n"
				"6. Guardar archivo “galgosFlaquitos.csv” \n"
				"7. Salir\n"
				"---------------------------------------------------------------------------------\n"
				"Ingrese una opcion: ",

				"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
				"2. Listar perros Ordenados de manera ascendente por nombre.\n"
				"3. generar y calcular cantidadComidadRacion.\n"
				"4. Listar los perritos con sus raciones de comida.\n"
				"5. Lista filtrada raza “Galgo”, tengan más de 10 años de edad y coman menos de 200 gramos de comida diaria.\n"
				"6. Guardar archivo “galgosFlaquitos.csv” \n"
				"7. Salir\n"
				"---------------------------------------------------------------------------------\n"
				,1, 7,10);

		switch(option)
		{
		case 1:
			confirmacion=' ';
			if(listaCargada)
			{
				pedirCaracter(&confirmacion, "Cargar nuevamente eliminara los datos no guardados.\nIngrese c para confirmar la carga del archivo\n");
			}
			else
			{
				confirmacion='c';
			}


			if(confirmacion=='c'||confirmacion=='C')
			{
				ll_clear(lista);
				errorControllerText = controller_loadFromText("perritos.csv",lista);
				if(errorControllerText==0)
				{
					printf("ERROR carga de archivo\n");
				}
				else if (errorControllerText==-1)
				{
					printf("ERROR parseo de archivo\n");
				}
				else if(errorControllerText==-2)
				{
					printf("ERROR Archivo vacio\n");
				}
				else
				{
					listaCargada=1;
					printf("Datos cargados con exito...\nVolviendo al menu...\n");
				}
			}

			option=0;
			break;
		case 2:

			if(listaCargada)
			{
				controller_sort(lista);
				controller_List(lista);
			}
			else
			{
				printf("Carge la base de datos primero\n");
			}

			option=0;
			break;
		case 3:

			if(listaCargada)
			{
				pFuncionMapeo=ePerros_laQueMapea;
				listaRacion = ll_map(lista, pFuncionMapeo);
			}
			else
			{
				printf("Carge la base de datos primero\n");
			}

			break;
		case 4:
			if(listaRacion!=NULL)
			{
				controller_ListRacion(listaRacion);
			}
			else
			{
				printf("Ningun Empleado en sistema\n");
			}

			break;
		case 5:
			if(listaRacion!=NULL)
			{
				pFuncionFiltros=ePerros_laQueFiltra;
				listaGalgosFlacos = ll_filter(listaRacion, pFuncionFiltros);
				controller_ListRacion(listaGalgosFlacos);
			}
			else
			{
				printf("Ningun Empleado en sistema\n");
			}
			break;
		case 6:
			if(listaGalgosFlacos!=NULL)
			{
				controller_saveAsText("galgosFlaquitos.csv", listaGalgosFlacos);
			}
			else
			{
				printf("Ningun Empleado en sistema\n");
			}
			break;
		case 7:
			if(listaCargada)
			{
				printf("Liberando espacio de memoria...\n");
				printf("Lista Eliminada...\n");
				printf("Saliendo del sistema...\n");
				ll_deleteLinkedList(lista);
			}
			else
			{
				printf("Ningun Empleado en sistema\n");
			}

			break;

		}

		system("pause");
	}while(option != 10);
	printf("Programa cerrado.\n");
	return 0;


	return EXIT_SUCCESS;
}

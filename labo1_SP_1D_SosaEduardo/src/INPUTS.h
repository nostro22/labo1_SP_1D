/*
 * INPUTS.h
 *
 *  Created on: Oct 1, 2021
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef INPUTS_H_
#define INPUTS_H_

/**
 * @fn int pedirEntero(int*, char*, char*, int, int, int)
 * @brief  pide un numero entero al cliente limitado por un maximo un minimo y una cantidad de intentos
 * @param entero numero pedido que sera cambiado por referencia
 * @param mensaje mesaje inicial al pedir el numero
 * @param mensajeError mensaje en caso de erro al pedir el numero
 * @param min minimo calor permitido al numero solicitado
 * @param max maximo valor permitido al numero solicitado
 * @param intentos numero maximo de intentos permitidos antes de cancelar y salir de la fincion devolviendo -1 caso de error
 * @return -1 caso error no se modificara el numero, 1 se modifica el entero recibido asignandole el valor ingresado por el usuario
 */
int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max, int intentos);

/**
 * @fn int askFloatNumber(float*, char*, char*, float, float, int)
 * @brief pide un numero floatante al cliente limitado por un maximo un minimo y una cantidad de intentos
 * @param flotante numero pedido que sera cambiado por referencia
 * @param mensaje mesaje inicial al pedir el numero
 * @param mensajeError mensaje en caso de erro al pedir el numero
 * @param min minimo calor permitido al numero solicitado
 * @param max maximo valor permitido al numero solicitado
 * @return -1 caso error no se modificara el numero, 1 se modifica el entero recibido asignandole el valor ingresado por el usuario
 */
int askFloatNumber(float* num,char* message,char* errormessage,int min, int max, int tries);

/**
 * @fn int pedirCadena(char*, char*, char*, int, int)
 * @brief  se le pide una cadena al usuario de una longitud determinada con una limitada cantidad de intentos para ser captado el input
 * @param cadena array donde se guardara la cadena obtenida
 * @param mensaje mesaje inicial al pedir la cadena
 * @param mensajeError mesaje error si se fallo al pedir la cadena
 * @param max longitud maxima de la cadena
 * @param intentos numero maximo de intentos antes de cancelar y salir de la funcion
 * @return -1 caso error no se modificara la cadena, 1 se modifica la cadena recibido asignandole el valor ingresado por el usuario
 */
int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max, int intentos);

/**
 * @fn int pedirCadenaSoloLetras(char*, char*, char*, int, int)
 * @brief se le pide una cadena al usuario de una longitud determinada con una limitada cantidad de intentos para ser captado el input y solo se permite el ingreso de letras y espacios
 * @param cadena array donde se guardara la cadena obtenida
 * @param mensaje mesaje inicial al pedir la cadena
 * @param mensajeError mesaje error si se fallo al pedir la cadena
 * @param max longitud maxima de la cadena
 * @param intentos numero maximo de intentos antes de cancelar y salir de la funcion
 * @return -1 caso error no se modificara la cadena, 1 se modifica la cadena recibido asignandole el valor ingresado por el usuario
 */
int pedirCadenaSoloLetras(char* cadena, char* mensaje, char* mensajeError, int max, int intentos);
/**
 * @fn int pedirCaracter(char*, char*)
 * @brief se captura la primera tecla que presione y se guarda este valor por referencia en cadena
 * @param caracter valor donde se guardara el char capturado
 * @param mensaje mensaje antes de capturar el char para guiar al usuario
 * @return 1 si se capturo la letra -1 si hubo error llamado nulo de la funcion
 */
int pedirCaracter(char* caracter, char* mensaje);
/**
 * @fn int contieneSoloLetras(char*)
 * @brief funcion que revisa una cadena de characteres para determinar si solo contiene letras y espacios vacios
 * @param cadena a ser analizada
 * @return 1 si solo contiene letras Y ESPACIOS -1 si continen otros char aparte de letras y espacios vacios
 */
int contieneSoloLetras(char* cadena);

int askForAccompaniedNumber(char* string);
int pedirCaracter(char* caracter, char* mensaje);
int transformUppercase(char* string);
int validateString(char* string);
int validateSpaces(char* string);
int generarIntRandom(int min, int max);



#endif /* INPUTS_H_ */

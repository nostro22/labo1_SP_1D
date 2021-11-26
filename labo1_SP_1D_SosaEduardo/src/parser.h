/*
 * parser.h
 *
 *  Created on: 5 nov. 2021
 *      Author: Usuario
 */

#ifndef PARSER_H_
#define PARSER_H_
/**
 * @fn int parser_EmployeeFromText(FILE*, LinkedList*)
 * @brief
 * Lee y Parsea los datos obtenidos por el archivo de texto para ser guardados en la LinkedList
 * @param pFile Archivo del cual se extraeran los datos
 * @param pArrayListEmployee LinkedList donde se guardaran los datos obtenidos del file
 * @return -1 file es NULL o LinkedList es NULL, 1 si se cargo exitosamente, -2 si el archivo no se logro extraer ningun empleado
 */
int parser_FromText(FILE* pFile , LinkedList* pArrayList);



#endif /* PARSER_H_ */

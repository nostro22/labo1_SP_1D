

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* Camino donde se encuentra el archivo a cargar
 * \param pArrayListEmployee LinkedList*  Lista de punteros de empleados
 * \return int 0 si fallo por path NULL o file NULL, -1 error en error parseo de datos y -2 error archivo vacio
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayList);

/** \brief Listar empleados recorre la lista de punteros y llama a la funcion employee_printData
 *
 * \param pArrayListEmployee LinkedList* Lista de punteros de empleados
 * \return int 0 si pArrayListEmployee es NULL. 1 si fue ecitosa la impresion
 *
 */
int controller_List(LinkedList* pArrayList);

/** \brief Ordenar empleados
 * Se le pide al usuario que selecione la opcion de ordenamiento usando las disintas funciones de ordenamiento con un puntero a funcion y ll_sort se ejecutan estas sobre la lista
 * \param pArrayListEmployee LinkedList* Lista de punteros de empleados
 * \return int 0 si es NULL el array. 1 si fue exitoso el ordenamiento. 2 si se cancelo por selecion de usuario
 */
int controller_sort(LinkedList* pArrayList);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* el camino hacia el archivo a guardar
 * \param pArrayListEmployee LinkedList* Lista de punteros de empleados
 * \return int 0 si el path es NULL. 1 si fue exitoso elguardado. 2 si pArrayListEmployee es NULL
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayList);

/** \brief Guarda los datos de los empleados en el archivo dataBn.bin (modo binario).
 *
 * \param path char* el camino hacia el archivo a guardar
 * \param pArrayListEmployee LinkedList*
 * \return int int 0 si el path es NULL. 1 si fue exitoso elguardado. 2 si pArrayListEmployee es NULL
 *
 */


int controller_ListRacion(LinkedList* pArrayListEmployee);

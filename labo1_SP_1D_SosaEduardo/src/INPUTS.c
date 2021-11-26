#include "INPUTS.h"


int pedirCadenaSoloLetras(char* cadena, char* mensaje, char* mensajeError, int max, int intentos)
{
	{
		int retorno=-1;
		char Auxiliar[200];
		int fallos =0;
		if(cadena!=NULL && max>0)
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%[^\n]",Auxiliar);

			while((strlen(Auxiliar)>max || askForAccompaniedNumber(Auxiliar)==-1 || validateString(Auxiliar)==0)&&(fallos<intentos))
			{
				printf("%s",mensajeError);
				fflush(stdin);
				scanf("%[^\n]",Auxiliar);
				if((strlen(Auxiliar)>max || askForAccompaniedNumber(Auxiliar)==-1 || validateString(Auxiliar)==0))
				{
					fallos++;
				}
			}
			strcpy(cadena,Auxiliar);
			if((fallos<intentos))
			{
				retorno=0;
			}

		}
		return retorno;
	}
}



int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max, int intentos)
{
	int retorno = -1;
	char buffer[256];
	int tam;
	int fallos=0;

	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && max > 0 && fallos<intentos)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", buffer);
		tam = strlen(buffer);

		while(tam > max && fallos<intentos)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%[^\n]", buffer);
			tam = strlen(buffer);
			if(tam > max)
			{
				fallos++;
			}

		}
		if( fallos<intentos)
		{
			strcpy(cadena, buffer);
			retorno = 1;
		}

	}

	return retorno;
}

int pedirCaracter(char* caracter, char* mensaje)
{
	int retorno = -1;

	if(caracter != NULL && mensaje != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		*caracter = getchar();
		retorno = 0;
	}

	return retorno;
}

int askForAccompaniedNumber(char* string)
{
	int retorno=-1;
	int i;
	int tam;

	if(string!=NULL)
	{
		tam=strlen(string);

		for(i=0;i<tam;i++)
		{
			if(isdigit(string[i])==0 && string[i]!='.' && string[0]!='+' && string[0]!='-')
			{
				retorno=0;
				break;
			}

		}

	}
	return retorno;
}

int validateString(char* string)
{
	int i;
	int tam;
	int retorno=-1;
	if(string!=NULL)
	{
		tam=strlen(string);
		transformUppercase(string);
		for(i=0;i<tam;i++)
		{

			if(string[i] < 97 || string[i] > 122)
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int transformUppercase(char* string)
{
	int retorno=-1;
	int i;
	int tam;
	if(string!=NULL)
	{
		tam=strlen(string);
		for(i=0;i<tam;i++)
		{
			string[i]=tolower(string[i]);
		}
		retorno=0;
	}
	return retorno;
}


int askFloatNumber(float* num,char* message,char* errormessage,int min, int max, int tries)
{
	int retorno=-1;
	char numAux[51];
	float numFloatAux;
	int fails=0;

	if(num!=NULL && message!=NULL && errormessage!=NULL)
	{

		printf("%s",message);
		fflush(stdin);
		scanf("%[^\n]",numAux);
		numFloatAux=atof(numAux);

		while(((!askForAccompaniedNumber(numAux) && !validateSpaces(message)) ||(numFloatAux>max || numFloatAux<min))&&fails<tries)
		{
			printf("%s",errormessage);
			fflush(stdin);
			scanf("%[^\n]",numAux);
			numFloatAux=atoi(numAux);
			if((!askForAccompaniedNumber(numAux) && !validateSpaces(message)) ||(numFloatAux>max || numFloatAux<min))
			{
				fails++;
			}
		}
		if(fails<tries)
		{
			*num=atof(numAux);
			retorno=0;
		}

	}
	return retorno;
}

int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max, int intentos)
{
	int retorno=-1;
	char numAux[51];
	int intAux;
	int fails=0;

	if(numAux!=NULL && mensaje!=NULL && mensajeError!=NULL)
	{

		printf("%s",mensaje);
		fflush(stdin);
		scanf("%[^\n]",numAux);
		intAux=atoi(numAux);

		while(((!askForAccompaniedNumber(numAux) && !validateSpaces(mensaje)) ||(intAux>max || intAux<min))&&fails<intentos)
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%[^\n]",numAux);
			intAux=atoi(numAux);
			if((!askForAccompaniedNumber(numAux) && !validateSpaces(mensaje)) ||(intAux>max || intAux<min))
			{
				fails++;
			}
		}
		if(fails<intentos)
		{
			*entero=atoi(numAux);
			retorno=0;
		}

	}
	return retorno;
}

int validateSpaces(char* string)
{
	int retorno=-1;
	int i;
	int tam;
	tam=strlen(string);
	for(i=0;i<tam;i++)
	{
		if(string[i] == ' '||  string[i] == '\t' ||  string[i] == '\v')
		{
			retorno=0;
			break;
		}
	}
	return retorno;
}

int generarIntRandom(int min, int max)
{
	int retorno = 0;

	retorno=  min + rand() % (max-min+1);

	return retorno;
}

//*****************************************************************
//THE CHILAKILLERS
//Curso: Análisis de algoritmos
//(C) Enero 2013
//ESCOM-IPN
//Ejemplo de medición de tiempo en C y recepción de parametros en C bajo UNIX
//Compilación: "gcc main.c tiempo.x  -o main(teimpo.c si se tiene la implementación de la libreria o tiempo.o si solo se tiene el codigo objeto)"
//Ejecución: "./main n" (Linux y MAC OS)
//*****************************************************************

//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"
#include "codificador.h"
#include "decodificador.h"
//*****************************************************************
//DEFINICION DE CONSTANTES DEL PROGRAMA
//*****************************************************************

//********************************************************************************
//DECLARACION DE ESTRUCTURAS
//********************************************************************************

//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************

//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************

//*****************************************************************
//PROGRAMA PRINCIPAL
//*****************************************************************
int main (int argc, char* argv[])
{
	//******************************************************************
	//Variables del main
	//******************************************************************
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	int n; 	//n determina el tamaño del algorito dado por argumento al ejecutar
	int i; //Variables para loops

	//******************************************************************
	//Recepción y decodificación de argumentos
	//******************************************************************

	//Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
  if (argc != 3){
      printf("%s\n", "Uso: ./compresor nombre_archivo opcion (1: comprimir, 2: descomprimir)");
      exit(1);
  }

	//******************************************************************
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************
	uswtime(&utime0, &stime0, &wtime0);
	//******************************************************************

	//******************************************************************
	//Algoritmo
	//******************************************************************
  int opcion = atoi(argv[2]);

  if(opcion == 1){
      printf("COMPRIMIENDO EL ARCHIVO: %s\n", argv[1]);
      comprimir_archivo(argv[1]);
  }
  else if(opcion == 2){
      printf("DESCOMPRIMIENDO EL ARCHIVO: %s\n", argv[1]);
      decodificar_archivo(argv[1]);
  }
	//******************************************************************

	//******************************************************************
	//Evaluar los tiempos de ejecución
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);

	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	//******************************************************************

	//Terminar programa normalmente
	exit (0);
}

//************************************************************************
//DEFINICIÓN DE FUNCIONES
//************************************************************************

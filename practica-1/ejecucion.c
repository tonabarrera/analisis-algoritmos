//*****************************************************************
//M. EN C. EDGARDO ADRIÁN FRANCO MARTÍNEZ
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
#include "funciones.h"
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
    int algoritmo = 1;

	//******************************************************************
	//Recepción y decodificación de argumentos
	//******************************************************************

	//Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
	if (argc!=3)
	{
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	}
	//Tomar el segundo argumento como tamaño del algoritmo
	else
	{
		n=atoi(argv[1]);
        algoritmo = atoi(argv[2]);
	}

    int * numeros = (int *)malloc(n*sizeof(int));

    llenar_arreglo(&numeros, n);
	//******************************************************************
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************
	//******************************************************************
	//******************************************************************
	//Algoritmo
	//******************************************************************
	//******************************************************************
    // Lo ponemos aqui para que no cuente el break
    switch (algoritmo) {
        case BURBUJA:
            uswtime(&utime0, &stime0, &wtime0);
            ordenamiento_burbuja(&numeros, n);
            uswtime(&utime1, &stime1, &wtime1);
            break;
        case BURBUJA_CHIDO:
            uswtime(&utime0, &stime0, &wtime0);
            ordenamiento_burbuja_mejorado(&numeros, n);
            uswtime(&utime1, &stime1, &wtime1);
            break;
        case SELECCION:
            uswtime(&utime0, &stime0, &wtime0);
            ordenamiento_seleccion(&numeros, n);
            uswtime(&utime1, &stime1, &wtime1);
            break;
        case INSERCION:
            uswtime(&utime0, &stime0, &wtime0);
            ordenamiento_insercion(&numeros, n);
            uswtime(&utime1, &stime1, &wtime1);
            break;
        case SHELL:
            uswtime(&utime0, &stime0, &wtime0);
            ordenamiento_shell(&numeros, n);
            uswtime(&utime1, &stime1, &wtime1);
            break;
        case ARBOL:
            uswtime(&utime0, &stime0, &wtime0);
            ordenamiento_arbol(&numeros, n);
            uswtime(&utime1, &stime1, &wtime1);
            break;
        default:
            printf("ERROR");
            exit(1);
            break;
    }
	//******************************************************************
	//Evaluar los tiempos de ejecución
	//******************************************************************

    printf("%s\n", "========================================================================");
    switch (algoritmo) {
        case BURBUJA:
            printf("%s\n", "BURBUJA SIMPLE");
            break;
        case BURBUJA_CHIDO:
            printf("%s\n", "BURBUJA MEJORADO");
            break;
        case SELECCION:
            printf("%s\n", "SELECCION");
            break;
        case INSERCION:
            printf("%s\n", "INSERCION");
            break;
        case SHELL:
            printf("%s\n", "SHELL");
            break;
        case ARBOL:
            printf("%s\n", "ARBOL");
            break;
        default:
            printf("ERROR");
            break;
    }
    printf("%s %d\n", "n = ", n);


	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");

	//Mostrar los tiempos en formato exponecial
    /*
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
    */
	//******************************************************************
	//Terminar programa normalmente
    printf("%s\n", "========================================================================");
	exit (0);
}

//************************************************************************
//DEFINICIÓN DE FUNCIONES
//************************************************************************

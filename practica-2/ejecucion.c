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
    struct Arbol *arbol = NULL;

	int numeros_prueba[] = {
		322486, 14700764, 3128036, 6337399, 61396,
		10393545, 2147445644, 1295390003, 450057883, 187645041,
		1980098116, 152503, 5000, 1493283650, 214826, 1843349527,
		1360839354, 2109248666 , 2147470852, 0
	};

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
	int i = 0;
    switch (algoritmo) {
        case BINARIO:
			for(i = 0; i < 20; i++){
				uswtime(&utime0, &stime0, &wtime0);
				int res = busqueda_binaria(numeros, numeros_prueba[i], 0, n-1);
	            uswtime(&utime1, &stime1, &wtime1);
				printf("%s\n", "========================================================================");
				printf("%s\n", "BUSQUEDA BINARIA");
				printf("%s %d\n", "n = ", n);
				printf("Numero buscado: %d, indice del numero: %d", numeros_prueba[i], res);
				printf("\n");
				printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
				printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
				printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
				printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
				printf("\n");
				printf("%s\n", "========================================================================");
			}
            break;
        case ARBOL:
        // LLenar la variable numeros
            for (i = 0; i < n; i++)
                insertar(&arbol, numeros[i]);
            for(i = 0; i < 20; i++){
                uswtime(&utime0, &stime0, &wtime0);
                int res = busqueda_arbol(arbol, numeros_prueba[i]);
                uswtime(&utime1, &stime1, &wtime1);
                printf("%s\n", "========================================================================");
                printf("%s\n", "BUSQUEDA ARBOL BINARIO");
                printf("%s %d\n", "n = ", n);
                printf("Numero buscado: %d, encontrado: %s", numeros_prueba[i], res == -1 ? "No": "Si");
                printf("\n");
                printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
                printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
                printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
                printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
                printf("\n");
                printf("%s\n", "========================================================================");*/
            }
            break;
	case LINEAL:
			for(i = 0; i < 20; i++){
				uswtime(&utime0, &stime0, &wtime0);
				int res = busqueda_lineal(numeros, numeros_prueba[i], n-1);
	            uswtime(&utime1, &stime1, &wtime1);
				printf("%s\n", "========================================================================");
				printf("%s\n", "BUSQUEDA LINEAL");
				printf("%s %d\n", "n = ", n);
				printf("Numero buscado: %d, indice del numero: %d", numeros_prueba[i], res);
				printf("\n");
				printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
				printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
				printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
				printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
				printf("\n");
				printf("%s\n", "========================================================================");
			}
            break;
        default:
            printf("ERROR");
            exit(1);
            break;
    }
	//******************************************************************
	//Evaluar los tiempos de ejecución
	//******************************************************************
	/*
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
	*/

	//Cálculo del tiempo de ejecución del programa
	/*
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	*/
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
    //printf("%s\n", "========================================================================");
	exit (0);
}

//************************************************************************
//DEFINICIÓN DE FUNCIONES
//************************************************************************

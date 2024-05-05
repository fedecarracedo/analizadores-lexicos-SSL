#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 200

#define ARCHIVO_ENTRADA "entrada.txt"
#define ARCHIVO_SALIDA "salida.txt"

//estados
#define Q0 0
#define Q1 1
#define Q2 2
#define Q3 3
#define Q4 4
#define Q5 5
#define Q6 6

//eventos
#define CERO            0
#define _1AL7           1
#define _8Y9            2
#define _a_f_A_F        3
#define xX              4
#define OTRO            5

#define TABLA_SIZE_X 7
#define TABLA_SIZE_Y 6

//condicionfin
#define HEXADECIMAL "HEXADECIMAL"
#define DECIMAL "DECIMAL"
#define OCTAL "OCTAL"
#define NORECONOCIDA "NO RECONOCIDA"

int analizarEvento(int estado, char a);
void estadoToText(int estado, char * texto);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simbolos
typedef enum simbolo {
    R,
    $,
    MAX_SIMBOLO
} t_simbolo;

// Estados
typedef enum estado {
    Q0,
    Q1,
    Q2,
    Q_RECHAZO,
    MAX_ESTADO
} t_estado;

// Eventos
typedef enum columna {
    C1,
    C2,
    C3,
    C4,
    C5,
    C_RECHAZO,
    MAX_COLUMNA
} t_columna;

// Define push pop y default = nada
typedef enum accion {
    PUSH,
    POP,
    NADA
} t_accion;

// Nodo de pila
typedef struct nodo {
    t_simbolo cima;
    struct nodo* siguiente;
} t_nodo;

// Movimiento
typedef struct movimiento {
    t_estado estado;
    t_accion accion;
} t_movimiento;

#define Q0_PUSH     { Q0, PUSH }
#define Q0_NADA     { Q0, NADA }
#define Q1_PUSH     { Q1, PUSH }
#define Q1_NADA     { Q1, NADA }
#define Q2_POP      { Q2, POP }
#define RECHAZAR    { Q_RECHAZO, NADA }
#define TAM_MAXIMO  100

void eliminarEspacios(char* , char*);
int automataFinitoPila(char*);
int obtenerColumna(char);
int obtenerCima(t_nodo*);
void operarPila(t_nodo** , t_accion);
void limpiarPila(t_nodo*);
int test();
short esOperador(short caracter);

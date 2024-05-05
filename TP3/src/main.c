#include "main.h"


int main() {
    //inicializacion
    char expresionIngresada[TAM_MAXIMO] = "";
    char expresionSinEspacios[TAM_MAXIMO] = "";

    //testing (si se usa el makefile principal, esta funcion no hace nada)
    // if(test()) return 0;

    //ingreso de cadena a testear
    printf("Ingrese la expresion a analizar:\t");
    fgets(expresionIngresada, TAM_MAXIMO, stdin); //se guarda la cadena en expresionIngresada
    eliminarEspacios(expresionIngresada, expresionSinEspacios);
    
    int resultadoAnalisis = automataFinitoPila(expresionSinEspacios);
    //seccion principal
    if(!resultadoAnalisis)
        printf("Expresion sintacticamente correcta\n");
    else {
        printf("Expresion sintacticamente incorrecta\n");
        printf("Error en la posicion %d", (resultadoAnalisis - 1));
    }

    return 0;
}

//elimina espacios ¯\_(ツ)_/¯
void eliminarEspacios(char* expresionIngresada, char* expresionSinEspacios)
{
    int i = 0;
    int j = 0;

    while(expresionIngresada[i] != '\0')
    {
        if(expresionIngresada[i] != ' ')
        {
            expresionSinEspacios[j] = expresionIngresada[i];
            j++;
        }
        i++;
    }
}

int automataFinitoPila(char* expresion)
{
    t_movimiento tablaDeMovimientos[MAX_SIMBOLO][MAX_ESTADO][MAX_COLUMNA] = {
        // Movimientos para cima = R
        {
            { RECHAZAR,     Q1_NADA,    RECHAZAR,   Q0_PUSH,    RECHAZAR,   RECHAZAR },
            { Q1_NADA,      Q1_NADA,    Q0_NADA,    RECHAZAR,   Q2_POP,     RECHAZAR },
            { RECHAZAR,     RECHAZAR,   Q0_NADA,    RECHAZAR,   Q2_POP,     RECHAZAR },
            { RECHAZAR,     RECHAZAR,   RECHAZAR,   RECHAZAR,   RECHAZAR,   RECHAZAR },
        },
        // Movimientos para cima = $
        {
            { RECHAZAR,     Q1_NADA,    RECHAZAR,   Q0_PUSH,    RECHAZAR,   RECHAZAR },
            { Q1_NADA,      Q1_NADA,    Q0_NADA,    RECHAZAR,   RECHAZAR,   RECHAZAR },
            { RECHAZAR,     RECHAZAR,   Q0_NADA,    RECHAZAR,   RECHAZAR,   RECHAZAR },
            { RECHAZAR,     RECHAZAR,   RECHAZAR,   RECHAZAR,   RECHAZAR,   RECHAZAR },
        }
    };

    t_nodo* pila = NULL;
    t_movimiento nuevoMovimiento = Q0_NADA;             // Punto de partida = (q0, $)

    int i = 0;
    int columnaCaracter = 0;
    int estadoPila = 0;
    int cimaPila = 0;
    

    while(expresion[i] != '\n')
    {      
        estadoPila = nuevoMovimiento.estado;
        cimaPila = obtenerCima(pila);
        columnaCaracter = obtenerColumna(expresion[i]);
        nuevoMovimiento = tablaDeMovimientos[cimaPila][estadoPila][columnaCaracter];
        operarPila(&pila, nuevoMovimiento.accion);   
        
        i++;

        if(nuevoMovimiento.estado == Q_RECHAZO)
            break;        
    }

    if(((nuevoMovimiento.estado == Q1) || (nuevoMovimiento.estado == Q2)) && obtenerCima(pila) == $)
        i = 0;
    else
        i++;

    // Capturo el estado con el que terminó el proceso
    int ultimoEstado = nuevoMovimiento.estado;
    char ultimoCaracter = expresion[i-2];
    // Errores por terminar en un estado que no es final. Son los más sencillos de identificar.
    if(ultimoEstado == Q0) {
        if(esOperador(ultimoCaracter))
            printf("Se esperaba una expresion luego del operador %c \n", ultimoCaracter);
        else
            printf("Se esperaba un parentesis de cierre y no se encontro \n");
    }
    if((ultimoEstado == Q2 || ultimoEstado == Q1) && obtenerCima(pila) == R)
        printf("Se esperaba un parentesis de cierre y no se encontro \n");

    // Estos son los errores por "movimiento ilegal". El estado 3 es el de rechazo.
    if(ultimoEstado == Q_RECHAZO) {
        printf("Caracter incorrecto: %c \n", ultimoCaracter);

    }


    limpiarPila(pila);


    return i;
}

int obtenerCima(t_nodo* pila)
{
    if(pila == NULL)
        return $;
    else
        return pila->cima;
}

//traduce el caracter encontrado al numero de columna correspondiente
int obtenerColumna(char caracter)
{
    if(caracter == '0')
        return C1;
    else if(caracter >= '1' && caracter <= '9')
        return C2;
    else if((caracter == '+') || (caracter == '-') || (caracter == '*') || (caracter == '/'))
        return C3;
    else if(caracter == '(')
        return C4;
    else if(caracter == ')')
        return C5;         
    else
        return C_RECHAZO;
}

//combina PUSH y POP
void operarPila(t_nodo** pila, t_accion accion)
{
    t_nodo* auxiliar = malloc(sizeof(t_nodo));
    switch(accion) {
        case PUSH:           
            auxiliar->cima = R;
            auxiliar->siguiente = *pila;
            *pila = auxiliar;
            break;        
        case POP:
            auxiliar = *pila;
            *pila = auxiliar->siguiente;
            free(auxiliar);
            break;
        default:
            free(auxiliar);
            break;
    }
}

void limpiarPila(t_nodo* pila)
{
    while(pila != NULL)
        operarPila(&pila, POP);
}

short esOperador(short caracter) {
    short esOperador = 0;
    switch(caracter) {
        case 42:
            esOperador = 1;
            break;
        case 43:
            esOperador = 1;
            break;
        case 45:
            esOperador = 1;
            break;
        case 47:
            esOperador = 1;
            break;
    }
    return esOperador;
}

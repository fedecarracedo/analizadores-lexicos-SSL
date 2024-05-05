#include "main.h"

int main(int argc, char const *argv[])
{
    char caracter;
    int estado = Q0;

    FILE * entrada = fopen(ARCHIVO_ENTRADA, "r");
    FILE * salida = fopen(ARCHIVO_SALIDA, "w");

    char estadoFinal [15];

    while(1){
        //caracter = fgetc
        caracter = fgetc(entrada);
        //output append caracter or final state
        if (caracter != ',' && !feof(entrada) && caracter != '\n'){
            fprintf(salida, "%c",caracter);
            estado = analizarEvento(estado, caracter);
        }else if (caracter == '\n'){
            continue;
        }
        else{
            estadoToText (estado, estadoFinal);
            fprintf(salida, "%s %s %s", "\t", estadoFinal, "\r");
            estado = Q0;
        }
        if (feof(entrada)) break;
    }

    fclose(entrada);
    fclose(salida);
}

void estadoToText(int estado, char * texto){

    switch (estado)
    {
    case Q0:
        strcpy(texto, NORECONOCIDA);
        break;
    
    case Q1:
        strcpy(texto, OCTAL);
        break;

    case Q2:
        strcpy(texto, DECIMAL);
        break;

    case Q3:
        strcpy(texto, NORECONOCIDA);
        break;

    case Q4:
        strcpy(texto, HEXADECIMAL);
        break;

    case Q5:
        strcpy(texto, OCTAL);
        break;

    default:
        strcpy(texto, NORECONOCIDA);
        break;
    }

}
int analizarEvento(int estado, char evento)
{
    //Tabla de estados y transiciones
    int tabla[TABLA_SIZE_X][TABLA_SIZE_Y] = {
    {Q1, Q2, Q2, Q6, Q6, Q6},
    {Q5, Q5, Q6, Q6, Q3, Q6},
    {Q2, Q2, Q2, Q6, Q6, Q6},
    {Q4, Q4, Q4, Q4, Q6, Q6},
    {Q4, Q4, Q4, Q4, Q6, Q6},
    {Q5, Q5, Q6, Q6, Q6, Q6},
    {Q6, Q6, Q6, Q6, Q6, Q6}
    };

    if (evento == '0') return tabla[estado][CERO];
    else if (evento >= '1' && evento <= '7') return tabla[estado][_1AL7];
    else if (evento == '8' || evento == '9') return tabla[estado][_8Y9];
    else if ((evento >= 'a' && evento <= 'f') || (evento >= 'A' && evento <= 'F')) return tabla[estado][_a_f_A_F];
    else if (evento == 'x' || evento == 'X') return tabla[estado][xX];
    else return tabla[estado][OTRO];
}

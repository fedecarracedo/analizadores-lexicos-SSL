# TP1

## objetivo
En este trabajo intentamos leer un archivo de entrada, compuesto de constantes enteras de C (y algunas palabras invalidas) separadas por coma.
Luego utilizamos un automata para reconocer y clasificar estas constantes. El resultado se imprime en un archivo de salida

## implementacion
Primero creamos un archivo header (.h) donde usamos 'Define' para que el codigo sea mas legible y facil de modificar.
Dentro de estas definiciones estan incluidos los estados y los eventos

```C
//eventos
#define CERO            0
#define _1AL7           1
#define _8Y9            2
#define _a_f_A_F        3
#define xX              4
#define OTRO            5

//estados
#define Q0              0
#define Q1              1
#define Q2              2
#define Q3              3
#define Q4              4
#define Q5              5
#define Q6              6
```

de esta forma nuestra tabla de transiciones termina siendo:

```C
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
```

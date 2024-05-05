#include "../src/main.h"

#define TAM_MAXIMO  100

int test(){
	//inicializacion
	char expresionIngresada[TAM_MAXIMO] = "";
    char expresionSinEspacios[TAM_MAXIMO] = "";
	FILE * entrada = fopen ("entrada.txt", "r");
	FILE * salida = fopen ("salida.txt", "w+");

	while(1){
		if(fgets(expresionIngresada, TAM_MAXIMO, entrada)!=NULL) { // fgets arroja NULL si hubo un error o llego al final del archivo
			eliminarEspacios(expresionIngresada, expresionSinEspacios);
			if(!automataFinitoPila(expresionSinEspacios)){
				expresionIngresada[strlen(expresionIngresada)-1] = '\0'; // remuevo el \n para mas claridad en salida.txt
				fprintf(salida, "%s S\n", expresionIngresada);
			}else{
				expresionIngresada[strlen(expresionIngresada)-1] = '\0'; // remuevo el \n para mas claridad en salida.txt
				fprintf(salida, "%s N\n", expresionIngresada);
			}
		}else break;
	}
	fclose(entrada);
	fclose(salida);
    return 1;
}

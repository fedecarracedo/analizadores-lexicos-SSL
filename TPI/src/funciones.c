#include "funciones.h"

/******************************/
/*********** LEXICO ***********/
/******************************/
void copiar_especial(char* str1, char* str2)
{
    char* auxiliar;
    auxiliar = strdup(str1);
    strcpy(str1, str2);
    if(strlen(str2) != 1) { strcat(str1, " "); }
    strcat(str1, auxiliar);      
}

void imprimir_especial(int linea, char* tipo, char* identificador)
{
    char *token = strtok(identificador, " ");
    if(token != NULL) {
        while(token != NULL) {
            printf("Linea %03d: Declaracion -> %s %s\n", linea, tipo, token);
            token = strtok(NULL, " ");
        } 
    }
}

void remover_especial(char* str1)
{
    int length = strlen(str1);
    str1[length - 1] = '\0';
    char *word = strrchr(str1, ' ') + 1;
    strcpy(str1, word);
    //strcat(str1, " ");
}

/******************************/
/********* SEMANTICO **********/
/******************************/
t_nodo* crear_nodo(char* tipo, char* identificador, bool esFuncion, bool esFuncionDefinida)
{
	t_nodo* nodo = malloc(sizeof(t_nodo));
    
	strcpy (nodo->tipo, tipo);
    strcpy (nodo->identificador, identificador);
    nodo->funcion.esFuncion = esFuncion;
    nodo->parametros = NULL;
	nodo->siguiente = NULL;
    return nodo;
}

t_lista* crear_lista()
{
	t_lista* lista = malloc(sizeof(t_lista));

	lista->inicio = NULL;
	lista->cantidad_nodos = 0;
	return lista;
}

void agregar_lista(t_lista* self, t_nodo* nodo)
{
	t_nodo* auxiliar;

	// Cubro condicion de lista vacia
	if (!self->inicio) {
		self->inicio = nodo;
		self->cantidad_nodos++;
		return;
	}
	// Si la lista no esta vacia, busco el puntero "siguiente" del ultimo nodo para enganchar el nuevo
	auxiliar = self->inicio;
	while (auxiliar->siguiente != NULL)
		auxiliar = auxiliar->siguiente;
	auxiliar->siguiente = nodo;
    self->cantidad_nodos++;
}

void copiar_lista(t_lista* destino, t_lista* origen)
{
    t_nodo* auxiliar = origen->inicio;

    while (auxiliar != NULL) {
        crear_nodo_parametro(destino, auxiliar->tipo, auxiliar->identificador);
        auxiliar = auxiliar->siguiente;
    }
}

void vaciar_lista(t_lista* self)
{
    t_nodo* auxiliar = self->inicio;

    while (auxiliar != NULL) {
        free(auxiliar);
        auxiliar = auxiliar->siguiente;
        self->cantidad_nodos--;
    }
    self->inicio = NULL;
}

bool existe(t_lista* self, char* identificador)
{
    t_nodo* auxiliar = self->inicio;

    while (auxiliar != NULL) {
        if(strcmp(auxiliar->identificador, identificador) == 0)
            return true;
        auxiliar = auxiliar->siguiente;
    }
    return false;
}

void crear_nodo_parametro(t_lista* self, char* tipo, char* identificador)
{
    t_nodo* auxiliar = crear_nodo(tipo, identificador, false, false);
    
    agregar_lista(self, auxiliar);
}

void crear_nodo_variable(t_lista* self, char* tipo, char* identificador)
{
    if (existe(self, identificador)) {
        printf("Error Semanticoo -> Linea %03d, la variable \"%s\" ya se encuentra definida\n", yylineno, identificador);
    } else {
        t_nodo* auxiliar = crear_nodo(tipo, identificador, false, false);
        agregar_lista(self, auxiliar);
    }  
}

void crear_nodo_funcion(t_lista* self, char* tipo, char* identificador, t_lista* parametros, bool esFuncionDefinida)
{
    // Si la funcion existe y la quiero definir
    if(existe(self, identificador)) {
        if(esFuncionDefinida) {
            // Chequeo que no esté definida previamente
            if(!definirFuncion(self, identificador))
                printf("Error Semantico -> Linea %03d, la funcion \"%s\" ya se encuentra definida\n", yylineno, identificador);
            else
                printf("Definida exitosamente la funcion '%s'\n", identificador);
        }
    } else {
        t_nodo* auxiliar = crear_nodo(tipo, identificador, true, esFuncionDefinida);

        auxiliar->parametros = crear_lista();
        copiar_lista(auxiliar->parametros, parametros);
        agregar_lista(self, auxiliar);
    }
}

bool definirFuncion(t_lista* self, char* identificador)
{   
    t_nodo* auxiliar = self->inicio;
    while (auxiliar != NULL) {
        if(strcmp(auxiliar->identificador, identificador) == 0 && auxiliar->funcion.esFuncionDefinida == false) {
            auxiliar->funcion.esFuncionDefinida = true;
            return true;
        }
        auxiliar = auxiliar->siguiente;
    }
    return false;
}

char* obtener_tipo(t_lista* self, char* str)
{
    if (strcmp(str, "int") == 0 || strcmp(str, "float") == 0 || strcmp(str, "char") == 0 || strcmp(str, "char*") == 0) {
        return str;
    } else {
        t_nodo* auxiliar = self->inicio;

        while (auxiliar != NULL) {
            if (!auxiliar->funcion.esFuncionDefinida) {
                if (strcmp(str, auxiliar->identificador) == 0) {
                    char *str_aux;
                    strcpy(str_aux, auxiliar->tipo);
                    int length = strlen(str_aux);
                    str_aux[length - 1] = '\0';
                    return str_aux;
                }
            }
            auxiliar = auxiliar->siguiente;
        }
        return "null";
    }
}

void controlar_invocacion_funcion(t_lista* self, char* identificador, t_lista* parametros)
{
    //bool esFuncionDefinida = false;

    if(existe(self, identificador)) {

        t_nodo* auxiliar = self->inicio;

        while (auxiliar != NULL) {
            if(strcmp(auxiliar->identificador, identificador) == 0 && auxiliar->funcion.esFuncionDefinida) {
                controlar_cantidad_tipos(auxiliar->parametros, parametros);
                //esFuncionDefinida = true;
            }  
            auxiliar = auxiliar->siguiente;
        }
        //if (!esFuncionDefinida)
        //    printf("Error Semantico -> Linea %03d, la funcion \"%s\" no se encuentra definida\n", yylineno, identificador);
    } else {
        printf("Error Semantico -> Linea %03d, la funcion \"%s\" no se encuentra declarada\n", yylineno, identificador);
    } 
}

void controlar_cantidad_tipos(t_lista* self, t_lista* parametros)
{
    if (self->cantidad_nodos != parametros->cantidad_nodos) {
        printf("Error Semantico -> Linea %03d, difiere la cantidad de argumentos de invocacion\n", yylineno);
    } else {
        t_nodo* l_aux = self->inicio;
        t_nodo* p_aux = parametros->inicio;
        for (int index = 0; index < self->cantidad_nodos; index++) {
            if (strcmp(l_aux->tipo, p_aux->tipo) != 0) {
                printf("Error Semantico -> Linea %03d, el tipo del parametro %d difiere del tipo del argumento de invocacion\n", yylineno, (index + 1));
            }
            l_aux = l_aux->siguiente;
            p_aux = p_aux->siguiente;
        }
    }
}

void validar_suma(char* tipo1, char* tipo2)
{
    if (strcmp(tipo1, "null") == 0 || (strcmp(tipo1, "null") == 0))
        printf("Error Semanticoo -> Linea %03d, no se pueden sumar dichos tipos de variables\n", yylineno);
}


void imprimir_ts(t_lista* self)
{
    imprimir_variables(self);
    imprimir_funciones(self);
}

void imprimir_variables(t_lista* self)
{
    t_nodo* auxiliar = self->inicio;

    printf("\n/********** VARIABLES *********/\n");
    while (auxiliar != NULL) {
        if (!auxiliar->funcion.esFuncion)
            printf("%s%s\n", auxiliar->tipo, auxiliar->identificador);
        auxiliar = auxiliar->siguiente;
    }
}

void imprimir_funciones(t_lista* self)
{
    int cantidad = 0;
    t_nodo* auxiliar = self->inicio;

    printf("\n/********** FUNCIONES *********/\n");
    while (auxiliar != NULL) {
        if(auxiliar->funcion.esFuncion) {
            printf("%s %s (", auxiliar->tipo, auxiliar->identificador);
            cantidad = imprimir_parametros(auxiliar->parametros);
            printf(") -> Funcion que retorna un %s y recibe %d parametros\n", auxiliar->tipo, cantidad);
        }
        auxiliar = auxiliar->siguiente;
    }
}

int imprimir_parametros(t_lista* self)
{
    int i = 0;
    char str[32] = "";

    t_nodo* auxiliar = self->inicio;

    while (auxiliar != NULL) {
        strcat(str, auxiliar->tipo);
        strcat(str, ", ");
        auxiliar = auxiliar->siguiente;
        i ++;
    }
    int length = strlen(str);
    str[length - 2] = '\0';
    printf("%s", str);
    return i;
}
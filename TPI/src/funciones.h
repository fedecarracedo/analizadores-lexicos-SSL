#ifndef FUNCIONES_H_
#define FUNCIONES_H_

	#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>

    extern int yylineno;

    typedef struct function {
        bool esFuncion;
        bool esFuncionDefinida;
    } t_funcion;

    typedef struct nodo {
		char tipo[32];
        char identificador[32];
        struct nodo *siguiente;
        struct function funcion; 
        struct lista *parametros;
	} t_nodo;

    typedef struct lista{
		t_nodo *inicio;
		int cantidad_nodos;
	} t_lista;

    t_nodo* crear_nodo(char* tipo, char* identificador, bool funcion, bool esFuncionDefinida);                              // Crea un nodo generico
    t_lista* crear_lista(void);                                                                                             // Iniciliza una lista
    void agregar_lista(t_lista* self, t_nodo* nodo);                                                                        // Agrega un nodo a la lista
    void copiar_lista(t_lista* destino, t_lista* origen);                                                                   // Copia una lista
    void vaciar_lista(t_lista* self);                                                                                       // Elimina nodos de una lista
    void crear_nodo_parametro(t_lista* self, char* tipo, char* identificador);                                              // Crea un nodo parametro de una funcion y lo agrega a la lista de parametros
    void crear_nodo_variable(t_lista* self, char* tipo, char* identificador);                                               // Crea un nodo de una variable y lo agrega a la lista de parametros
    void crear_nodo_funcion(t_lista* self, char* tipo, char* identificador, t_lista* parametros, bool esFuncionDefinida);   // Crea un nodo funcion y acopla la lista de parametros
    bool existe(t_lista* self, char* identificador);                                                                        // Valida la existencia del indentificador en la lista
    bool definirFuncion(t_lista* self, char* identificador);
    char* obtener_tipo(t_lista* self, char* str);                                                                           // Devuelve el tipo de dato de los argumentos de una funcion invocada
    void controlar_invocacion_funcion(t_lista* self, char* identificador, t_lista* parametros);                             // Valida que la cantidad y tipos de parametros en la invocacion sean correctos
    void controlar_cantidad_tipos(t_lista* self, t_lista* parametros);                                                      // Valida que la cantidad y tipos de parametros en la invocacion sean correctos
    void imprimir_ts(t_lista* self);
    void imprimir_variables(t_lista* self);
    void imprimir_funciones(t_lista* self);
    int imprimir_parametros(t_lista* self);

    void validar_suma(char* tipo1, char* tipo2);

    void copiar_especial(char* str1, char* str2);
    void imprimir_especial(int linea, char* tipo, char* identificador);
    void remover_especial(char* str1);

#endif /*FUNCIONES_H_*/
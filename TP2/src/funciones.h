#ifndef FUNCIONES_H_
#define FUNCIONES_H_

	#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
	#include <stdbool.h>
	#include <math.h>

	typedef struct nodo {
		char* lexema;
		int valor;
		struct nodo *siguiente;
	} t_nodo;

	typedef struct {
		t_nodo *inicio;
		int cantidad_nodos;
	} t_lista;    

    t_nodo* nodo_crear(char*, int);
	void nodo_agregar_al_inicio(t_lista*, t_nodo*);
	void nodo_agregar_al_final(t_lista*, t_nodo*);
	void nodo_intercambiar(t_nodo*, t_nodo*);

    t_lista* lista_crear();
    void lista_agregar(t_lista*, char*);
	void lista_agregar_sin_repetir(t_lista*, char*);
	void lista_agregar_con_longitud(t_lista*, char*, int);
	void lista_agregar_con_linea(t_lista*, char*, int);

	int lista_buscar(t_lista*, char*, bool);
	void ordenar_ascendente(t_lista*, bool);

	void lista_mostrar(t_lista*, int);
	void lista_mostrar_solo_lexema(t_lista*);
	void lista_mostrar_cantidad(t_lista*);
	void lista_mostrar_longitud(t_lista*);
	void lista_mostrar_octal(t_lista*);
	void lista_mostrar_hexa(t_lista*);
	void lista_mostrar_decimal(t_lista*);
	void lista_mostrar_real(t_lista*);
	void lista_mostrar_una_linea(t_lista*);
	void lista_mostrar_multilinea(t_lista*);
	void lista_mostrar_nro_linea(t_lista*);

#endif /*FUNCIONES_H_*/
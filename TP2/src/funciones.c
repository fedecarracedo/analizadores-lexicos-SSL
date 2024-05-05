#include "funciones.h"

t_nodo* nodo_crear(char* lexema, int valor)
{
	t_nodo* nodo = malloc(sizeof(t_nodo));
	nodo->lexema = strdup(lexema);
	nodo->valor = valor;
	nodo->siguiente = NULL;
	return nodo;
}

void nodo_agregar_al_inicio(t_lista* self, t_nodo* nodo)
{
    nodo->siguiente = self->inicio;
    self->inicio = nodo;
    self->cantidad_nodos++;
}

void nodo_agregar_al_final(t_lista* self, t_nodo* nodo)
{
	t_nodo* auxiliar;

	// Cubro condicion de lista vacia
	if(!self->inicio) {
		self->inicio = nodo;
		self->cantidad_nodos++;
		return;
	}
	// Si la lista no esta vacia, busco el puntero "siguiente" del ultimo nodo para enganchar el nuevo
	auxiliar = self->inicio;
	while(auxiliar->siguiente != NULL)
		auxiliar = auxiliar->siguiente;
	auxiliar->siguiente = nodo;
    self->cantidad_nodos++;
}

void nodo_intercambiar(t_nodo* nodo_a, t_nodo* nodo_b) 
{
	char* tmp_lexema;
	int tmp_valor;

	tmp_lexema = nodo_a->lexema;
	tmp_valor = nodo_a->valor;
	nodo_a->lexema = nodo_b->lexema;
	nodo_a->valor = nodo_b->valor;
	nodo_b->lexema = tmp_lexema;
	nodo_b->valor = tmp_valor;		
}

t_lista* lista_crear()
{
	t_lista* lista = malloc(sizeof(t_lista));
	lista->inicio = NULL;
	lista->cantidad_nodos = 0;
	return lista;
}

void lista_agregar(t_lista* self, char* lexema)
{
	t_nodo* nodo = nodo_crear(lexema, 0);
	nodo_agregar_al_final(self, nodo);
}

void lista_agregar_sin_repetir(t_lista* self, char* lexema)
{
	t_nodo* nodo = nodo_crear(lexema, 1);
	if(!lista_buscar(self, lexema, true))
		nodo_agregar_al_final(self, nodo);
}

void lista_agregar_con_longitud(t_lista* self, char* lexema, int longitud)
{
	t_nodo* nodo = nodo_crear(lexema, longitud-2);
	if(!lista_buscar(self, lexema, false))
		nodo_agregar_al_final(self, nodo);
}

void lista_agregar_con_linea(t_lista* self, char* lexema, int linea)
{
	t_nodo* nodo = nodo_crear(lexema, linea);
	nodo_agregar_al_final(self, nodo);
}

int lista_buscar(t_lista* self, char* lexema, bool flag_actualizar)
{
	t_nodo* auxiliar;
	auxiliar = self->inicio;

	while(auxiliar != NULL) {
		if (!strcmp(auxiliar->lexema, lexema)) {
			if (flag_actualizar) 
				return auxiliar->valor++;
			else
				return 1;
		}
		else {
			auxiliar = auxiliar->siguiente;
		}	
	}
	return 0;
}

void ordenar_ascendente(t_lista* self, bool ordenar_por_lexema)
{
	t_nodo* pivote;													// i
	t_nodo* actual;													// j

	if(!self->inicio)
		return;

	// Ordenamiento burbuja
	pivote = self->inicio;											// i = 0
	while(pivote->siguiente != NULL) {								// i < total - 1
		actual = pivote->siguiente;									// j = i + 1
		while(actual != NULL) {										// j < total
			if(ordenar_por_lexema) {									// COMPARO LEXEMA
				if (strcmp(pivote->lexema, actual->lexema) > 0)		// lexema[i] > lexema[j]
					nodo_intercambiar(pivote, actual);
			}
			else {													// COMPARO VALOR
				if (pivote->valor > actual->valor)					// lexema[i] > lexema[j]
					nodo_intercambiar(pivote, actual);
			}
			actual = actual->siguiente;								// j++
		}
		pivote = pivote->siguiente;									// i++
	}
	return;
}

void lista_mostrar(t_lista* self , int categoriaLexica)
{
	switch(categoriaLexica)
	{
		case 0:
			printf("\n/*** Identificadores ***/\n");
			ordenar_ascendente(self, true);
			lista_mostrar_cantidad(self);
			printf("------------------------------\n");
			break;
		case 1:
			printf("/*** Literales Cadena ***/\n");
			ordenar_ascendente(self, false);
			lista_mostrar_longitud(self);
			printf("------------------------------\n");
			break;
		case 2:
			printf("/*** Palabras Reservadas -> Otros ***/\n");
			lista_mostrar_solo_lexema(self);
			printf("------------------------------\n");
			break;
		case 3:
			printf("/*** Palabras Reservadas -> tipos de dato ***/\n");
			lista_mostrar_solo_lexema(self);
			printf("------------------------------\n");
			break;
		case 4:
			printf("/*** Palabras Reservadas -> estructuras de control ***/\n");
			lista_mostrar_solo_lexema(self);
			printf("------------------------------\n");
			break;
		case 5:
			printf("/*** Constantes Octal ***/\n");
			lista_mostrar_octal(self);
			printf("------------------------------\n");
			break;
		case 6:
			printf("/*** Constantes Hexadecimal ***/\n");
			lista_mostrar_hexa(self);
			printf("------------------------------\n");
			break;
		case 7:
			printf("/*** Constantes Decimal ***/\n");
			lista_mostrar_decimal(self);		
			printf("------------------------------\n");
			break;						
		case 8:
			printf("/*** Constantes Real ***/\n");
			lista_mostrar_real(self);
			printf("------------------------------\n");
			break;
		case 9:
			printf("/*** Constantes Caracter ***/\n");
			lista_mostrar_solo_lexema(self);		
			printf("------------------------------\n");
			break;
		case 10:
			printf("/*** Operadores ***/\n");
			lista_mostrar_cantidad(self);
			printf("------------------------------\n");
			break;
		case 11:
			printf("/*** Comentarios de una linea ***/\n");
			lista_mostrar_una_linea(self);
			printf("------------------------------\n");
			printf("/*** Comentarios multilinea ***/\n");
			lista_mostrar_multilinea(self);
			printf("------------------------------\n");
			break;
		case 12:
			printf("/*** No reconocidos ***/\n");
			lista_mostrar_nro_linea(self);
			printf("------------------------------\n");
			break;
		default:
			break;	
	}
}

void lista_mostrar_solo_lexema(t_lista* self)
{
	t_nodo* auxiliar;
	auxiliar = self->inicio;
	
	while(auxiliar != NULL) {
		printf("Lexema: %s\n", auxiliar->lexema);
		auxiliar = auxiliar->siguiente;
	}
}

void lista_mostrar_cantidad(t_lista* self)
{
	t_nodo* auxiliar;
	auxiliar = self->inicio;
	
	while(auxiliar != NULL) {
		printf("Lexema: %s\t, cantidad de ocurrencias: %d\n", auxiliar->lexema, auxiliar->valor);
		auxiliar = auxiliar->siguiente;
	}
}

void lista_mostrar_longitud(t_lista* self)
{
	t_nodo* auxiliar;
	auxiliar = self->inicio;
	
	while(auxiliar != NULL) {
		printf("Lexema: %s\t, longitud: %d\n", auxiliar->lexema, auxiliar->valor);
		auxiliar = auxiliar->siguiente;
	}
}

void lista_mostrar_octal(t_lista* self)
{
	char* tmp;
	t_nodo* auxiliar;
	auxiliar = self->inicio;
	
	while(auxiliar != NULL) {
		printf("Lexema: %s\t, valor en decimal: %ld\n", auxiliar->lexema, strtol(auxiliar->lexema, &tmp, 8));
		auxiliar = auxiliar->siguiente;
	}
}

void lista_mostrar_hexa(t_lista* self)
{
	char* tmp;
	t_nodo* auxiliar;
	auxiliar = self->inicio;
	
	while(auxiliar != NULL) {
		printf("Lexema: %s\t, valor en decimal: %ld\n", auxiliar->lexema, strtol(auxiliar->lexema, &tmp, 16));
		auxiliar = auxiliar->siguiente;
	}
}

void lista_mostrar_decimal(t_lista* self)
{
	int tmp = 0;
	t_nodo* auxiliar;
	auxiliar = self->inicio;
	
	while(auxiliar != NULL) {
		tmp += atoi(auxiliar->lexema);
		printf("Lexema: %s\t, valor en decimal: %d\n", auxiliar->lexema, atoi(auxiliar->lexema));
		auxiliar = auxiliar->siguiente;
	}
	printf("Sumatoria total: %d\n", tmp);
}

void lista_mostrar_real(t_lista* self)
{
	double mantisa, parte_entera;
	t_nodo* auxiliar;
	auxiliar = self->inicio;
	
	while(auxiliar != NULL) {
		mantisa = modf(atof(auxiliar->lexema), &parte_entera);
		printf("Lexema: %s\t, parte entera: %g\t, mantisa: %g\n", auxiliar->lexema, parte_entera, mantisa);
		auxiliar = auxiliar->siguiente;
	}
}

void lista_mostrar_una_linea(t_lista* self)
{
	t_nodo* auxiliar;
	auxiliar = self->inicio;
	
	while(auxiliar != NULL) {
		if(auxiliar->valor == 0)
			printf("Lexema: %s\n", auxiliar->lexema);
		auxiliar = auxiliar->siguiente;
	}
}

void lista_mostrar_multilinea(t_lista* self)
{
	t_nodo* auxiliar;
	auxiliar = self->inicio;
	
	while(auxiliar != NULL) {
		if(auxiliar->valor == 1)
			printf("Lexema: %s\n", auxiliar->lexema);
		auxiliar = auxiliar->siguiente;
	}
}

void lista_mostrar_nro_linea(t_lista* self)
{
	t_nodo* auxiliar;
	auxiliar = self->inicio;
	
	while(auxiliar != NULL) {
		printf("Caracter no reconocido: %s\t, en linea: %d\n", auxiliar->lexema, auxiliar->valor);
		auxiliar = auxiliar->siguiente;
	}
}
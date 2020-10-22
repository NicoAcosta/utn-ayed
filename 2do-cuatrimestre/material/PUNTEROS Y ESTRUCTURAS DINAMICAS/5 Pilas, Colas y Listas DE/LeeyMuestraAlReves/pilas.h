#ifndef PILAS_H_INCLUDED
#define PILAS_H_INCLUDED

#include "listasSE.h"

/*Nodo de pila*/
typedef NodoListaSE NodoPila;

/*FUNCIONALIDAD DE PILA*/
void push(NodoPila *&pila, tipoinfo info);
tipoinfo pop(NodoPila *&pila);

#endif // PILAS_H_INCLUDED

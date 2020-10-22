#ifndef LISTASSE_H_INCLUDED
#define LISTASSE_H_INCLUDED
#include <iostream>
typedef int tipoinfo;
struct NodoListaSE
{
    tipoinfo info;             // Datos de el nodo
    NodoListaSE   *sgte;  // Puntero al siguiente nodo

};


void InsertarSiguiente (NodoListaSE  *&n, tipoinfo x);
void BorrarSiguiente(NodoListaSE  *n);
NodoListaSE *ObtenerSiguiente(NodoListaSE  *n);
NodoListaSE *ObtenerUltimo(NodoListaSE * p);
NodoListaSE* BuscarNodo(NodoListaSE * raiz, tipoinfo infobuscada);
NodoListaSE* BuscarNodoAnterior(NodoListaSE * raiz, NodoListaSE * anterior_a);
void borrarNodo(NodoListaSE *& raiz, NodoListaSE * aborrar);
void InsertarAlFinal(NodoListaSE *&lista, tipoinfo x);
void borrarLista(NodoListaSE *&lista);
#endif // LISTASSE_H_INCLUDED

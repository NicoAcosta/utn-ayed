#ifndef LISTASDE_H_INCLUDED
#define LISTASDE_H_INCLUDED
#include <iostream>
typedef int tipoinfo;
struct NodoListaDE
{
    tipoinfo info;             // Datos de el nodo
    NodoListaDE *sgte;  // Puntero al siguiente nodo
    NodoListaDE *ant;

};


void ListaDEInsertarSiguiente (NodoListaDE  *&n, tipoinfo x);
void ListaDEBorrarSiguiente(NodoListaDE  *n);
NodoListaDE *ListaDEObtenerSiguiente(NodoListaDE  *n);
NodoListaDE *ListaDEObtenerUltimo(NodoListaDE * p);
NodoListaDE* ListaDEBuscarNodo(NodoListaDE * raiz, tipoinfo infobuscada);
NodoListaDE* ListaDEBuscarNodoAnterior(NodoListaDE *nodo);
void ListaDEborrarNodo(NodoListaDE *& raiz, NodoListaDE * aborrar);
void ListaDEInsertarAlFinal(NodoListaDE *&lista, tipoinfo x);
void ListaDEborrarLista(NodoListaDE *&lista);


#endif // LISTASDE_H_INCLUDED

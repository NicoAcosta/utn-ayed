#ifndef COLAS_H_INCLUDED
#define COLAS_H_INCLUDED

#include "listasSE.h"

/*Nodo de cola*/
typedef NodoListaSE NodoCola;

void cqueue(NodoCola *&cola, tipoinfo x);
tipoinfo dequeue(NodoCola *&cola);

#endif // COLAS_H_INCLUDED

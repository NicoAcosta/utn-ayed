#include "pilas.h"


void push(NodoPila *&pila, tipoinfo info)
{
    InsertarAlFinal(pila,info);
}


tipoinfo pop(NodoPila *&pila)
{
    NodoListaSE *ultimo;
    ultimo= ObtenerUltimo(pila);
    if (ultimo)
    {
        tipoinfo aux = ultimo->info;
        borrarNodo(pila,ultimo);
        return aux;
    }
    return NULL;
}

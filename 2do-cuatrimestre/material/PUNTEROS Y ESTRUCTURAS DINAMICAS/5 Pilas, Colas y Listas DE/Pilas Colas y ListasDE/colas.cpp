#include "colas.h"

void cqueue(NodoCola *&cola, tipoinfo x)
{
    InsertarAlFinal(cola,x);
}

tipoinfo dequeue(NodoCola *&cola)
{
    NodoCola *aux;
    tipoinfo x;
    if (cola)
    {
        aux= cola;
        x= aux->info;
        cola= aux->sgte;
        delete aux;
        return x;
    }
    return NULL;
}

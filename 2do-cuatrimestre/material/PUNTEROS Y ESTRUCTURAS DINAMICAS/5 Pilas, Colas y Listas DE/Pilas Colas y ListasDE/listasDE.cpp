#include "listasDE.h"
#include <iostream>
void ListaDEInsertarSiguiente (NodoListaDE  *&n, tipoinfo x)
{
    NodoListaDE *nuevo= new NodoListaDE();
    nuevo->info=x;
    if (n!=NULL)
    {
        nuevo->sgte= n->sgte;
        n->sgte = nuevo;
        nuevo->ant=n;
        if (nuevo->sgte)
        {
            nuevo->sgte->ant = nuevo;
        }
    }
    else
    {
        nuevo->sgte= n;
        n= nuevo;
        nuevo->ant=NULL;
    }

    return;
}

void ListaDEBorrarSiguiente(NodoListaDE  *n)
{
    NodoListaDE  *aborrar = n->sgte;
    NodoListaDE  *sgteaborrar;
    if (aborrar)
        sgteaborrar= aborrar->sgte;
    else
        sgteaborrar = NULL;
    n->sgte = sgteaborrar;
    sgteaborrar->ant=n;
    delete aborrar;
    return;
}

NodoListaDE *ListaDEObtenerSiguiente(NodoListaDE  *n)
{
    if (n)
        return n->sgte;
    else
        return NULL;
}

NodoListaDE *ListaDEObtenerUltimo(NodoListaDE * p)
{
    if (p)
    {
        while (p->sgte)
        {
            p = p->sgte;
        }
    }
    return p;

}

NodoListaDE* ListaDEBuscarNodo(NodoListaDE * raiz, tipoinfo infobuscada)
{
    NodoListaDE *p=raiz;
    while (p && (p->info != infobuscada))
    {
        p = p->sgte;
    }
    return p;
}


NodoListaDE* ListaDEBuscarNodoAnterior(NodoListaDE *nodo)
{
    if (nodo && nodo->ant)
    {
        return nodo->ant;
    }
    else
        return NULL;
}

/*
BorrarNodo: recibe el puntero del nodo a borrar
*/
void ListaDEborrarNodo(NodoListaDE *&raiz,NodoListaDE *aborrar)
{
    NodoListaDE *auxsgte ;
    NodoListaDE *auxant;

    if (aborrar && aborrar->ant)
    {
        auxant= aborrar->ant;
        ListaDEBorrarSiguiente(auxant);
    }
    else if (aborrar)
    {
        auxsgte= aborrar->sgte;
        delete aborrar;
        auxsgte->ant=NULL;
        raiz= auxsgte;
    }
    return;
}


void ListaDEInsertarAlFinal(NodoListaDE *&lista, tipoinfo x)
{
    NodoListaDE *aux;
    if (lista)
    {
        aux=ListaDEObtenerUltimo(lista);
        ListaDEInsertarSiguiente(aux,x);
    }
    else
    {
        ListaDEInsertarSiguiente(lista,x);
    }
    return;
}

void ListaDEborrarLista(NodoListaDE *&lista)
{
    NodoListaDE *anterior;
    NodoListaDE *paux;
    while (lista!=NULL)
    {
        anterior=NULL;
        paux= lista;
        while (paux && paux->sgte)
        {
            anterior = paux;
            paux= paux->sgte;
        }
        if (paux)
        {
            delete paux;
            if (anterior!=NULL)
                anterior->sgte=NULL;
            else
                lista =NULL;
        }
    }
    return;
}

#include <stdio.h> //Se agrega para poder usar archivos
#include <iostream>
#include <conio.h>
#include <cstring>
#include "listaMaterias.h"
using namespace std;

void ListaMateriaInsertarSiguiente (NodoListaSEMateria  *&n, Materia x)
{
    NodoListaSEMateria *nuevo= new NodoListaSEMateria();
    nuevo->info=x;
    if (n!=NULL)
    {
        nuevo->sgte= n->sgte;
        n->sgte = nuevo;
    }
    else
    {
        nuevo->sgte= n;
        n= nuevo;
    }

    return;
}

void ListaMateriaBorrarSiguiente(NodoListaSEMateria  *n)
{
    NodoListaSEMateria  *aborrar = n->sgte;
    NodoListaSEMateria  *sgteaborrar;
    if (aborrar)
        sgteaborrar= aborrar->sgte;
    else
        sgteaborrar = NULL;
    n->sgte = sgteaborrar;
    delete aborrar;
    return;
}

NodoListaSEMateria *ListaMateriaObtenerSiguiente(NodoListaSEMateria  *n)
{
    if (n)
        return n->sgte;
    else
        return NULL;
}

NodoListaSEMateria *ObtenerUltimoMateria(NodoListaSEMateria * p)
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




NodoListaSEMateria* ListaMateriaBuscarNodoAnterior(NodoListaSEMateria * raiz, NodoListaSEMateria * anterior_a)
{
    NodoListaSEMateria *p =NULL;
    if (raiz != anterior_a)
    {
        p = raiz;
        while (p && (p->sgte!= anterior_a) )
        {
            p = p->sgte;
        }
        return p;
    }
    else
        return NULL;
}

/*
BorrarNodo: recibe por parámetro lista y el puntero a borrar
*/
void borrarNodoMateria(NodoListaSEMateria *& raiz, NodoListaSEMateria * aborrar)
{
    if (raiz && aborrar)
    {
        if (aborrar==raiz)
        {
            raiz = raiz->sgte;
            delete aborrar;
        }
        else
        {
            NodoListaSEMateria *x = ListaMateriaBuscarNodoAnterior(raiz,aborrar);
            ListaMateriaBorrarSiguiente(x);
        }
    }
    return;
}


void ListaMateriasInsertarAlFinal(NodoListaSEMateria *&lista, Materia x)
{
    NodoListaSEMateria *aux;
    aux=ObtenerUltimoMateria(lista);
    if (aux)
    {
        ListaMateriaInsertarSiguiente(aux,x);
    }
    else
    {
        ListaMateriaInsertarSiguiente(lista,x);
    }
    return;
}

void ListaMateriaborrarLista(NodoListaSEMateria *&lista)
{
    NodoListaSEMateria *anterior;
    NodoListaSEMateria *paux;
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

void ListaMateriaListar(NodoListaSEMateria *lista)
{
    while (lista)
    {
        cout << "Nombre: " << lista->info.nombreMateria << endl;
        cout << "Fecha: " << lista->info.fechaAprobacion<< endl;
        cout << "Nota: " << lista->info.nota << ", Libro: " << lista->info.libro << ", Folio: " << lista->info.folio << endl;
        lista = lista->sgte;
    }
}

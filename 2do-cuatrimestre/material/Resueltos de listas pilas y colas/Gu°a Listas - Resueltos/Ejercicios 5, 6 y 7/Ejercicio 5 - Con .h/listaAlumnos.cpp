#include <stdio.h> //Se agrega para poder usar archivos
#include <iostream>
#include <conio.h>
#include <cstring>
#include "listaAlumnos.h"
using namespace std;

void ListaAlumnoInsertarSiguiente (NodoListaSEAlumno  *&n, Alumno x)
{
    NodoListaSEAlumno *nuevo= new NodoListaSEAlumno();
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

void ListaAlumnoBorrarSiguiente(NodoListaSEAlumno  *n)
{
    NodoListaSEAlumno  *aborrar = n->sgte;
    NodoListaSEAlumno  *sgteaborrar;
    if (aborrar)
        sgteaborrar= aborrar->sgte;
    else
        sgteaborrar = NULL;
    n->sgte = sgteaborrar;
    delete aborrar;
    return;
}

NodoListaSEAlumno *ListaAlumnoObtenerSiguiente(NodoListaSEAlumno  *n)
{
    if (n)
        return n->sgte;
    else
        return NULL;
}

NodoListaSEAlumno *ObtenerUltimoAlumno(NodoListaSEAlumno * p)
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

NodoListaSEAlumno* BuscarAlumnoPorDNI(NodoListaSEAlumno * raiz, char dnibuscado[])
{
    NodoListaSEAlumno *p=raiz;
    while (p && (strcmp(p->info.dni,dnibuscado)))
    {
        p = p->sgte;
    }
    return p;
}


NodoListaSEAlumno* ListaAlumnoBuscarNodoAnterior(NodoListaSEAlumno * raiz, NodoListaSEAlumno * anterior_a)
{
    NodoListaSEAlumno *p =NULL;
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
void borrarNodoAlumno(NodoListaSEAlumno *& raiz, NodoListaSEAlumno * aborrar)
{
    if (raiz && aborrar)
    {
        if (aborrar=raiz)
        {
            raiz = raiz->sgte;
            delete aborrar;
        }
        else
        {
            NodoListaSEAlumno *x = ListaAlumnoBuscarNodoAnterior(raiz,aborrar);
            ListaAlumnoBorrarSiguiente(x);
        }
    }
    return;
}


void ListaAlumnoborrarLista(NodoListaSEAlumno *&lista)
{
    NodoListaSEAlumno *anterior;
    NodoListaSEAlumno *paux;
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

void ListaAlumnoListar(NodoListaSEAlumno *lista)
{
    while (lista)
    {
        cout << "======== DATOS DEL ALUMNO " << lista->info.apellido << "========" << endl;
        cout << "Apellido y nombre: " << lista->info.apellido << ", " << lista->info.nombre << endl;
        cout << "DNI: " << lista->info.dni << endl;
        cout << "Legajo: " << lista->info.legajo << endl;
        cout << "Carrera: " << lista->info.codcarrera<< endl << endl;
        lista = lista->sgte;
    }
}

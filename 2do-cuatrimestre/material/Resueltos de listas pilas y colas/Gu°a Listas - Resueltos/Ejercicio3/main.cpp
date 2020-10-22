/* LISTAS SE */

#include <iostream>
#include <conio.h>
using namespace std;


struct NodoListaSE
{
    int info;             // Datos de el nodo
    NodoListaSE   *sgte;  // Puntero al siguiente nodo

};

void InsertarSiguiente (NodoListaSE  *&n, int x)
{
    NodoListaSE *nuevo= new NodoListaSE();
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


NodoListaSE *ObtenerUltimo(NodoListaSE * p)
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

void InsertarAlFinal (NodoListaSE  *&n, int x)
{
    NodoListaSE *nuevo= new NodoListaSE();
    NodoListaSE *ultimo= NULL;
    nuevo->info=x;
    nuevo->sgte= NULL;
	if (n!=NULL)
    {

        ultimo = ObtenerUltimo(n);
        ultimo->sgte = nuevo;
    }
    else
    {
        n= nuevo;
    }
    return;
}


void BorrarSiguiente(NodoListaSE  *n)
{
    NodoListaSE  *aborrar = n->sgte;
    NodoListaSE  *sgteaborrar;
    if (aborrar)
        sgteaborrar= aborrar->sgte;
    else
        sgteaborrar = NULL;
    n->sgte = sgteaborrar;
    delete aborrar;
    return;
}

NodoListaSE *ObtenerSiguiente(NodoListaSE  *n)
{
    if (n)
        return n->sgte;
    else
        return NULL;
}

NodoListaSE* BuscarNodo(NodoListaSE * raiz, int infobuscada)
{
    NodoListaSE *p=raiz;
    while (p && (p->info != infobuscada))
    {
        p = p->sgte;
    }
    return p;
}


NodoListaSE* BuscarNodoAnterior(NodoListaSE * raiz, NodoListaSE * anterior_a)
{
    NodoListaSE *p =NULL;
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
void borrarNodo(NodoListaSE *& raiz, NodoListaSE * aborrar)
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
            NodoListaSE *x = BuscarNodoAnterior(raiz,aborrar);
            BorrarSiguiente(x);
        }
    }
    return;
}

void MostrarLista(NodoListaSE *lista)
{
    while (lista)
    {
        cout << lista->info << " | ";
        lista = ObtenerSiguiente(lista);
    }
    cout << endl;
}

void Intercalar(NodoListaSE *lista1, NodoListaSE *lista2, NodoListaSE *&lista3)
{
    while (lista1)
    {
        InsertarAlFinal(lista3, lista1->info);
        if (lista2)
        {
            InsertarAlFinal(lista3, lista2->info);
            lista2=lista2->sgte;
        }
        lista1= lista1->sgte;
    }
    while (lista2)
    {
        InsertarAlFinal(lista3, lista2->info);
        lista2=lista2->sgte;
    }
    return;
}

int main()
{

    NodoListaSE *lista1= NULL;
    NodoListaSE *lista2= NULL;
    NodoListaSE *lista3= NULL;
    NodoListaSE *aux=NULL;
    InsertarAlFinal(lista1,23);
    InsertarAlFinal(lista1,7);
    InsertarAlFinal(lista1,512);
    InsertarAlFinal(lista2,47);
    InsertarAlFinal(lista2,5);
    Intercalar(lista1, lista2, lista3);
    MostrarLista(lista3);
    getch();
    return 0;
}

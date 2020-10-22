#include <iostream>
#include <conio.h>
using namespace std;
struct Nodo
{
    int info;
    Nodo *sgte;
};

Nodo *obtenerUltimo(Nodo *lista)
{
    while (lista && lista->sgte)
        lista= lista->sgte;
    return lista;
}

/* Recibe la raíz de la lista (ptro a primer nodo) */
void AgregarNodoAlFinal(Nodo *&lista, int x)
{
    Nodo *paux;
    if (lista)
    {
        paux= obtenerUltimo(lista);
        paux->sgte= new Nodo();
        paux= paux->sgte;
        paux->info= x;
        paux->sgte=NULL;
    }
    else//CREAR EL PRIMER NODO
    {
        lista= new Nodo();
        lista->info=x;
        lista->sgte=NULL;
    }
    return;
}

void push(Nodo *&pila, int elemento)
{
    AgregarNodoAlFinal(pila,elemento);
}

int pop(Nodo *&pila)
{
        int elemento;
        Nodo *anterior, *paux;
        anterior=NULL;
        paux= pila;
        while (paux && paux->sgte)
        {
            anterior = paux;
            paux= paux->sgte;
        }
        if (paux)
        {
            elemento = paux->info;
            delete paux;
            if (anterior!=NULL)
                anterior->sgte=NULL;
            else
                pila =NULL;
            return elemento;
        }
        else
        {
            cout << "ERROR: PILA VACIA." << endl;
            return 0;
        }
}

int pop_v2(Nodo *&pila, bool &error)
{
        int elemento;
        error = false;
        Nodo *anterior, *paux;
        anterior=NULL;
        paux= pila;
        while (paux && paux->sgte)
        {
            anterior = paux;
            paux= paux->sgte;
        }
        if (paux)
        {
            elemento = paux->info;
            delete paux;
            if (anterior!=NULL)
                anterior->sgte=NULL;
            else
                pila =NULL;
            return elemento;
        }
        else
        {
            error = true;
            return 0;
        }
}

void queue(Nodo *&cola, int elemento)
{
    AgregarNodoAlFinal(cola,elemento);
}

int unqueue(Nodo *&cola)
{
    int elemento;
    Nodo *aux;
    if (cola)
    {
        elemento = cola->info;
        aux= cola->sgte;
        delete cola;
        cola = aux;
        return elemento;
    }
    else
    {
        cout << "ERROR: COLA VACIA" << endl;
        return 0;
    }
}

int main()
{
    /* PILAS */
    bool error;
    Nodo *pila=NULL;
    push(pila,5);
    push(pila,13);
    push(pila,27);
    push(pila,7);
    push(pila,32);
    int x;
    while (x=pop(pila))
        cout << "pop: " << x << endl;
    push(pila,0);
    x=pop_v2(pila,error);
    if(!error)
        cout << "El elemento leido es " << x << endl;
    else
        cout << "Error: vacio" << endl;
    /* COLAS */
    Nodo *cola=NULL;
    queue(cola, 8);
    queue(cola, 18);
    queue(cola, 28);
    queue(cola, 38);
    while (x=unqueue(cola))
        cout << "unqueue: " << x << endl;
    getch();
    return 0;
}

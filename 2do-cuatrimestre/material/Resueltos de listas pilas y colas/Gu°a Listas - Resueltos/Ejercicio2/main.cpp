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

int main()
{

    NodoListaSE *lista1=NULL;
    NodoListaSE *lista2=NULL;
    NodoListaSE *aux=NULL;
    /*Agregamos nodos en la lista 1*/
    InsertarSiguiente(lista1,1);
    aux = ObtenerUltimo(lista1);
    InsertarSiguiente(aux,2);
    aux = ObtenerUltimo(lista1);
    InsertarSiguiente(aux,3);
    aux = ObtenerUltimo(lista1);
    /* Ahora agregamos en la lista 2, pero usando InsertarAlFinal*/
    InsertarAlFinal(lista2,21);
    InsertarAlFinal(lista2,22);
    InsertarAlFinal(lista2,23);
    cout << "Presione una tecla para mostrar la lista 1" << endl;
    getch();
    MostrarLista(lista1);
    cout << "Presione una tecla para mostrar la lista 2" << endl;
    getch();
    MostrarLista(lista2);
    /* Concatenamos redireccionando memoria */
    aux = ObtenerUltimo(lista1);
    aux->sgte = lista2;
    cout << "Presione una tecla para mostrar las listas concatenadas" << endl;
    getch();
    MostrarLista(lista1);
    cout << "Qué pasa si se cambia un valor de un nodo de la lista2?" << endl;
    cout << "Presione una tecla:" << endl;
    getch();
    cout << "Lista 2 (direccion primer nodo " << lista2 << "):";
    lista2->sgte->info=856;
    MostrarLista(lista2);
    cout << "Lista 1:";
    MostrarLista(lista1);
    getch();
    /*Este método concatenó las listas redireccionando el ultimo puntero
    de la lista 1, como todavía tenemos el puntero lista2 apuntando al que,
    originalmente era el primer nodo de la lista2, podemos desconcatenarlas:*/
    cout << "Desconcatena listas (presione una tecla)" << endl;
    getch();
    aux =lista1;
    if (aux!=NULL)
    {
            while(aux->sgte!=lista2)
            {
                aux=aux->sgte;
            }
            aux->sgte=NULL;
    }
    cout << "Lista 1 desconcatenada:" << endl;
    MostrarLista(lista1);
    cout << "Lista 2 desconcatenada:" << endl;
    MostrarLista(lista2);
    /*Concatenación de listas creando los nodos respectivos */
    NodoListaSE *lista3 = NULL;
    cout << "Lista 3 concatenada nuevamente pero con nodos propios:" << endl;
    aux=lista1;
	while (aux!=NULL)
    {
        InsertarAlFinal(lista3,aux->info);
        aux=aux->sgte;
    }
	aux=lista2;
	while (aux!=NULL)
    {
        InsertarAlFinal(lista3,aux->info);
        aux=aux->sgte;
    }
    cout << "lista 3: ";
    MostrarLista(lista3);
    getch();
    return 0;
}

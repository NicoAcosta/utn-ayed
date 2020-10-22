/* LISTAS SE */

#include <iostream>
#include <conio.h>
using namespace std;


struct NodoListaSE
{
    int info;             // Datos de el nodo
    NodoListaSE   *sgte;  // Puntero al siguiente nodo

};



NodoListaSE *ObtenerSiguiente(NodoListaSE  *n)
{
    if (n)
        return n->sgte;
    else
        return NULL;
}

void MostrarLista(NodoListaSE *milista)
{
    while (milista)
    {
        cout << milista->info << "   " << milista <<endl;
        milista = ObtenerSiguiente(milista);
    }
}

void InsertarSiguiente (NodoListaSE  *&n, int x)
{
    NodoListaSE *nuevo= new NodoListaSE();
    nuevo->info=x;
    if (n)
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

NodoListaSE* BuscarNodo(NodoListaSE * p, int infobuscada)
{
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
        if (aborrar==raiz)
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


void InsertarAlFinal(NodoListaSE *&lista, int x)
{
    NodoListaSE *aux;
    aux=ObtenerUltimo(lista);
    if (aux)
    {
        InsertarSiguiente(aux,x);
    }
    else
    {
        InsertarSiguiente(lista,x);
    }
    return;
}

void borrarLista(NodoListaSE *&lista)
{
    NodoListaSE *anterior;
    NodoListaSE *paux;
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
int main()
{

    NodoListaSE *milista = NULL;
    NodoListaSE *aux;
    NodoListaSE *x;
    InsertarSiguiente(milista,5);
    aux = ObtenerUltimo(milista);
    InsertarSiguiente(aux,8);
    aux = ObtenerUltimo(milista);
    InsertarSiguiente(aux,3);
    aux = ObtenerUltimo(milista);
    InsertarSiguiente(aux,12);
    MostrarLista(milista);
    //Probamos obtener el ultimo
    x = ObtenerUltimo(milista);
    cout << "Usando ObtenerUltimo encontramos que el ultimo dato es: " << x->info << endl;
    //Probamos buscar el elemento d
    cout << "Buscamos un 3 con BuscarNodo."<< endl;
    x = BuscarNodo(milista,3);
    if (x)
        cout << "El dato buscado es: " << x->info << endl;
    else
        cout << "El elemento no existe" << endl;
    //Probamos buscar un elemento que no existe
    cout << "Probamos buscar un elemento que no existe, se busca un 27." << endl;
    x = BuscarNodo(milista,27);
    if (x)
        cout << "El dato buscado es: " << x->info << endl;
    else
        cout << "El elemento no existe" << endl;
    cout  << "Agregamos un 9 al lado del 8" << endl;
    x = BuscarNodo(milista,8);
    if (x)
        InsertarSiguiente(x,9);
    MostrarLista(milista);
    cout << "Probamos buscar nodo anterior al que contiene 3, para luego, desde este nodo encontrado, borrar el que contiene 3" << endl;
    x = BuscarNodoAnterior(milista,BuscarNodo(milista,3));
    BorrarSiguiente(x);
    MostrarLista(milista);
    //borra toda la lista para liberar memoria
    cout << "Borramos toda la lista con borrarLista, este procedimiento se encarga de hacer delete de todos los nodos." << endl;
    borrarLista(milista);
    char c = getch();
    return 0;
}

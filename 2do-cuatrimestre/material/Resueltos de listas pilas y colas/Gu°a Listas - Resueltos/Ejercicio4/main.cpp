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

int ContarNodos(NodoListaSE *lista)
{
    int cont=0;
    while (lista)
    {
        cont++;
        lista = ObtenerSiguiente(lista);
    }
    return cont;
}


void burbujaListas(NodoListaSE *&lista)
{
    int n,i,j;
    NodoListaSE *aux;
    NodoListaSE *anterior;
    NodoListaSE *proximo;
    bool inter; //Para ver si hubo intercambio  o no
    n= ContarNodos(lista);
    for (i=0;i<=n-2;i++)
    {
        aux= lista;//Arranca desde el principio
        for (j=0;j<=n-2-i;j++)
        {
            if (aux->sgte->info < aux->info)
            {
                inter= true;
                if (aux==lista)
                {
                    lista= aux->sgte;
                    proximo= lista->sgte;
                    lista->sgte=aux;
                    aux->sgte=proximo;
                }
                else
                {
                    anterior=BuscarNodoAnterior(lista,aux);
                    proximo=aux->sgte;
                    anterior->sgte= proximo;
                    aux->sgte= proximo->sgte;
                    proximo->sgte= aux;
                }
            }
            else
                inter=false;
            if (!inter)
            {
                aux= aux->sgte;
            }
        }
    }
    return;
}



int main()
{

    NodoListaSE *lista1= NULL;
    int i;
    for (i=0;i<=50;i++)
    {
        InsertarAlFinal(lista1,100-i);
    }
    MostrarLista(lista1);
    burbujaListas(lista1);
    cout << "Presione una tecla para ordenar" << endl;
    getch();
    MostrarLista(lista1);
    getch();
    return 0;
}

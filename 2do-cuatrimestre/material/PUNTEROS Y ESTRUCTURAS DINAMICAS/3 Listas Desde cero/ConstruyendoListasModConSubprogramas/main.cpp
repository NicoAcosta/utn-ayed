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
    {
        lista= lista->sgte;
    }
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

void borrarLista(Nodo *&lista)
{
    Nodo *anterior;
    Nodo *paux;
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
}


int main()
{
    Nodo *inicio=NULL;
    Nodo *paux;
    cout << "Cada nodo ocupa " << sizeof(Nodo) << "bytes" << endl;
    AgregarNodoAlFinal(inicio,5);
    AgregarNodoAlFinal(inicio,27);
    AgregarNodoAlFinal(inicio,32);
    /*vamos a mostrar el contenido de la lista*/
    cout << "Lista toda la lista:" << endl;
    paux = inicio;
    while (paux)//Es equivalente a while (paux!=NULL)
    {
        cout << "Info: " << paux->info << endl;
        cout << "Siguiente en: " << paux->sgte << endl;
        cout << "================" << endl;
        paux = paux->sgte;
    }

    borrarLista(inicio);
    cout << "Lista apunta a " << inicio << endl;
    getch();
    return 0;
}

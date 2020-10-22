#include <iostream>
#include <conio.h>
using namespace std;

struct Nodo
{
    int info;
    Nodo *sgte;
};


void insertarOrdenado(Nodo *&lista, int ainsertar)
{
    Nodo *paux = lista;
    Nodo *anterior =NULL;
    while (paux && paux->info < ainsertar)
    {
        anterior = paux;
        paux = paux->sgte;
    }
    if ( paux!= lista)
    {
        anterior->sgte = new Nodo();
        anterior->sgte->info = ainsertar;
        anterior->sgte->sgte = paux;

    }
    else
    {
        lista= new Nodo();
        lista->sgte = paux;
        lista->info = ainsertar;
    }
    return;
}

void borrarLista(Nodo *&inicio)
{
    Nodo *paux;
    /***** borra de adelante hacia atras *****/
    while (inicio)
    {
        paux = inicio;
        if (paux->sgte != NULL)
        {
            inicio = inicio-> sgte;
            delete paux;
        }
        else
        {
            delete inicio;
            inicio = NULL;
        }
    }
    return;
}

void listar(Nodo *paux)
{
    while (paux)//Es equivalente a while (paux!=NULL)
    {
        cout << "Direccion del nodo: " << paux << endl;
        cout << "Info: " << paux->info << endl;
        cout << "Siguiente en: " << paux->sgte << endl;
        cout << "================" << endl;
        paux = paux->sgte;
    }
    return;
}
int main()
{
    Nodo *inicio = NULL;
    inicio= new Nodo();
    inicio->info=5;  //(*inicio).info= 5;
    inicio->sgte =NULL; //(*inicio).sgte = NULL;
    cout << "Cada nodo ocupa " << sizeof(Nodo) << "bytes" << endl;
    cout << "La info de inicio es:" << (*inicio).info << endl;
    inicio->sgte = new Nodo();
    inicio->sgte->info=27;//(*inicio->sgte).info = 27;
    inicio->sgte->sgte =NULL;
    /* CREAMOS UN TERCER NODO */
    Nodo *paux;
    paux= inicio->sgte;
    paux->sgte=new Nodo();
    paux = paux->sgte;
    paux->info= 32;
    paux->sgte=NULL;
    /*vamos a mostrar el contenido
    de la lista*/

    insertarOrdenado(inicio,50);
    insertarOrdenado(inicio,3);
    insertarOrdenado(inicio,4);
    insertarOrdenado(inicio,30);
    cout << "Lista toda la lista:" << endl;
    listar(inicio);
    getch();
    borrarLista(inicio);
    listar(inicio);
    getch();



    return 0;
}

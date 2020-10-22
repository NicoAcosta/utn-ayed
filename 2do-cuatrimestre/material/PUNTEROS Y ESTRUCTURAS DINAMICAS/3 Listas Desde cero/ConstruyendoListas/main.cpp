#include <iostream>
#include <conio.h>
using namespace std;

struct Nodo
{
    int info;
    Nodo *sgte;
};

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
    /*vamos a mostrar el contenido de la lista*/
    cout << "Lista toda la lista:" << endl;
    paux = inicio;

    while (paux)//Es equivalente a while (paux!=NULL)
    {
        cout << "Direccion del nodo: " << paux << endl;
        cout << "Info: " << paux->info << endl;
        cout << "Siguiente en: " << paux->sgte << endl;
        cout << "================" << endl;
        paux = paux->sgte;
    }
    /***** borra de atras hacia adelante *****/
    /*
    Nodo *anterior;
    while (inicio!=NULL)
    {
        anterior=NULL;
        paux= inicio;
        while (paux && paux->sgte)
		{
			anterior = paux;
			paux = paux ->sgte;
        }
        if (paux)
        {
            delete paux;
            if (anterior!=NULL)
                anterior->sgte=NULL;
            else
                inicio =NULL;
        }
    }
    */
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

    getch();
    return 0;
}

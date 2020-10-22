#include <iostream>
#include <conio.h>
#include "listasDE.h"

using namespace std;

int main()
{
    NodoListaDE *miLista=NULL;
    NodoListaDE *aux;
    ListaDEInsertarAlFinal(miLista, 8);
    ListaDEInsertarAlFinal(miLista, 10);
    ListaDEInsertarAlFinal(miLista, 16);
    ListaDEInsertarAlFinal(miLista, 5);
    ListaDEInsertarAlFinal(miLista, 7);
    ListaDEInsertarAlFinal(miLista, 19);
    ListaDEInsertarAlFinal(miLista, 1);
    ListaDEInsertarAlFinal(miLista, 2);
    aux= ListaDEBuscarNodo(miLista,7);
    if (aux) //si lo encontró inserta
        ListaDEInsertarSiguiente(aux,12);
    else
        cout << "Error: no encontró nodo con 7." << endl;
    aux = miLista;
    while (aux)
    {
        cout << "Info: " << aux->info << endl;
        aux= aux->sgte;
    }
    getch();
    return 0;
}

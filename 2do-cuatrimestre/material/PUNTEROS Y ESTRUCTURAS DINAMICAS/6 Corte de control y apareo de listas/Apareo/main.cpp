#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include "listasSE.h"

using namespace std;
/*Procedimiento que carga datos de prueba, hardcodeados,
para poder verificar el correcto funcionamiento del algoritmo */
void cargaDatosPrueba(NodoListaSE *&lista1, NodoListaSE *&lista2)
{


    InsertarAlFinal(lista1,10);
    InsertarAlFinal(lista1,20);
    InsertarAlFinal(lista1,50);
    InsertarAlFinal(lista1,74);
    InsertarAlFinal(lista1,79);
    InsertarAlFinal(lista1,82);

    InsertarAlFinal(lista2,6);
    InsertarAlFinal(lista2,76);
    InsertarAlFinal(lista2,77);
    return;
}



NodoListaSE* Apareo(NodoListaSE *auxLista1,NodoListaSE *auxLista2)
{
    NodoListaSE *nuevaLista= NULL;
    while (auxLista1 && auxLista2)
    {
        if (auxLista1->info < auxLista2->info)
        {
            InsertarAlFinal(nuevaLista, auxLista1->info);
            auxLista1= auxLista1->sgte;
        }
        else
        {
            InsertarAlFinal(nuevaLista, auxLista2->info);
            auxLista2= auxLista2->sgte;
        }
    }
    while (auxLista1)
    {
        InsertarAlFinal(nuevaLista, auxLista1->info);
        auxLista1= auxLista1->sgte;
    }
    while (auxLista2)
    {
        InsertarAlFinal(nuevaLista, auxLista2->info);
        auxLista2= auxLista2->sgte;
    }
    return nuevaLista;
}
int main()
{
    NodoListaSE *lista1 = NULL;
    NodoListaSE *lista2 = NULL;
    NodoListaSE *aux = NULL;
    cargaDatosPrueba(lista1, lista2);
    NodoListaSE *nuevaLista = Apareo(lista1,lista2);
    aux= nuevaLista;
    while (aux)
    {
        cout << aux->info << endl;
        aux = ObtenerSiguiente(aux);
    }
    borrarLista(lista1);
    borrarLista(lista2);
    borrarLista(nuevaLista);
    getch();
    return 0;
}

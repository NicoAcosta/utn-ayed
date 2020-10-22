#include <iostream>
#include <conio.h>
#include "pilas.h"
#include "colas.h"
#include "listasDE.h"

using namespace std;


int main()
{
    cout << "Ejemplo de  pilas, apilamos 1,2,3 y 4:" << endl;
    NodoPila *mipila=NULL;
    push(mipila,1);
    push(mipila,2);
    push(mipila,3);
    push(mipila,4);
    while(mipila)
    {
        cout << "Desapila un nodo:" << endl;
        cout << pop(mipila) << endl;
    }

    cout << "Ejemplo de colas, encolamos 10,11 y 12:" << endl;

    NodoCola *cola =NULL;
    cqueue(cola,10);
    cqueue(cola,11);
    cqueue(cola,12);
    while (cola)
    {
        cout << "Desacola un nodo:" << endl;
        cout << dequeue(cola)<< endl;
    }
    /* LISTAS DOBLEMENTE ENLAZADAS */
    cout << "Ejemplo de listasDE, agregamos tres numeros, 100, 200 y 300:" << endl;
    NodoListaDE *milistaDE=NULL;
    NodoListaDE *auxlista=NULL;
    ListaDEInsertarAlFinal(milistaDE,100);
    ListaDEInsertarAlFinal(milistaDE,200);
    ListaDEInsertarAlFinal(milistaDE,300);
    cout << "y los mostramos al reves para probar los punteros al anterior:" <<endl;
    auxlista = ListaDEObtenerUltimo(milistaDE);
    cout << auxlista->info << "<==>" << auxlista->ant->info << "<==>" << auxlista->ant->ant->info << endl;
    cout << "Ahora borramos el nodo del medio (el de 200)." <<endl;
    auxlista = ListaDEBuscarNodo(milistaDE,200);
    if (auxlista!= NULL)
    {
            ListaDEborrarNodo(milistaDE, auxlista);
            cout << "Nodo borrado exitosamente" << endl;
    }
    else
        cout << "No se encontro el nodo a borrar." << endl;

    cout << "Recorremos al derecho y al revés para verificar que los punteros quedaron ok:" << endl;
    cout << "Al derecho:" <<endl;
    cout << milistaDE->info << " <==> " << milistaDE->sgte->info << endl;
    cout << "Al reves:" <<endl;
    auxlista = ListaDEObtenerUltimo(milistaDE);
    cout << auxlista->info << " <==> " << auxlista->ant->info << endl;
    cout << "Agregamos un elemento entre el 100 y el 300" << endl;
    auxlista = ListaDEBuscarNodo(milistaDE,100);
    if (auxlista!= NULL)
    {
            ListaDEInsertarSiguiente(auxlista,467);
            cout << "Nodo agregado exitosamente" << endl;
    }
    cout << "Recorremos al derecho" << endl;
    auxlista = milistaDE;
    while(auxlista)
    {
        cout << auxlista->info << endl;
        auxlista = auxlista->sgte;
    }
    cout << "Recorremos al reves" << endl;
    auxlista = ListaDEObtenerUltimo(milistaDE);
    while(auxlista)
    {
        cout << auxlista->info << endl;
        auxlista = auxlista->ant;
    }
    ListaDEborrarLista(milistaDE);

    getch();
    return 0;
}

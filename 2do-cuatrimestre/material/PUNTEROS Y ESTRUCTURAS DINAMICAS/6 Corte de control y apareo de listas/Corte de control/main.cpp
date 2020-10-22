#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include "listasSE.h"

using namespace std;
/*Procedimiento que carga datos de prueba, hardcodeados,
para poder verificar el correcto funcionamiento del algoritmo */
void cargaDatosPrueba(NodoListaSE *&lista)
{
    FacturaItem aux;

    aux.nrofactura = 100;
    aux.nroitem = 432;
    aux.precio = 700;
    InsertarAlFinal(lista,aux);

    aux.nrofactura = 100;
    aux.nroitem = 198;
    aux.precio = 1200.5;
    InsertarAlFinal(lista,aux);

    aux.nrofactura = 101;
    aux.nroitem = 27;
    aux.precio = 340.75;
    InsertarAlFinal(lista,aux);

    aux.nrofactura = 102;
    aux.nroitem = 698;
    aux.precio = 120.15;
    InsertarAlFinal(lista,aux);

    aux.nrofactura = 102;
    aux.nroitem = 27;
    aux.precio = 340.75;
    InsertarAlFinal(lista,aux);

    aux.nrofactura = 102;
    aux.nroitem = 12;
    aux.precio = 563.20;
    InsertarAlFinal(lista,aux);
    return;
}


/*TotalPorFactura implementa el corte de control,
para poder utilizar este algoritmo la lista de facturas debe
estar previamente ordenada por el número de factura*/
void TotalPorFactura(NodoListaSE *listaFacturas)
{
    NodoListaSE *aux= listaFacturas;
    float suma;
    int anterior;
    while (aux)
    {
        suma=0;
        anterior= aux->info.nrofactura;
        while (aux && aux->info.nrofactura == anterior)
        {
            suma += aux->info.precio;
            aux = aux->sgte;
        }
        cout << "El total de la factura nro " << anterior << " es $" << suma << endl;
    }
    return;
}
int main()
{
    NodoListaSE *listaFacturas = NULL;
    cargaDatosPrueba(listaFacturas);
    TotalPorFactura(listaFacturas);
    getch();
    return 0;
}

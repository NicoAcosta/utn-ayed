#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Nodo {
    int info;
    Nodo *sgte;
};

Nodo *aux;


void crearyLLenarLista(Nodo *lista, int n) {

    aux = lista;
    aux->info = (2 * n) - 7;
    aux->sgte = NULL;
    
    aux->sgte = new Nodo();
    aux = aux->sgte;
    aux->info = (9 * n) - 7;
    aux->sgte = NULL;
    
    aux->sgte = new Nodo();
    aux = aux->sgte;
    aux->info = (n * 5) - 7;
    aux->sgte = NULL;
    
    aux->sgte = new Nodo();
    aux = aux->sgte;
    aux->info = (5 * n) - 7;
    aux->sgte = NULL;
    
    aux->sgte = new Nodo();
    aux = aux->sgte;
    aux->info = (1 * n) - 7;
    aux->sgte = NULL;
    
    aux->sgte = new Nodo();
    aux = aux->sgte;
    aux->info = (6 * n) - 7;
    aux->sgte = NULL;
}

int cantNodos(Nodo *lista) {
    int i = 0;
    Nodo *auxcant = new Nodo();
    auxcant = lista;
    while (auxcant) {
        i++;
        auxcant = auxcant->sgte;
    }
    return i;
}

void mostrarLista(Nodo *lista) {
    aux = lista;
    while (aux) {
        cout << aux->info << endl;
        aux = aux->sgte;
    }
    
    cout << endl;
}

Nodo *ultimo(Nodo *lista){
    aux = lista;
    while (aux && aux->sgte) {
        aux = aux->sgte;
    }
    return aux;
}

void insertarAlfinal(Nodo *lista, Nodo *nuevo){
    ultimo(lista)->sgte = nuevo;
    
}



int main() {
    Nodo *l1 = new Nodo();
    Nodo *l2 = new Nodo();
    Nodo *l3 = new Nodo();
    crearyLLenarLista(l1, 3);
    crearyLLenarLista(l2, 2);
    mostrarLista(l1);
    mostrarLista(l2);
    
    insertarAlfinal(l1, l2);
    mostrarLista(l1);
    
    
    
    
    
    
    
}

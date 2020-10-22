#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;



struct Nodo {
    int info;
    Nodo *sgte;
};

Nodo *aux, *aux2;


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

void insertarAlfinal(Nodo *lista, int nuevo){
    Nodo *a;
    a = ultimo(lista);
    a->sgte = new Nodo();
    a->sgte->info = nuevo;
    a ->sgte->sgte = NULL;
    
}

void intercalaryo(Nodo *f, Nodo*g, Nodo *h) {
    Nodo *ff = f;
    Nodo *gg = g;
    Nodo *hh = h;
    
    h = f;
    while (ff && gg) {
        
        hh = ff;
        ff = ff->sgte;
        hh->sgte = gg;
        gg = gg->sgte;
        hh->sgte->sgte = ff;
        
    }
    
}

void intercalar(Nodo *f, Nodo*g, Nodo *h) {
    while (f) {
        insertarAlfinal(h, f->info);
        if (g) {
            insertarAlfinal(h, g->info);
            g = g->sgte;
        }
        f = f->sgte;
    }
    while (g) {
        insertarAlfinal(h, g->info);
        g = g->sgte;
    }
    return;
}

void ordenar(Nodo *lista) {
    int num;
    for (int i = 0; i < cantNodos(lista); i++) {
        aux = lista;
        while(aux && aux->sgte) {
            if (aux->info > aux->sgte->info){
                num = aux->info;
                aux->info = aux->sgte->info;
                aux->sgte->info = num;
            }
            aux = aux->sgte;
        }
    }
}



int main() {
    Nodo *l1 = new Nodo();
    Nodo *l2 = new Nodo();
    Nodo *l3 = new Nodo();
    crearyLLenarLista(l1, 3);
    crearyLLenarLista(l2, 2);
    mostrarLista(l1);
    mostrarLista(l2);
    
    intercalar(l1, l2, l3);
    mostrarLista(l3);
    
    ordenar(l3);
    mostrarLista(l3);
    
    
    
    
    
    
    
}




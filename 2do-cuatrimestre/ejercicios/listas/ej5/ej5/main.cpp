#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct alumno {
    char inicial;
    int dni;
};
typedef alumno tipo;


struct Nodo {
    alumno info;
    Nodo *sgte;
};

int cantDatos(FILE *f) {
    fseek(f, 0, SEEK_END);
    return ftell(f)/sizeof(tipo);
}

bool Fin(FILE *f) {
    long actual = ftell(f);
    fseek(f, 0, SEEK_END);
    long fin = ftell(f);
    fseek(f, actual, SEEK_SET)
    if (actual == fin)
        return true;
    else
        return false;
        
}


int main() {
    Nodo *listaAl = new Nodo();
    listaAl->sgte = NULL;
    tipo aux;
    FILE *f;
    Nodo *ll = listaAl;
    
    if (f = fopen("alumnos.f", "rb+")) {
        while (!Fin(f)) {
            fread(&aux, sizeof(tipo), 1, f);
            Nodo* nuevo = new Nodo();
            nuevo->info = aux;
            
            if(ll){
                nuevo->sgte = ll->sgte;
                ll->sgte = nuevo;
            } else {
                nuevo->sgte = ll;
                ll = nuevo;
            }
            
            
            
            
            
            
            
            
        }
        
        
        
        
        
        
        
    } else {
        cout << "No se pudo abrir" << endl;
    }
    
    
    
    
    
}

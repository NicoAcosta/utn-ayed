#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef int tipo;
tipo aux;

void retroceder(FILE *file, int cant) {
    fseek(file, sizeof(tipo)*(-cant), SEEK_CUR);
}

void avanzar(FILE *file, int cant) {
    fseek(file, sizeof(tipo)*(cant), SEEK_CUR);
}

void irPrincipio(FILE* file){
    fseek(file, 0, SEEK_SET);
}

void irFin(FILE *file){
    fseek(file, 0, SEEK_END);
}

int posActual(FILE *file) {
    return ftell(file)/sizeof(tipo);
}

int cantDatos(FILE *file) {
    int pos = ftell(file);
    
    irFin(file);
    int cantDatos = ftell(file)/sizeof(tipo);
    
    fseek(file, pos, SEEK_SET);
    
    return cantDatos;
}

bool Final(FILE *file){
    if (posActual(file) < cantDatos(file))
        return false;
    else
        return true;
}

bool Principio(FILE *file){
    if (posActual(file))
        return false;
    else
        return true;
}

void leer(FILE *file) {
    fread(&aux, sizeof(tipo), 1, file);
}

void escribir(FILE *file) {
    fwrite(&aux, sizeof(tipo), 1, file);
}

void leerA(FILE *file, tipo &auxleer) {
    fread(&auxleer, sizeof(tipo), 1, file);
}

void escribirDesde(FILE *file, tipo &auxescribir) {
    fwrite(&auxescribir, sizeof(tipo), 1, file);
}


void apareo(FILE *f, FILE *g, FILE *h){
    tipo auxf, auxg;
    
    irPrincipio(f);
    irPrincipio(g);
    irPrincipio(h);
    
    while(!Final(f) && !Final(g)) {
        leerA(f, auxf);
        leerA(g, auxg);
        retroceder(f, 1);
        retroceder(g, 1);
        if (auxf < auxg) {
            leer(f);
            escribir(h);
        } else {
            leer(g);
            escribir(h);
        }
    }
    
    if (!Final(f)) {
        while (!Final(f)) {
            leer(f);
            escribir(h);
        }
    } else {
        while (!Final(g)) {
            leer(g);
            escribir(h);
        }
    }

}


void apareoInverso(FILE *f, FILE *g, FILE *h){
    tipo auxf, auxg;
    char uc;
    
    irFin(f);
    irFin(g);
    irPrincipio(h);
    
    while(!Principio(f) && !Principio(g)) {
        retroceder(f, 1);
        retroceder(g, 1);
        leerA(f, auxf);
        leerA(g, auxg);
        
        
        
        if (auxf > auxg) {
            escribirDesde(h, auxf);
            retroceder(f, 1);
            uc = 'f';
            
        } else {
            escribirDesde(h, auxg);
            retroceder(g, 1);
            uc = 'g';
        }
    }
    
//    if (Principio(f) && Principio(g)) {
//        if (uc == 'g')
//            escribirDesde(h, auxf);
//        else
//            escribirDesde(h, auxg);
//    }
    
    if (!Principio(f)) {
            while (!Principio(f)) {
                retroceder(f, 1);
                leer(f);
                escribir(h);
                retroceder(f, 1);
            }
        } else {
            while (!Final(g)) {
                retroceder(g, 1);
                leer(g);
                escribir(h);
                retroceder(g, 1);
            }
        }
}




void cargarDatos(FILE *f, FILE *g) {
    if (f) {
        for (tipo i = 0; i < 10; i = i+2) {
            escribirDesde(f, i);
        }
        cout << "f cargado" << endl;
    } else
        cout << "Error cargando f" << endl;

    if (g) {
        for (int i = 1; i < 19; i= i+2) {
            escribirDesde(g, i);
        }
        cout << "g cargado" << endl;
    } else
        cout << "Error cargando g" << endl;
}


void mostrarArchivo (FILE *file, char nombre) {
    cout << endl << "ARCHIVO " << nombre << ":" << endl;
    
    irPrincipio(file);
    while (!Final(file)) {
        leer(file);
        cout << aux << endl;
    }
    cout << endl << endl << endl;
}








int main() {
    FILE *f;
    FILE *g;
    FILE *h;
    
    f = fopen("f.file", "wb");
    g = fopen("g.file", "wb");
    cargarDatos(f, g);
    fclose(f);
    fclose(g);
    
    f = fopen("f.file", "rb");
    g = fopen("g.file", "rb");
    mostrarArchivo(f, 'f');
    mostrarArchivo(g, 'g');
    fclose(f);
    fclose(g);
    
//    f = fopen("f.file", "rb");
//    g = fopen("g.file", "rb");
//    h = fopen("h.file", "wb");
//    apareo(f, g, h);
//    fclose(f);
//    fclose(g);
//    fclose(h);
//
//    h = fopen("h.file", "rb");
//    mostrarArchivo(h, 'h');
//    fclose(h);
    
    f = fopen("f.file", "rb");
    g = fopen("g.file", "rb");
    h = fopen("h.file", "wb");
    apareoInverso(f, g, h);
    fclose(f);
    fclose(g);
    fclose(h);
    
    h = fopen("h.file", "rb");
    mostrarArchivo(h, 'h');
    fclose(h);
    

}

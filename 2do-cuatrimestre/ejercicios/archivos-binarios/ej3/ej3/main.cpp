#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
const char fd[] = "f.file";
const char gd[] = "g.file";
const char hd[] = "h.file";

void cargarDatos(FILE *f, FILE *g) {
    
    f = fopen(fd, "wb");
    if (f) {
        for (int i = 0; i < 5; i++) {
            fwrite(&i, sizeof(int), 1, f);
        }
        cout << "f cargado" << endl;
    } else
        cout << "Error cargando f" << endl;
    fclose(f);
    
    g = fopen(gd, "wb");
    if (g) {
        for (int i = 10; i < 11; i++) {
            fwrite(&i, sizeof(int), 1, g);
        }
        cout << "g cargado" << endl;
    } else
        cout << "Error cargando g" << endl;
    fclose(g);
}



int cantDatos(FILE *file) {
    if (file) {
        fseek(file, 0, SEEK_END);
        int cant = (ftell(file)/sizeof(int));
        return cant;
    } else
        cout << "Error leyendo file" << endl;
    
    return 2048;
}

void mostrarArchivo (FILE *file) {
    int aux;

    cout << endl << "Valores: " << endl;

    fseek(file, 0, SEEK_SET);
    while (!feof(file)) {
        fread(&aux, sizeof(int), 1, file);
        cout << aux << endl;
    }
    cout << endl << endl << endl;
}


void combinar(FILE *f, FILE *g, FILE *h) {
    int aux;
    fseek(f, 0, SEEK_SET);
    fseek(g, 0, SEEK_SET);
    fseek(h, 0, SEEK_SET);
    
    while ((!feof(f)) && (!feof(g))) {
        fread(&aux, sizeof(int), 1, f);
        fwrite(&aux, sizeof(int), 1, h);
        fread(&aux, sizeof(int), 1, g);
        fwrite(&aux, sizeof(int), 1, h);
    }
}



int main() {
    
    FILE *f;
    FILE *g;
    FILE *h;
    int aux;
    
    cargarDatos(f, g);
    
    f = fopen(fd, "rb");
    g = fopen(gd, "rb");
    
    h = fopen(hd, "wb+");
    
    if (f && g && h) {
        
        cout << "OK" << endl;
        
        cout << "Tam f: " << cantDatos(f) << endl;
        mostrarArchivo(f);
        cout << "Tam g: " << cantDatos(g) << endl;
        mostrarArchivo(g);
        cout << "Tam h: " << cantDatos(h) << endl;
        
        combinar(f, g, h);
        
        cout << endl << endl << "Tam h: " << cantDatos(h) << endl;
        mostrarArchivo(h);
        
        
        fclose(f);
        fclose(g);
        fclose(h);
        
    } else {
        cout << "Error al abrir los archivos" << endl;
    }
    
    
}

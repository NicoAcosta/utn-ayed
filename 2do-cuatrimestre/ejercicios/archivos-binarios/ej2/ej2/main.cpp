#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void mostrarArchivo (FILE *f, int nVal) {
    float aux;
    
    cout << endl << "Valores ingresados: " << endl << endl;
    
    fseek(f, 0, SEEK_SET);
    for (int i = 1; i <= nVal; i++) {
        fread(&aux, sizeof(float), 1, f);
        cout << "Valor nº " << i << ": " << aux << endl;
    }
    cout << endl << endl << endl;
}

void escribirNValores (FILE *f, int &nVal) {
    float aux;
    
    cout << "Ingrese cantidad de valores: " << endl;
    cin >> nVal;
    
    for (int i = 1; i <= nVal; i++) {
        cout << endl << endl << "Ingrese valor nº " << i << ": " << endl ;
        cin >> aux;
        fwrite(&aux, sizeof(float), 1, f);
    }
}

void cambiarValor(FILE *f) {
    int nval;
    float aux;
    
    cout << "Nº de valor a cambiar: ";
    cin >> nval;
    cout << endl << "Nuevo valor: ";
    cin >> aux;
    
    fseek(f, sizeof(float)*(nval-1), SEEK_SET);
    fwrite(&aux, sizeof(float), 1, f);
}



int main() {
    
    FILE *f;
    int nVal;
    
    f = fopen("archivo2.jaja", "wb+");
    
    if (f) {
        
        escribirNValores(f, nVal);
        
        mostrarArchivo(f, nVal);
        
        cambiarValor(f);
        
        mostrarArchivo(f, nVal);
        
        fclose(f);
        
        
    } else
        cout << "Error al abrir el archivo." << endl;
    
    return 0;
}

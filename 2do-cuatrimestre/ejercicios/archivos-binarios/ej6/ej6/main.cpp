#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
using namespace std;

FILE *f;
const char dir[] = "f.file";



struct alumno {
    char nombre[20];
    char apellido[20];
    int legajo;
    int DNI;
    int fnac;
};

typedef alumno tipo;
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

void leeryMostrarAlumno (FILE *file) {
        leer(file);
        cout << "Nombre: " << aux.nombre << endl <<
                "Apellido: " << aux.apellido << endl <<
                "Legajo: " << aux.legajo << endl <<
                "DNI: " << aux.DNI << endl <<
                "Fecha de nac: " << aux.fnac << endl << endl << endl;
}

void mostrarAlumnoAux () {
        cout << "Nombre: " << aux.nombre << endl <<
                "Apellido: " << aux.apellido << endl <<
                "Legajo: " << aux.legajo << endl <<
                "DNI: " << aux.DNI << endl <<
                "Fecha de nac: " << aux.fnac << endl << endl << endl;
}

void mostrarArchivo (FILE *file) {
    cout << "---------------------------" << endl << endl << "ARCHIVO:" << endl << endl;
    
    irPrincipio(file);
    int i = 1;
    
    while (!Final(file)) {
        cout << "Alumno Nº " << i << ":" << endl;
        leeryMostrarAlumno(f);
        i++;
    }
    cout << "---------------------------" << endl << endl;
}

int cant () {
    int cantAl;
    cout << "Cantidad de alumnos a ingresar: ";
    cin >> cantAl;
    cout << endl << endl;
    return cantAl;
}

void ingresarAlumno() {
    cout << "Nombre: ";
    cin >> aux.nombre;
    cout << "Apellido: ";
    cin >> aux.apellido;
    cout << "Legajo: ";
    cin >> aux.legajo;
    cout << "DNI: ";
    cin >> aux.DNI;
    cout << "Fecha de nacimiento: ";
    cin >> aux.fnac;
}

void ingresarNAlumnosA(int cantAl, FILE *file) {
    for (int i = 1; i <= cantAl; i++) {
        cout << "Alumno Nº " << i << ":" << endl;
        ingresarAlumno();
        escribir(file);
        cout << endl << endl;
    }
}

int menu() {
    cout << "---------- MENU ----------" << endl << endl <<
    "1) Agregar alumnos" << endl <<
    "2) Mostrar todos" << endl <<
    "3) Buscar por legajo" << endl <<
    "4) Buscar por DNI" << endl <<
    "5) Ordenar por legajo" << endl <<
    "6) Ordenar por DNI" << endl <<
    "9) Salir" << endl << endl;
    int op;
    cin >> op;
    return op;
}

void buscarXDNI(){
    int dnib;
    f = fopen(dir, "rb");
    
    cout << "DNI: ";
    cin >> dnib;
    
    while (!Final(f)) {
        leer(f);
        if (aux.DNI == dnib) {
            mostrarAlumnoAux();
            return;
        }
    }
    cout << "No se encontró" << endl << endl;
    return;
}

void buscarXLegajo(){
    int legajob;
    f = fopen(dir, "rb");
    
    cout << "DNI: ";
    cin >> legajob;
    
    while (!Final(f)) {
        leer(f);
        if (aux.legajo == legajob) {
            mostrarAlumnoAux();
            return;
        }
    }
    cout << "No se encontró" << endl << endl;
    return;
}

void ordenarXLegajo(){
    alumno aux1, aux2;
    
    for (int i = 0; i < cantDatos(f); i++) {
        while (!Final(f)) {
            retroceder(f, 1);
            leerA(f, aux1);
            leerA(f, aux2);
            if (aux1.legajo > aux2.legajo) {
                retroceder(f, 2);
                escribirDesde(f, aux2);
                escribirDesde(f, aux1);
            }
        }
        irPrincipio(f);
    }
}

void ordenarXDNI(){
    alumno aux1, aux2;
    
    for (int i = 0; i < cantDatos(f); i++) {
        while (!Final(f)) {
            retroceder(f, 1);
            leerA(f, aux1);
            leerA(f, aux2);
            if (aux1.DNI > aux2.DNI) {
                retroceder(f, 2);
                escribirDesde(f, aux2);
                escribirDesde(f, aux1);
            }
        }
        irPrincipio(f);
    }
}


int main() {
    
    int op;
    
    
    while (1 == 1) {
        
        op = menu();
        cout << endl << endl;
        
        switch (op) {
            case 1:
                f = fopen(dir, "wb");
                ingresarNAlumnosA(cant(), f);
                fclose(f);
                break;
            case 2:
                f = fopen(dir, "rb");
                mostrarArchivo(f);
                fclose(f);
                break;
            case 3:
                f = fopen(dir, "rb");
                buscarXLegajo();
                fclose(f);
                break;
            case 4:
                f = fopen(dir, "rb");
                buscarXDNI();
                fclose(f);
                break;
            case 5:
                f = fopen(dir, "rb+");
                ordenarXLegajo();
                fclose(f);
            case 6:
                f = fopen(dir, "rb+");
                ordenarXDNI();
                fclose(f);
            case 9:
                return 0;
            default:
                break;
        }
        
    }
    

    
    return 0;
    
    
    
    
    
    
    
}

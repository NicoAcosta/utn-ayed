
#include <iostream>
using namespace std;

struct alumno {
    char apellido[20];
    char tipoDoc[10];
    int nDoc;
    int nLegago;
    float nota;
};


void detAlumnos(int &nAl){
    cout << "Ingrese cantidad de alumnos: " << endl;
    cin >> nAl;
    cout << endl;
    return;
}


void llenarAlumnos (alumno reg[], int nAl) {
    for (int i = 0; i < nAl; i++){
        cout << "Apellido Nombre: ";
        cin >> reg[i].apellido;
        cout << "Tippo Doc: ";
        cin >> reg[i].tipoDoc;
        cout << "N Doc: ";
        cin >> reg[i].nDoc;
        cout << "N Legajo: ";
        cin >> reg[i].nLegago;
        cout << "Nota: ";
        cin >> reg[i].nota;
        cout << endl << endl;
    }
}

void mostrarAlumnos (alumno reg[], int nAl) {
    for (int i=0; i<nAl; i++) {
        cout << "Apellido Nombre: ";
        cout << reg[i].apellido << endl;
        cout << "Tippo Doc: ";
        cout << reg[i].tipoDoc << endl;
        cout << "N Doc: ";
        cout << reg[i].nDoc << endl;
        cout << "N Legajo: ";
        cout << reg[i].nLegago << endl;
        cout << "Nota: ";
        cout << reg[i].nota << endl;
        cout << endl << endl;
    }
}

void mostrarUno (alumno reg[], int nAl, int i) {
    cout << "Apellido Nombre: ";
    cout << reg[i].apellido << endl;
    cout << "Tippo Doc: ";
    cout << reg[i].tipoDoc << endl;
    cout << "N Doc: ";
    cout << reg[i].nDoc << endl;
    cout << "N Legajo: ";
    cout << reg[i].nLegago << endl;
    cout << "Nota: ";
    cout << reg[i].nota << endl;
    cout << endl << endl;
}

float promedio(alumno reg[], int nAl) {
    int suma = 0;
    for (int i = 0; i < nAl; i ++)
        suma += reg[i].nota;
    return (suma / nAl);
}

void may7(alumno reg[], int nAl) {
    for (int i = 0; i < nAl; i++){
        if (reg[i].nota > 7){
            cout << "Apellido Nombre: ";
            cout << reg[i].apellido << endl;
            cout << "Tippo Doc: ";
            cout << reg[i].tipoDoc << endl;
            cout << "N Doc: ";
            cout << reg[i].nDoc << endl;
            cout << "N Legajo: ";
            cout << reg[i].nLegago << endl;
            cout << "Nota: ";
            cout << reg[i].nota << endl;
            cout << endl << endl;
        }
    }
}

void ordenarPorNota(alumno reg[], int nAl) {
    for (int i = 0; i<nAl; i++){
        for (int j = 0; j< nAl-1; j++){
            if (reg[j].nota > reg[j+1].nota) {
                alumno aux = reg[j+1];
                reg[j+1] = reg[j];
                reg[j] = aux;
            }
        }
    }
}


int main() {
    
    int nAl;
    detAlumnos(nAl);
    
    alumno reg[nAl];
    llenarAlumnos(reg, nAl);
    
    cout << "----------- MOSTRAR ALUMNOS -----------" << endl;
    mostrarAlumnos(reg, nAl);
    cout << "---------------------------------------" << endl << "---------------------------------------" << endl << endl << endl;
    
    
    cout << "----------- MOSTRAR PROMEDIO -----------" << endl << endl;
    cout << "Promedio: " << promedio(reg, nAl) << endl << endl;
    cout << "---------------------------------------" << endl<< "---------------------------------------" << endl  << endl << endl;
    
    
    cout << "----------- MOSTRAR MAYORES A 7 -----------" << endl;
    may7(reg, nAl);
    cout << "---------------------------------------" << endl<< "---------------------------------------" << endl  << endl << endl;
    
    
    cout << "----------- MOSTRAR ORDENADOS -----------" << endl;
    ordenarPorNota(reg, nAl);
    mostrarAlumnos(reg, nAl);
    cout << "---------------------------------------" << endl<< "---------------------------------------" << endl  << endl << endl;
    
    
    cout << "----------- MOSTRAR PEOR -----------" << endl << endl;
    mostrarUno(reg, nAl, 0);
    cout << "---------------------------------------" << endl << "---------------------------------------" << endl << endl;
    
    
    return 0;
}

//
//  main.cpp
//  ej5
//
//  Created by Nico on 27/10/2019.
//  Copyright © 2019 Nicolás Acosta. All rights reserved.
//

#include <iostream>
using namespace std;

void detTam(int &tam){
    cout << "Ingrese cantidad de valores por vector: " << endl;
    cin >> tam;
    cout << endl;
    return;
}

void ops(int tam, int vec1[], int vec2[], int vecSuma[], int vecProd[], int vecPV[]) {
    for (int i = 0; i < tam; i++) {
        vecSuma[i] = vec1[i] + vec2[i];
        vecProd[i] = vec1[i] * vec2[i];
        vecPV[0] += vec1[i] * vec2[i];
    }
    return;
}

void mostrar(int vec[], int tam) {
    for (int i = 0; i < tam; i++){
        cout << vec[i] << " ";
    }
    cout << endl << endl;
    return;
}


void leerVector(int vec[], int tam) {
    for (int i = 0; i < tam; i++){
        cin >> vec[i];
    }
    return;
}

int main() {
    int tam;
    detTam(tam);
    
    int vec1[tam], vec2[tam];
    
    cout << "Ingrese valores de vec1: " << endl;
    leerVector(vec1, tam);
    
    cout << "Ingrese valores de vec2: " << endl;
    leerVector(vec2, tam);
    
    int vecSuma[tam];
    int vecProd[tam];
    int vecPV[0];
    vecPV[0] = 0;
    
    ops(tam, vec1, vec2, vecSuma, vecProd, vecPV);
    
    mostrar(vec1, tam);
    mostrar(vec2, tam);
    mostrar(vecSuma, tam);
    mostrar(vecProd, tam);
    mostrar(vecPV, 1);

    
    return 0;
}

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


void ordenar(int vec[], int tam) {
    int men;
    
    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam-1; j++){
            if (vec[j] < vec[j+1]) {
                men = vec[j];
                vec[j] = vec[j+1];
                vec [j+1] = men;
            }
        }
    }
}


void aparear(int vec1[], int vec2[], int ap[], int tam1, int tam2) {
    
    int i=0, j=0, k=0;
    int tam = tam1+tam2;
    
    while (i<tam1 && j<tam2) {
        if (vec1[i] < vec2[j]){
            ap[k] = vec1[i];
            i++;
        } else {
            ap[k] = vec2[j];
            j++;
        }
        k++;
    }
    if (i < tam1) {
        for (int l = i; i < tam1; l++) {
            ap[k] = vec1[l];
            k++;
        }
    } else {
        for (int l = j; l < tam2; l++) {
            ap[k] = vec2[l];
            k++;
        }
    }
    
}


int main() {
    
    
    int tam1, tam2;
    
    detTam(tam1);
    int vec1[tam1];
    cout << "Ingrese valores de vec1: " << endl;
    leerVector(vec1, tam1);
    
    detTam(tam2);
    int vec2[tam2];
    cout << "Ingrese valores de vec2: " << endl;
    leerVector(vec2, tam2);
    
    /*
    
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
     
    */
    
    int ap[tam1+tam2];
    
    
    mostrar(vec1, tam1);
    
    mostrar(vec2, tam2);
    
    aparear(vec1, vec2, ap, tam1, tam2);
    
    mostrar(ap, tam1+tam2);
    
    return 0;
}


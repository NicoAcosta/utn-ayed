
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


void detNReg(int &nReg){
    cout << "Ingrese cantidad de registros: " << endl;
    cin >> nReg;
    cout << endl;
    return;
}

void llenarAgenda (char v[][4][30], int nReg) {
    for (int i = 0; i < nReg; i++){
        cout << "Apellido, Nombre: ";
        cin >> v[i][0];
        cout << "Dirección: ";
        cin >> v[i][1];
        cout << "Tel: ";
        cin >> v[i][2];
        cout << "CP: ";
        cin >> v[i][3];
        cout << endl << endl;
    }
    
}

void ordenar(int vec[][4][30], int nReg) {
    int men;
    for (int i = 0; i < nReg; i++){
        for (int j = 0; j < nReg-1; j++){
            if (atoi(vec[j][3]) < atoi(vec[j+1][3])) {
//                men = vec[j];
//                vec[j] = vec[j+1];
//                vec [j+1] = men;
            }
        }
    }
}


int main() {
    
    int nReg;
    detNReg(nReg);
    
    char agenda[nReg][4][30];
    llenarAgenda(agenda, nReg);
    
    int num = atoi(agenda[0][2]);
    
    return 0;
}



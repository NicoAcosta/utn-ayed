
#include <iostream>
using namespace std;

void ordenar(int vec[], int tam) {
    int men;
    
    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam-1; j++){
            if (vec[j] > vec[j+1]) {
                men = vec[j];
                vec[j] = vec[j+1];
                vec [j+1] = men;
            }
        }
    }
}


void mostrar(int vec[], int tam) {
    for (int i = 0; i < tam; i++){
        cout << vec[i] << " ";
    }
    cout << endl << endl;
    return;
}

int main() {
    
    int ar[4][3];
    int v[12];
    
    cout << "Ingresar 12 valores" << endl << endl;
    for (int i=0; i<4; i++) {
        for (int j=0; j<3; j++) {
            cin >> ar[i][j];
        }
    }
    cout << endl << endl;
    
    for (int i=0; i<4; i++) {
        for (int j=0; j<3; j++) {
            cout << ar[i][j] << "  ";
        }
    }
    
    cout << endl << endl;
    
    
    for (int i=0; i<4; i++) {
        for (int j=0; j<3; j++) {
            v[(3*i)+j] = ar[i][j];
        }
    }
    
    mostrar(v, 12);
    
    ordenar(v, 12);
    
    mostrar(v, 12);
    
    
    
    
    return 0;
}

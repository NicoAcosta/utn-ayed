//
//  main.cpp
//  ej4
//
//  Created by Nico on 27/10/2019.
//  Copyright © 2019 Nicolás Acosta. All rights reserved.
//

#include <iostream>
using namespace std;

void leerVector(int vec[5]) {
    cout << "Ingrese vector: " << endl;
    for (int i = 0; i<6; i++)
        cin >> vec[i];
    
    return;
}

void mostrarVector(int vec[5]) {
    cout << endl << endl;
    for (int i = 0; i<6; i++)
        cout << vec[i] << " ";
    
    return;
}

void reverse(int vec[5]) {
    cout << endl << endl;
    for (int i = 5; i>=0; i--)
        cout << vec[i] << " ";
    
    return;
}

int main() {
    
    int vec[5];
    
    leerVector(vec);
    mostrarVector(vec);
    reverse(vec);
    
    
    
    return 0;
}

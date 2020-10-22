//
//  main.cpp
//  Parcial T2
//
//  Created by Nico on 11/06/2019.
//  Copyright © 2019 Nicolás Acosta. All rights reserved.
//

#include <iostream>
using namespace std;


void mostrar (int v[], int tam) {
    int i;
    for (i=0; i<tam; i++) {
        if (v[i])
            cout << v[i] << endl;
        
    }
    
    return;
}

int main() {
    
    int v1[10] = {1, 3, 5};
    mostrar (v1, 10);
    
    
    
    return 0;
}

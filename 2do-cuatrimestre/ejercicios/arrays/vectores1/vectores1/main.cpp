//
//  main.cpp
//  vectores1
//
//  Created by Nico on 25/10/2019.
//  Copyright © 2019 Nicolás Acosta. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    
    cout << "Hello, World!\n";
    
    int numeros[9];
    
    for (int i = 0; i<10; i++) {
        cin >> numeros[i];
    }
    
    for (int i = 9; i>= 0; i--) {
        cout << numeros[i] << endl;
    }
    
    return 0;
}

//
//  main.cpp
//  33 MCD
//
//  Created by Nico on 12/06/2019.
//  Copyright © 2019 Nicolás Acosta. All rights reserved.
//

#include <iostream>
using namespace std;

int mcd(int a, int b) {
    int r;
    
    while (1 == 1) {
        
        r = a%b;
        
        if (!r) {
            return b;
        }
        
        a = b;
        b = r;
    }
    
    return 0;
}

int main() {
    
    int n1, n2;
    
    do {
        do {
            cout << "Ingrese dos números:" << endl << endl;
            cin >> n1 >> n2;
        } while (!n1 || !n2);
        
        
        cout << endl << "MCD de " << n1 << " y " << n2 << ": " << mcd(n1, n2) << "." << endl << endl;
    } while (1 == 1);
    
    
    
    return 9;
}

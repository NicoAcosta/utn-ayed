//
//  main.cpp
//  Menu
//
//  Created by Nico on 11/06/2019.
//  Copyright © 2019 Nicolás Acosta. All rights reserved.
//

#include <iostream>

using namespace std;

double factorial(int n) {
    
    if (n==0)
        return 1;
    return (n * factorial(n-1));
    
}

int mcd(int a, int b) {
    int r;
    do {
        r = a%b;
        if (r==0)
            return b;
        a = b;
        b = r;
    } while (b!=0);
    return 0;
}

int potencia(int b, int e) {
    int n = 1;
    for (int a = 0; a < e; a++) {
        n *= b;
    }
    return n;
}

int main() {
    
    char opcion;
    int x, y;
    
    do {
        cout << endl << "--------" << endl << endl << "Ingrese una opcion:" << endl << endl << "a - MCD" << endl << "b - Potencia" << endl << "c - factorial" << endl << "Esc - Salir" << endl << endl;
        
        do {
            opcion = getchar();
        } while (opcion != 'a' && opcion != 'b' && opcion != 'c' && opcion != 27);
        
        switch (opcion) {
            case 'a':
                cout << endl << "Ingrese dos números" << endl << endl;
                cin >> x >> y;
                cout << endl << mcd(x, y) << endl << endl;
                break;
            case 'b':
                cout << endl << "Ingrese dos números" << endl << endl;
                cin >> x >> y;
                cout << endl << potencia(x, y) << endl << endl;
                break;
            case 'c':
                cout << "Ingrese un número" << endl << endl;
                cin >> x;
                cout << endl << factorial(x) << endl << endl;
                break;
        }
    
    } while (opcion != 27);
    
    return 0;
}

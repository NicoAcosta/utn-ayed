//
//  main.cpp
//  41
//
//  Created by Nico on 11/06/2019.
//  Copyright © 2019 Nicolás Acosta. All rights reserved.
//

#include <iostream>
using namespace std;

int mcd(int a, int b) {
    int r;
    do {
        r = a%b;
        if (r == 0)
            return b;
        a = b;
        b = r;
    } while (b != 0);
    return 0;
}


int main() {
    
    int n1, n2;
    cout << "Ingrese la cantidad de cajas de vino blanco:" << endl;
    cin >> n1;
    cout << "Ingrese la cantidad de cajas de vino tinto:" << endl;
    cin >> n2;
    int mcdd = mcd(n1, n2);
    int f1 = n1 / mcdd;
    int f2 = n2 / mcdd;
    cout << endl << endl << "Cantidad de paquetes: " << mcdd << "." << endl << "Cajas de vino blanco por caja: " << f1 << endl << "Cajas de vino tinto por caja: " << f2 << endl << endl;
    
    
    
    return 0;
}

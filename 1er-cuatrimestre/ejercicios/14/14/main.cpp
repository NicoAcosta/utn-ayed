//
//  main.cpp
//  14
//
//  Created by Nico on 12/06/2019.
//  Copyright © 2019 Nicolás Acosta. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {

    int n, cantidadMayores = 0, cantidadMenores = 0, sumaMayores = 0, sumaMenores = 0;
    
    for (int i = 1; i < 9; i++) {
        cin >> n;
        if (n > 100) {
            cantidadMayores++;
            sumaMayores += n;
            
        } else if (n < -10) {
            cantidadMenores++;
            sumaMenores += n;
        }
    }
    
    cout    << endl << endl << "Promedio >100: " << (float) (sumaMayores / cantidadMayores)
            << endl << endl << "Promedio <50: " << (float) (sumaMenores / cantidadMenores) << endl << endl;
    
    return 0;
}

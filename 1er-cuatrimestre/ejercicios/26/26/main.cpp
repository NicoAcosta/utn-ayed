//
//  main.cpp
//  26
//
//  Created by Nico on 13/06/2019.
//  Copyright © 2019 Nicolás Acosta. All rights reserved.
//

#include <iostream>
using namespace std;



int main() {
    int peso, puerto, id, p1 = 0, p2 = 0, p3 = 0, max = -1, idmax, suma = 0;
    
    for (int i = 1; i < 6; i++) {
        
        cout << endl << "Ingrese identidficador del contendedor" << endl;
        cin >> id;
        cout << endl << "Ingrese peso del contendedor" << endl;
        cin >> peso;
        do {
            cout << endl << "Ingrese puerto de arribo" << endl;
            cin >> puerto;
        } while (puerto != 1 && puerto != 2 && puerto != 3);
        
        if (peso > max) {
            max = peso;
            idmax = id;
        }
        
        switch (puerto) {
            case 1:
                p1++;
                break;
            case 2:
                p2++;
                break;
            case 3:
                p3++;
                break;
        }
        
        suma += peso;
        
    }
    
    cout << endl << endl <<
    "Peso total: " << suma << endl << endl <<
    "Contenedor de mayor peso: " << idmax << " (" << max << ")" << endl << endl <<
    "Contenedores con puerto de arribo 1: " << p1 << endl <<
    "Contenedores con puerto de arribo 2: " << p2 << endl <<
    "Contenedores con puerto de arribo 3: " << p3 << endl << endl;
    
    
    return 0;
}

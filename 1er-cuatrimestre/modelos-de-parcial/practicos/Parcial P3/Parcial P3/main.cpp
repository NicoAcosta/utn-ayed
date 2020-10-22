//
//  main.cpp
//  Parcial P3
//
//  Created by Nico on 11/06/2019.
//  Copyright © 2019 Nicolás Acosta. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    
    int valor = 0;
    int posJuego = 0;
    int posGeneral = 1;
    int min = 0;
    int suma = 0;
    
    for (int i = 1; i < 6; i++) {
        
        cout << "Ingrese valores" << endl;
        cin >> valor;
        
        posJuego= 1;
        suma = 0;
        
        while (valor) {
            
            if (posGeneral == 1 || valor < min)
                min = valor;
            
            suma += valor;
            posJuego++;
            posGeneral++;
            
            cin >> valor;
            
        }
        
        cout << "Fin del juego." << endl <<
                "Promedio: " << (float) suma / (posJuego - 1) << endl << endl;
        
    }
    
    cout << "FIN" << endl <<
            "Menor: " << min << endl << endl;
    
    return 0;
}

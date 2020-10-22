//
//  main.cpp
//  24
//
//  Created by Nico on 12/06/2019.
//  Copyright © 2019 Nicolás Acosta. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    
    int n, nroLote = 0, posLote = 0, maximo = 0, minLote = 0, sumaLote = 0, loteMaximo = 0, posMaximo = 0;
    float promLote = 0;
    
    cin >> n;
    
    while (n >= 0) {
        
        nro Lote++;
        
        while (n > 0) {
            
            posLote++;
            
            if (posLote == 1 || n < minLote)
                minLote = n;
            
            if (n > maximo) {
                maximo = n;
                loteMaximo = nroLote;
                posMaximo = posLote;
            }
            
            sumaLote += n;
            
            cin >> n;
            
        }
        
        if (!n && !posLote) {
            
            cout << endl << endl << "Conjunto vacío." << endl << endl;
            
        } else {
            
            promLote = sumaLote / posLote;
            
            cout << endl << endl << "Fin del lote." << endl <<
            "Promedio: " << promLote << endl <<
            "Mínimo: " << minLote << endl << endl;
            
        }
        
        posLote = 0;
        sumaLote = 0;
        promLote = 0;
        
        if (n >= 0) {
            cin >> n;
        }
        
    }
    
    cout << endl << endl << "Fin del conjunto." << endl <<
                            "Cantidad de Sublotes: " << nroLote << endl <<
                            "Máximo: " << maximo << endl <<
                            "del Lote: " << loteMaximo << endl <<
                            "en la Posición: " << posMaximo << endl << endl;
    
    return 0;
}

//
//  main.cpp
//  50
//
//  Created by Nico on 11/06/2019.
//  Copyright © 2019 Nicolás Acosta. All rights reserved.
//

#include <iostream>
using namespace std;

void obtenerHorario() {
    
    char a, b, c, d;
    
    a = getchar();
    b = getchar();
    c = getchar();
    d = getchar();
    
    cout << endl << endl << "Hora: " << a << b << ":" << c << d << "." << endl;
}




int main() {
    
    float abono = 0, exc = 0, costoexc = 0, monto;
    int minlib, minut;
    
    cout << endl << "Ingresar Costo Abono:" << endl;
    cin >> abono;
    cout << endl << "Ingresar Minutos Libres:" << endl;
    cin >> minlib;
    cout << endl << "Ingresar Costo por Minuto Excedido:" << endl;
    cin >> exc;
    cout << endl << "Ingresar Minutos Utilizados:" << endl;
    cin >> minut;
    
    if ((minlib - minut) < 0) {
        costoexc = (minut - minlib) * exc;
    } else {
        costoexc = 0;
    }
    
    monto = (abono + costoexc) * 1.21;
    
    cout << "Abono: " << abono << "." << endl;
    
    if (costoexc > 0) {
        cout << "Costo de exceso: " << costoexc << "." << endl <<
                    (char) 9 << "Minutos excedidos: " << (minut - minlib) << "." << endl <<
                    (char) 9 << "Precio por minuto: " << exc << "." << endl;
    } else {
        cout << "No hubo exceso de minutos" << endl << endl;
    }
    cout << "Subtotal: " << (abono + costoexc) << endl <<
            "IVA: " << (abono + costoexc) * 0.21 << "." << endl <<
            "Total: " << monto;
    
    
    
    
    return 0;
}

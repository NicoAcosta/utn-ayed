//
//  main.cpp
//  Parcial P2
//
//  Created by Nico on 11/06/2019.
//  Copyright © 2019 Nicolás Acosta. All rights reserved.
//

#include <iostream>
using namespace std;

long fib(int n){
    if (n <= 1)
        return 1;
    return fib(n-1) + fib(n-2);
}


int main() {
    
    int x;
    
    while (1 == 1) {
    // insert code here...
    
        cout << endl << endl << "Ingrese un número" << endl << endl;
        cin >> x;
        if (x == 23)
            return 0;
        cout << "Fibonacci de " << x << ": " << fib(x) << "." << endl << endl;
        
        
    }
 
    return 0;
}

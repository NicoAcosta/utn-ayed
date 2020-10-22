//
//  main.cpp
//  Parcial T1
//
//  Created by Nico on 11/06/2019.
//  Copyright © 2019 Nicolás Acosta. All rights reserved.
//

#include <iostream>
using namespace std;

void inc3(int x) {
    x += 3;
    return;
}

void inc1(int &x) {
    x += 1;
    inc3(x);
    return;
}


int main() {
    // insert code here..
    int x = 6;
    inc1(x);
    cout << x << endl;
    
    
    
    
    return 0;
}

//
//  main.cpp
//  ej3
//
//  Created by Nico on 26/10/2019.
//  Copyright © 2019 Nicolás Acosta. All rights reserved.
//

#include <iostream>
using namespace std;

int largo(char word[20]) {
    
    int cant = 0;
    
    while (word[cant] != NULL) {
        cant++;
    }

    return cant;
    
}

void mostrar(char word[20]) {
    cout << word << endl;
    return;
}

void reverse(char word[20]) {
    for (int i = largo(word); i >= 0; i--){
        cout << word[i];
    }
    cout << endl << endl;
    return;
}




int main() {
    
    char word[20];
    
    cout << "Ingresar palabra: " << endl << endl;
    
    cin >> word;
    
    mostrar(word);
    
    reverse(word);
    
    return 0;
}

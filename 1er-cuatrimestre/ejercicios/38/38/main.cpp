//
//  main.cpp
//  38
//
//  Created by Nico on 12/06/2019.
//  Copyright © 2019 Nicolás Acosta. All rights reserved.
//

#include <iostream>
using namespace std;

int EdadAGrupoEtario (int edad) {
    
    if (edad <= 14) {
        return 1;
    } else if (edad <= 21) {
        return 2;
    } else if (edad <= 28) {
        return 3;
    } else if (edad <= 35) {
        return 4;
    } else if (edad <= 42) {
        return 5;
    } else if (edad <= 49) {
        return 6;
    } else if (edad <= 63) {
        return 7;
    } else if (edad > 63) {
        return 8;
    }
    
    return 0;
}

int main() {
    int ed;
    
    do {
        
        do {
            
            cout << "Ingrese un número" << endl << endl;
            cin >> ed;
            
        } while (ed < 0);
        
        
        cout << EdadAGrupoEtario(ed) << endl << endl <<
        "-------" << endl << endl;
        
    } while (ed != 456);
    
}




//#include <iostream>
//using namespace std;
//
//int EdadAGrupoEtario (int edad) {
//    switch (edad) {
//        case ;
//            return 10;
//        case 2:
//            return 20;
//        case 3:
//            return 30;
//
//    }
//    return 0;
//}
//
//int main() {
//    int ed;
//
//    do {
//
//        do {
//
//            cout << "Ingrese un número" << endl << endl;
//            cin >> ed;
//
//        } while (ed != 1 && ed != 2 && ed != 3 && ed != 0);
//
//        if (!ed) {
//
//            cout << endl << endl << "FIN" << endl << endl;
//
//            return 0;
//        }
//
//        cout << EdadAGrupoEtario(ed) << endl << endl <<
//                "-------" << endl << endl;
//
//    } while (ed != 0);
//
//}

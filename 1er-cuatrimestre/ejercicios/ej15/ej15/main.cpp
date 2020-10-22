#include <iostream>
using namespace std;

int main() {
    
    int tipo;
    char motivo[20];
    float valor;
    char gravedad;
    
    float sumaL=0, sumaM=0, sumaG=0;
    int clausura=0;
    
    for (int i = 0; i < 10; i ++) {
        
        cout << "Tipo: ";
        cin >> tipo;
//        cout << "Motivo: ";
//        cin >> motivo;
        cout << "Valor: ";
        cin >> valor;
        cout << "Gravedad: ";
        cin >> gravedad;
        cout << endl;
        
        switch (gravedad) {
            case 'L': sumaL+=valor;
                break;
            case 'M': sumaM+=valor;
                break;
            case 'G': sumaG+=valor;
                break;
        }
        
        if ((gravedad == 'G') && (tipo == 3 || tipo == 4))
            clausura++;
    }
    
    cout << "Suma L: " << sumaL << endl <<
    "Suma M: " << sumaM << endl <<
    "Suma G: " << sumaG << endl << endl;
    if (clausura>3)
        cout << "Clausurar fábrica" << endl << endl;
    
    return 0;
}

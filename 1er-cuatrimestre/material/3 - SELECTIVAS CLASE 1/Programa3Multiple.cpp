#include <iostream>

using namespace std;

/* Primer ejemplo de selectiva múltiple.
 Dado el ingreso de un nro. entre 0 y 9 por teclado,
 mostrarlo escrito en letras. Si el nro. no cumple
 lo solicitado, mostrar un mensaje de error. */

int main()
{
    int x;
    cout << "Ingrese un valor:" << endl;
    cin >> x;
    switch(x)
    {
        case 0:
            cout << "Cero." << endl;
            break;
        case 1:
            cout << "Uno." << endl;
            break;
        case 2:
            cout << "Dos." << endl;
           // break;
        case 3:
            cout << "Tres." << endl;
            break;
        case 4:
            cout << "Cuatro." << endl;
            break;
        case 5:
            cout << "Cinco." << endl;
            break;
        case 6:
            cout << "Seis." << endl;
            break;
        case 7:
            cout << "Siete." << endl;
            break;
        case 8:
            cout << "Ocho." << endl;
            break;
        case 9:
            cout << "Nueve." << endl;
            break;
        default:
            cout << "Error: valor inválido." << endl;
    }
    cout << "El programa ha finalizado." << endl;
    return 0;
}

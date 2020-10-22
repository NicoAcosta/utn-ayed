#include <iostream>

using namespace std;

/* Dado el ingreso de un caractér indicar si es
 vocal o no. EJEMPLO REALIZADO CON SELECTIVA SIMPLE.*/

int main()
{
    char c;
    cout << "Ingrese un caractér:" << endl;
    cin >> c;
    if ( (c == 'A') || (c == 'a') || (c == 'E') ||
        (c == 'e') || (c == 'I') || (c == 'i') ||
        (c == 'O') || (c == 'o') || (c == 'U') ||
        (c == 'u') )
    {
            cout << "Es vocal" << endl;
    }
    else
    {
            cout << "No es vocal" << endl;
    }
    cout << "El programa ha finalizado." << endl;
    return 0;
}

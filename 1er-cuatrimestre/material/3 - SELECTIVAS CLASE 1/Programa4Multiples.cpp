#include <iostream>

using namespace std;

/* Dado el ingreso de un caractér indicar si es
 vocal o no.*/

int main()
{
    char c;
    cout << "Ingrese un caractér:" << endl;
    cin >> c;
    switch(c)
    {
        //case 65: case 97:
        case 'A': case 'a':
        case 'E': case 'e':
        case 'I': case 'i':
        case 'O': case 'o':
        case 'U': case 'u':
            cout << c << " - ASCII: " << (int) c << " -  Es vocal" << endl;
            break;
        default:
            cout << c << " - ASCII: " << (int) c << " -  NO es vocal" << endl;
    }
    cout << "El programa ha finalizado." << endl;
    return 0;
}

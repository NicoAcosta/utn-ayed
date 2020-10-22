#include <iostream>

using namespace std;

//************ SOLUCION 2 ALTERNATIVA**********
int main()
{
    int x;
    cout << "Ingrese un valor:" << endl;
    cin >> x;
    if (x > 20)
    {
        cout << "El nro. ingresado es mayor a 20." << endl;
    }
    if (x <= 20)
    {
        cout << "El nro. ingresado no es mayor a 20." << endl;
    }
    cout << "El programa ha finalizado." << endl;
    return 0;
}

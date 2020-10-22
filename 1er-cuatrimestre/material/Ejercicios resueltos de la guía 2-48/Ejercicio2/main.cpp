#include <iostream>

using namespace std;

int main()
{
    int d,m,a,fecha;
    cout << "Ingrese día, mes y año:" << endl;
    cin >> d >> m >> a;
    fecha = a * 10000 + m * 100 + d;
    cout << "AAAAMMDD:" << fecha << endl;
    return 0;
}

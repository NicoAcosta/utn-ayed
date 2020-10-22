#include <iostream>

using namespace std;

int main()
{
    int d,m,a,fecha;
    cout << "Ingrese fecha en formato AAAAMMDD:" << endl;
    cin >> fecha;
    a = fecha / 10000;
    m = (fecha % 10000) / 100;
    d = fecha % 100;
    cout << "Año: " << a << " Mes: " << m << " Día: " << d << endl;
    return 0;
}

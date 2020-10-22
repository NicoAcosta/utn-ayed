#include <iostream>

using namespace std;

int main()
{
    int fecha1, fecha2;
    cout << "Ingrese dos fechas en formato AAAAMMDD:" << endl;
    cin >> fecha1 >> fecha2;
    if (fecha1 > fecha2)
    {
        cout << fecha1 << " es más reciente." << endl;
    }
    else
    {
        if (fecha1 == fecha2)
        {
            cout << "Las fechas son iguales." << endl;
        }
        else
        {
            cout << fecha2 << " es más reciente." << endl;
        }

    }
    return 0;
}

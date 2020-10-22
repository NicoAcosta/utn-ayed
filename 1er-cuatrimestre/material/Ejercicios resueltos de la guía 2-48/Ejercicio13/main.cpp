#include <iostream>

using namespace std;

int main()
{
    int m,n,i, suma=0;
    cout << "Ingrese los operandos de la multiplicacion" << endl;
    cin >> m >> n;
    for (i=1; i<=n; i++)
    {
        suma += m;
    }
    cout << m << " * " << n << " = " << suma << endl;
    return 0;
}

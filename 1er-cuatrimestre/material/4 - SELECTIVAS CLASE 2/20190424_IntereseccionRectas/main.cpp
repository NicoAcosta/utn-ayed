#include <iostream>

using namespace std;

int main()
{
    float m1,m2,b1,b2,xi,yi;
    cout << "Ingrese pendiente y ordenada de la recta 1:" << endl;
    cin >> m1 >> b1;
    cout << "Ingrese pendiente y ordenada de la recta 2:" << endl;
    cin >> m2 >> b2;
    if (m1 == m2)
    {
        if (b1==b2)
            cout << "La solucion es toda la recta Y = " << m1 << " X + " << b1 << endl;
        else
            cout << "No existe solucion, rectas paralelas" << endl;
    }
    else
    {
        xi = (b2-b1) / (m1-m2);
        yi = m1 * xi + b1;
        cout << "El punto de interseccion (xi;yi) = (" << xi << " ; " << yi << ")" << endl;
    }
    return 0;
}

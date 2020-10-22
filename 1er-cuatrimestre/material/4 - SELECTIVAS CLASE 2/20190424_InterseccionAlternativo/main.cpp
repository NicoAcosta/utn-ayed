#include <iostream>

using namespace std;

int main()
{
    float m1,m2,b1,b2,xi,yi;
    cout << "Ingrese pendiente y ordenada de la recta 1:" << endl;
    cin >> m1 >> b1;
    cout << "Ingrese pendiente y ordenada de la recta 2:" << endl;
    cin >> m2 >> b2;
    /* cuando un bloque tiene una unica linea,
    las llaves son optativas, como el los siguientes
    dos ifs */
    if (m1 == m2 && b1 == b2)
        cout << "La solucion es toda la recta Y = " << m1 << " X + " << b1 << endl;
    if (m1 == m2 && b1 != b2)
        cout << "No existe solucion, rectas paralelas" << endl;
    if (m1 != m2)
    {
        xi = (b2-b1) / (m1-m2);
        yi = m1 * xi + b1;
        cout << "El punto de interseccion (xi;yi) = (" << xi << " ; " << yi << ")" << endl;
    }
    return 0;
}

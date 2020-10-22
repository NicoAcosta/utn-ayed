#include <iostream>

using namespace std;

int main()
{
    int y = 20;
    int z;
    bool x;
    /* Para el lenguaje, las expresiones de tipo lógico se evalúan
    como un entero. El valor 0 (cero) es falso, 1 es verdadero,
    aunque, cualquier valor distinto de cero es verdadero */
    x = (y<=10) && (y==20);
    z = (y<=10) || (y==20);
    cout << "x = " << x << "  | z = " << z << endl;

    if (y==10)
    {
        cout << "La expresion es verdadera." << endl;
    }
    else
    {
        cout << "La expresion es falsa." << endl;
    }
    cout << "Al salir y=" << y << endl;
    return 0;
}

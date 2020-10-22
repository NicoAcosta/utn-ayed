#include <iostream>

using namespace std;

int main()
{
    bool x;
    int y,z;
    cout << "Ingrese valores de y y z:" << endl;
    cin >> y >> z;
    x =  y > z;
    cout << "Valor de la expresion logca: " << x << endl;
    //if (x == true)
    if (x)
        cout << "X es verdadera." << endl;
    else
        cout << "X es falsa." << endl;
    return 0;
}


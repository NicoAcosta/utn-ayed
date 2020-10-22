#include <iostream>

using namespace std;

int main()
{
    /*
    Este programa es un ejemplo
    hecho en clase  y es INCORRECTO,
    ya que se realiza la conversión
    sin haber leído un valor para f
    */
    float f, c;
    c = (f-32) * 5/9;
    cout << "La fórmula devuelve: " << c << endl;
    cin >> c;
    cout <<c;
    //cout << "Hello world!" << endl;
    return 0;
}

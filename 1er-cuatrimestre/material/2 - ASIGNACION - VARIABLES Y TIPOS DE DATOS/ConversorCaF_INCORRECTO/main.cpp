#include <iostream>

using namespace std;

int main()
{
    /*
    Este programa es un ejemplo
    hecho en clase  y es INCORRECTO,
    ya que se realiza la conversi�n
    sin haber le�do un valor para f
    */
    float f, c;
    c = (f-32) * 5/9;
    cout << "La f�rmula devuelve: " << c << endl;
    cin >> c;
    cout <<c;
    //cout << "Hello world!" << endl;
    return 0;
}

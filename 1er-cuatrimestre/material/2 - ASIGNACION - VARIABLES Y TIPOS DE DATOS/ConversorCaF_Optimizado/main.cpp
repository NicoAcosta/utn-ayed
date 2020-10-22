#include <iostream>

using namespace std;

int main()
{
    float f;
    cout << "Ingrese una temp. en °F:" << endl;
    cin >> f;
    cout << f << " °F= " << (f-32) *5/9 << "°C" << endl;
    return 0;
}

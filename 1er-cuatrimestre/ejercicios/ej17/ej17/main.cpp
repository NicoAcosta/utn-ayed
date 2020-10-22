#include <iostream>
using namespace std;

int main() {
    float n, men1520=0, men2780=0, men5999=0, mas=0;
    cout << "ingrese sueldos" << endl << endl;
    cin >> n;
    while (n > 0) {
        if (n < 1520)
            men1520++;
        else if (n < 2780)
            men2780++;
        else if (n < 5999)
            men5999++;
        else
            mas++;
        cin >> n;
    }
    cout << endl << endl <<
    "Menos de 1520: " << men1520 << endl <<
    "Menos de 2780: " << men2780 << endl <<
    "Menos de 5999: " << men5999 << endl <<
    "5999 o más: " << mas << endl;
}

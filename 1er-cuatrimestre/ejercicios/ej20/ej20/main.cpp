#include <iostream>
using namespace std;

int main() {
    
    int n, num, posmay, may;
    
    cout << "Valores: ";
    cin >> n;
    
    for (int i = 1; i<=n;i++) {
        cin >> num;
        if (i == 1 || n>may) {
            may = num;
            posmay = i;
        }
    }
    
    cout << endl << endl <<
    "Mayor: " << may << endl <<
    "Posición: " << posmay << endl << endl;
    
}

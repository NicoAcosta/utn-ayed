#include <iostream>
using namespace std;

int main() {
    
    int m, n=0;
    cout << "Ingrese M: ";
    cin >> m;
    
    
    
    while (m) {
        if (!(n%3) && n%5) {
            cout << n << endl;
            m--;
        }
        n = n+3;
    }
}

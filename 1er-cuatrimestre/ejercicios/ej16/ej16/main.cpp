#include <iostream>
using namespace std;

int main() {
    
    int n, nn=0;
    cout << "Ingrese n" << endl;
    cin >> n;
    while (n>=0) {
        nn++;
        cout << n << endl;
        cin >> n;
    }
    cout << endl << endl << nn << endl << endl << endl;
    
}

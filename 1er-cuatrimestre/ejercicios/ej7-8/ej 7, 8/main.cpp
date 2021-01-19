#include <iostream>
using namespace std;

int main() {
    
    int a, b, c;
    cout << "Lados: " << endl;
    cin >> a >> b >> c;
    if ( a>0 && b>0 && c>0) {
        
        if (a == b || a == c || b == c){
            if (a == b && b == c)
                cout << "Equilátero" << endl;
            else
                cout << "Isósceles" << endl;
        } else
            cout << "Escaleno" << endl;
        
    } else {
        cout << "No forman triángulo" << endl << endl;
    }
}

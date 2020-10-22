#include <iostream>
using namespace std;

int main() {
    
    cout << "Ingrese 7 numeros:" << endl << endl;
    int n, suma100 = 0, cant100 = 0, suma10 = 0;
    
    for (int i = 0; i < 7; i++) {
        cin >> n;
        if (n>100){
            suma100 += n;
            cant100++;
        }
        if (n<-10){
            suma10 += n;
        }
    }
    
    cout << "Prom may 100: " << (float)suma100/cant100 << endl <<
    "Suma men -10: " << suma10 << endl;
    
}

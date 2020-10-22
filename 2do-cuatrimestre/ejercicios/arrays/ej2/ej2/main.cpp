
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    
    float numeros[14], suma = 0;
    
    for (int i=0; i<15; i++) {
        
        cin >> numeros [i];
        suma += numeros[i];
        
    }
    
    float may, men, prom = suma/15;
    float clsprom, difprom;
    
    for (int i=0; i<15; i++) {
        
        if (i == 0 || numeros[i] > may)
            may = numeros[i];
        
        if (i == 0 || numeros[i] < men)
            men = numeros[i];
        
        if (i == 0 || (abs(numeros[i]-prom)) < difprom ) {
            clsprom = numeros[i];
            difprom = abs(numeros[i]-prom);
        }

    }
    
    cout    << endl << endl
            << "Mayor: " << may << endl
            << "Menos: " << men << endl
    << "Más cerca del prom: " << clsprom << "(" << difprom << ")" << endl;
    
    
}

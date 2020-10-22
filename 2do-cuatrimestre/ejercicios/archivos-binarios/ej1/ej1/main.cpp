#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


int main() {
    
    FILE *f;
    int nVal;
    float val;
    
    
    f = fopen("archivo1.jaja", "wb");
    if (f) {
        
        cout << "Ingrese cantidad de valores: " << endl;
        cin >> nVal;
        
        for (int i = 0; i < nVal; i++) {
            cout << endl << endl << "Ingrese valor nº " << i << ": " << endl ;
            cin >> val;
            fwrite(&val, sizeof(float), 1, f);
        }
        
        
        fclose(f);
        f = fopen("archivo1.jaja", "rb");
        
        cout << endl << endl << endl <<
        "Valores ingresados: " << endl << endl;
        for (int i = 0; i < nVal; i++) {
            fread(&val, sizeof(float), 1, f);
            cout << "Valor nº " << i << ": " << val << endl;
        }
        
        
        fclose(f);
    } else
        cout << "Error al abrir el archivo." << endl;
    
    
    
    
    return 0;
}

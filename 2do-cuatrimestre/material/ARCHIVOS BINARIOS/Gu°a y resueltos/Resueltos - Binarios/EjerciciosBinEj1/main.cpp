#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main()
{
    int n, valor;
    cout << "Ingrese la cantidad de valores a escribir:" << endl;
    cin >> n;
    FILE *f;
    int i;
    if (f = fopen("ejercicio1.ayed","ab"))
    {
        for (i=0; i<n;i++)
        {
            cout << "Ingrese el valor " << i + 1 << ":" << endl;
            cin >> valor;
            fwrite(&valor,sizeof(int),1,f);
        }
        fclose(f);
    }
    else
    {
        cout << "Error al intentar crear el archivo." << endl;
        return 1;
    }
    cout << "Muestra los valores" << endl;
    if (f = fopen("ejercicio1.ayed","rb"))
    {
            cout << "Leemos hasta que feof(f) sea true" << endl;
            fread(&valor,sizeof(int),1,f);
            while (!feof(f))
            {
                cout << "Leyo: " << valor << endl;
                fread(&valor,sizeof(int),1,f);
            }
            /*Otra forma de leer hasta el final
            sin utilizar feof */
            cout << "Leemos haciendo while fread:" << endl;
            fseek(f,0,SEEK_SET);
            while (fread(&valor,sizeof(int),1,f))
            {
                cout << "Leyo: " << valor << endl;
            }
            fclose(f);
    }
    else
    {
        return 1;
    }
    getch();
    return 0;
}

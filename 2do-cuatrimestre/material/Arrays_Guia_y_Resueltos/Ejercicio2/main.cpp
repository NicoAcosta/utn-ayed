#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;

int mayor(int v[], int tam)
{
    int i;
    int mayor= v[0];
    for (i=1;i<tam;i++)
    {

            if (v[i]>mayor)
                mayor = v[i];
    }
    return mayor;
}

int menor(int v[], int tam)
{
    int i;
    int menor= v[0];
    for (i=1;i<tam;i++)
    {

            if (v[i]<menor)
                menor = v[i];
    }
    return menor;
}


float promedio(int v[], int tam)
{
    int i;
    float sum=0;
    for (i=0;i<tam;i++)
    {
            sum+= v[i];
    }
    return sum/tam;
}

int mascercano(int v[], int tam)
{

    int i;
    float prom = promedio(v,tam);
    float distmc= abs(v[0]- prom);
    int mc = v[0];
    for (i=0;i<tam;i++)
    {
        if (abs(v[i]-prom)< distmc)
        {
            distmc= abs(v[i]-prom);
            mc= v[i];
        }
    }
    return mc;
}

int main()
{
    int v[15],i;
    cout << "**** INGRESE LOS 15 VALORES ****" << endl;
    for (i=0;i<15;i++)
    {
            cout << "v[" << i << "]= ";
            cin >> v[i];
    }
    cout << "El mayor es: " << mayor(v,15) << endl;
     cout << "El menor es: " << menor(v,15) << endl;
     cout << "El mas cercado al promedio ("<< promedio(v,15) << ") es: " << mascercano(v,15) << endl;
    getch();
    return 0;
}

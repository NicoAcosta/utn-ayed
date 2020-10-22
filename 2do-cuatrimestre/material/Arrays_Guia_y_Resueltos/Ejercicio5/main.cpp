#include <iostream>
//#include <conio.h>
using namespace std;


void suma(int vec1[], int vec2[], int result[], int tam)
{
    for (int i=0; i< tam; i++)
    {
        result[i] = vec1[i] + vec2[i];
    }
    return;
}

int ProductoEscalar(int vec1[], int vec2[], int tam)
{
    int sum = 0;
    for (int i=0; i< tam; i++)
    {
       sum += vec1[i] * vec2[i];
    }
    return sum;
}

int main()
{
    int VectorUno[10]= {3,2,3,4,5};
    int VectorDos[10]= {6,7,8,9,10};
    int Resultado[10];
    int tam;
    cout << "Ingrese el tamaño" << endl;
    cin >> tam;
    suma(VectorUno,VectorDos, Resultado,5);
    cout << "La suma es: " << endl;
    for (int i =0; i < tam; i++)
            cout << "Resultado[" << i << "]= " << Resultado[i] << endl;
    cout << endl << endl << "El producto escalar es: " << ProductoEscalar(VectorUno,VectorDos,5) << endl;
    //getch();
    return 0;
}

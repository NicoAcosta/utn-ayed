#include <iostream>
#include <conio.h>
using namespace std;


void invert(int vec[], int i, int tam)
{
    int aux;
    if (i < tam/2)
    {
        aux = vec[i];
        vec[i] = vec[tam-1-i];
        vec[tam -1- i] = aux;
        invert(vec, i+1, tam);
    }
    return;

}
int main()
{
    int v[]= {1,2,3,4,5,6,7,8,9,10,11};
    invert(v,0,11);
    for (int i =0; i < 11; i++)
            cout << "v[" << i << "]= " << v[i] << endl;
    getch();
    return 0;
}

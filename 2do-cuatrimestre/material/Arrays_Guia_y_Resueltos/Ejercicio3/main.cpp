#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    char c;
    char un_vector[100];
    int cont =0;
    c = getche();
    while (c != '/')
    {
        un_vector[cont] = c;
        cont++;
        c = getche();
    }
    cout << "La palabra al reves es: " << endl;
    for (int i=cont-1; i>=0; i--)
        cout << un_vector[i];

    return 0;
}

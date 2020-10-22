#include <iostream>
#include "pilas.h"


using namespace std;


int main()
{
    int a;
    NodoPila *mipila=NULL;
    char letra;
    while (1 == 1)
    {
            push(mipila,letra);
    }
    cout << endl;
    while(mipila)
    {
        cout << pop(mipila);
    }
    cout << "FIN"<< endl;
    cin >> a;
    return 0;
}

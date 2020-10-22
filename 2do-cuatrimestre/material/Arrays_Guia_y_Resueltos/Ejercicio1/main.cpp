#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int v[10],i;
    for (i=0;i<10;i++)
    {
            cout << "v[" << i << "]= ";
            cin >> v[i];
    }
    cout << "**** LISTA EN ORDEN INVERSO ****" << endl;
    for (i=9;i>=0;i--)
    {
            cout << "v[" << i << "]= " << v[i] << endl;
    }
    getch();
    return 0;
}

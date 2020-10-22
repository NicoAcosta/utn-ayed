#include <iostream>

using namespace std;

int main()
{
    int m,cantmostrados=0,num=1;
    cout << "Ingrese un numero:" << endl;
    cin >> m;
    while (cantmostrados < m)
    {
        if (num%3==0 && num%5!=0)
        {
            cout << num << endl;
            cantmostrados++;
        }
        num++;
    }
    return 0;
}

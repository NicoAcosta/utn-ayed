#include <iostream>

using namespace std;

int main()
{
    int m,i=0,num=1;
    cout << "Ingrese un numero:" << endl;
    cin >> m;
    do
    {
        if (num%3==0 && num%5!=0)
        {
            cout << num << endl;
            i++;
        }
        else
            num++;
    }
    while (i < m);
    return 0;
}

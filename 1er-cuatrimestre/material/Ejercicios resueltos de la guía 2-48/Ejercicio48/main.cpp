#include <iostream>

using namespace std;

bool esPrimo(int num)
{
    for (int i=num-1;i>1;i--)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    cout << "esPrimo(1527): " << esPrimo(1527) << endl;
    cout << "esPrimo(997): " << esPrimo(997) << endl;
    cout << "esPrimo(1039): " << esPrimo(1039) << endl;
    return 0;
}

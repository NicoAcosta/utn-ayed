#include <iostream>

using namespace std;


int MCD(int A, int B)
{
    int resto;
    while (1)
    {
        resto = A % B;
        if (resto == 0)
            return B;
        A = B;
        B = resto;
    }
    return 0; //Nunca debería llegar a esta instancia

}


int main()
{
    cout << MCD(19,7) << endl;
    return 0;
}

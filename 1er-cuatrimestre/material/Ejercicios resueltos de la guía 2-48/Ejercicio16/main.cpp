#include <iostream>

using namespace std;

int main()
{
    int i = 0, valor;
    int j = 0;
    //Solución no recomendada con for
    cout << "Contamos valores hasta leer negativo con for:" << endl;
    for (i = 0; i <= 1; i++)
    {
        cin >> valor;
        if (valor >=0)
        {
            j++;
            i=0;
        }
        else
            i=2;
    }
    if (!j) //es equivalente a if (j==0)
        cout << "No se ingresaron valores" << endl;
    else
        cout << "Se ingresaron " << j << " valores." << endl;

    //Solución correcta: while o do while, con while:
    cout << "Contamos valores hasta leer negativo con while:" << endl;
    j = 0;
    cin >> valor;
    while (valor >=0)
    {
        j++;
        cin >> valor;
    }
    if (!j) //es equivalente a if (j==0)
        cout << "No se ingresaron valores" << endl;
    else
        cout << "Se ingresaron " << j << " valores." << endl;
    //con do - while:
    cout << "Contamos valores hasta leer negativo con do-while:" << endl;
    j = -1;
    do
    {
        j++;
        cin >> valor;
    }
    while (valor >=0);
    if (!j) //es equivalente a if (j==0)
        cout << "No se ingresaron valores" << endl;
    else
        cout << "Se ingresaron " << j << " valores." << endl;

    return 0;
}

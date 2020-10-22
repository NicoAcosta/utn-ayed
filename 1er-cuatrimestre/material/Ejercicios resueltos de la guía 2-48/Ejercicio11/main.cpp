#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int mes, agno;
    bool bisiesto=false;
    cout << "Ingrese mes y año respectivamente" << endl;
    cin >> mes >> agno;
    if (!(agno%4)) //if (agno % 4 == 0)
    {
        if(!(agno%100) && agno%400) //if (agno%100==0 && agno%400!=0)
            bisiesto = false;
        else
            bisiesto = true;
    }
    switch (mes)
    {
        case 1:case 3:
        case 5:case 7:
        case 8:case 10:
        case 12:
            cout << "Tiene 31 dias" << endl;
        break;
        case 4:case 6:
        case 9:case 11:
            cout << "Tiene 30 dias" << endl;
        break;
        case 2:
            if (bisiesto == true)
                cout << "Tiene 29" << endl;
            else
                cout << "Tiene 28" << endl;
        break;
        default:
            cout << "Error: mes no valido" << endl;

    }
    getch();
    return 0;
}

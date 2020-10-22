#include <iostream>
#include <cstring>
#include <conio.h> //getch
#include <stdio.h> //fflush
#include <stdlib.h> //atoi
using namespace std;

void inicializar(char tabla[][4][50])
{
    for (int i=0;i< 100; i++)
    {
        for (int j=0; j< 4; j++)
        {
            strcpy(tabla[i][j],"");
        }
    }
    return;
}

void leer_datos(char tabla[][4][50], int fila)
{
    cout << "Ingrese apellido y nombre" << endl;
    fflush(stdin);
    gets(tabla[fila][0]);
    cout << "Ingrese direccion" << endl;
    fflush(stdin);
    gets(tabla[fila][1]);
    cout << "Ingrese telefono" << endl;
    cin >> tabla[fila][2];
    cout << "Ingrese codigo postal" << endl;
    cin >> tabla[fila][3];
    return;
}


void mostrar_filas(char tabla[][4][50], int cant_filas)
{
    cout << "|  Apellido y nombre     | Direccion     |  Telefono   |   Cod. Postal " << endl;
    for (int i=0;i<cant_filas;i++)
    {
        cout << tabla[i][0] << "   |   " << tabla[i][1] << "   |   " ;
        cout << tabla[i][2] << "   |   " <<tabla[i][3] << endl;
    }
    return;
}

void burbuja(char tabla[][4][50], int tam)
{
    char aux[50];
    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = 0; j < tam - 1 - i; j++)
        {
            //La funcion atoi transforma un string a integer
            if (atoi(tabla[j+1][3])< atoi (tabla[j][3]))
            {
                for (int columna=0; columna < 4; columna++)
                {

                    strcpy(aux, tabla[j][columna]);
                    strcpy(tabla[j][columna], tabla[j+1][columna]);
                    strcpy(tabla[j+1][columna], aux);
                }
            }
        }
    }
    return;
}

int main()
{
    char tabla[100][4][50];
    inicializar(tabla);
    leer_datos(tabla,0);
    leer_datos(tabla,1);
    leer_datos(tabla,2);
    leer_datos(tabla,3);
    leer_datos(tabla,4);
    mostrar_filas(tabla,5);
    burbuja(tabla,5);
    cout << " ****************************** " << endl << endl;
    mostrar_filas(tabla,5);

    return 0;
}

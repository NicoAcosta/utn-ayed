#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

int guardar_n(char ruta[])
{
    FILE *f;
    int i,n, aux;
    cout << "Ingrese n:" << endl;
    cin >> n;
    if (f = fopen(ruta,"ab"))
    {
        for (i=1; i<=n;i++)
        {
            cout << "Ingrese un nro:" << endl;
            cin >> aux;
            fwrite(&aux,sizeof(int),1,f);
        }
        fclose(f);
        return 0;
    }
    else
        return 1;
}

int modifica(char ruta[])
{
    int tam, cantidad,n, aux;
    FILE *f;
    if (f = fopen(ruta,"rb+"))
    {
        cout << "Ingrese el n que quiere modificar" << endl;
        cin >> n;
        fseek(f,0, SEEK_END);
        tam = ftell(f);
        cantidad = tam /sizeof(int);
        if (n>cantidad)
            cout << "Error, no existe n" << endl;
        else
        {
            cout << "Ingrese el nuevo valor" << endl;
            cin >> aux;
            fseek(f,sizeof(int)*(n-1), SEEK_SET);
            fwrite(&aux,sizeof(int),1,f);

        }
        fclose(f);
        return 0;
    }
    else
        return 1;
}

int mostrartodo(char ruta[])
{
    FILE *f;
    int i,n, aux;

    if (f = fopen("prueba.laquequieras","rb"))
    {
        fread(&aux,sizeof(int),1,f);
        while (!feof(f))
        {
            cout << "Leyo: " << aux << endl;
            fread(&aux,sizeof(int),1,f);
        }
        fclose(f);
        return 0;
    }
    else
        return 1;
}

int main()
{

    char ruta_y_nombre[] = "prueba.laquequieras";
    char opcion;
    do
    {
        cout << "Elija una opcion" << endl;
        cout << "1 - Ingresar elementos" << endl;
        cout << "2 - Modificar elemento" << endl;
        cout << "3 - Mostrar el archivo" << endl;
        cout << "esc - Salir" << endl;
        do
        {
                opcion= getch();
        }
        while (opcion!='1' && opcion!='2' && opcion!='3' && opcion!=27);
        switch(opcion)
        {
            case '1':
                guardar_n(ruta_y_nombre);
                break;
            case '2':
                modifica(ruta_y_nombre);
                break;
            case '3':
                mostrartodo(ruta_y_nombre);
                break;
        }


    }while (opcion!= 27);
    getch();
    return 0;
}

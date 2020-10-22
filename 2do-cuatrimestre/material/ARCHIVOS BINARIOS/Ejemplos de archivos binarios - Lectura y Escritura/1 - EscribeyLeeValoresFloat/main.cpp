#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main()
{
    cout << "Escribamos los nros del 1 al 100 en el archivo:" << endl;
    FILE *f;
    int i;
    if (f = fopen("prueba.laquequieras","wb"))
    {
        for (i=1; i<=100;i++)
        {
            fwrite(&i,sizeof(int),1,f);
        }
        fclose(f);
    }
    else
    {
        cout << "Error al intentar crear el archivo." << endl;
        return 1;
    }
    cout << "Se hace la verificación de la escritura" << endl;
    int x;
    if (f = fopen("prueba.laquequieras","rb"))
    {
        for (i=1; i<=100;i++)
        {
            fread(&x,sizeof(int),1,f);
            cout << "Leyo: " << x << endl;
        }
        fclose(f);
    }
    cout << "Presione una tecla para sumar 1500 al número que esta en la pos 20" << endl;
    getch();
    if (f = fopen("prueba.laquequieras","rb+"))
    {
        fseek(f,sizeof(int)*19, SEEK_SET);
        fread(&i,sizeof(int),1,f);
        i+=1500;
        fseek(f,(-1)*sizeof(int), SEEK_CUR);
        fwrite(&i,sizeof(int),1,f);
        fclose(f);
    }
    cout << "Nro. modificado aprete una tecla para verificar" << endl;
    getch();
    cout << "Se hace la verificación de la escritura" << endl;
    if (f = fopen("prueba.laquequieras","rb"))
    {
        int  num;
        for (i=1; i<=100;i++)
        {
            fread(&num,sizeof(int),1,f);
            cout << "Leyo: " << num << endl;
        }
        fclose(f);
    }
    getch();
    return 0;
}

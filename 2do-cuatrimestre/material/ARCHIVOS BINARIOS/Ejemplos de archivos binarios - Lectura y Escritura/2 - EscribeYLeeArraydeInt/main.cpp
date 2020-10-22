#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main()
{
    cout << "Escribamos un array de 5 elementos." << endl;
    FILE *f;
    int i,num;
    int vec[] = {78,91,4,8,10};
    int aux[] = {0,0,0,0,0};
    if (f = fopen("prueba.laquequieras","wb"))
    {
        cout << "El tamaño del vector es: " << sizeof(vec) << endl;
        fwrite(vec,sizeof(int),5,f);
        fclose(f);
    }
    else
    {
        cout << "Error de escritura" << endl;
        return 1;
    }

    if (f = fopen("prueba.laquequieras","rb"))
    {
        cout << "Puedo leer de a uno, presione una tecla para hacerlo" << endl;
        getch();
        for (i=0; i<5;i++)
        {
            fread(&num,sizeof(int),1,f);
            cout << "Leyo: " << num << endl;
        }
        cout << "También pudo leer todo un array. Presione una tecla." << endl;
        getch();
        fseek(f, 0, SEEK_SET);
        fread(aux,sizeof(int),5,f);
        for (i=0; i<5;i++)
        {
            cout << "aux[" << i << "]=" << aux[i] << endl;
        }

        fclose(f);
    }
    getch();
    return 0;
}

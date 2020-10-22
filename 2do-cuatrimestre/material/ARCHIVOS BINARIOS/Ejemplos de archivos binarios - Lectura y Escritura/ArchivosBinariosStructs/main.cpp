#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <conio.h>

/* un struct cualquiera */

struct rec

{
    int x,y,z;
};

/* escribe 10 registros en el archivo PRUEBA */
using namespace std;

int main()

{
    int i,j;
    FILE *f;
    rec r;
    /* CREAMOS EL ARCHIVO */
    f=fopen("PRUEBA","wb");
    for (i=1;i<=10; i++)
    {
        r.x=i;
        r.y=i;
        r.z=i;
        fwrite(&r,sizeof(rec),1,f);
    }
    fclose(f);
    cout << "Archivo creado y escrito con los números de 1 a 10" << endl;
    cout << "Presione una tecla para leer desde cero" << endl;
    getch();
    /* LEEMOS 10 REGISTROS DESDE 0 y MOSTRAMOS POR PANTALLA*/
    f=fopen("PRUEBA","rb");
    for (i=1;i<=10; i++)
    {
        fread(&r,sizeof(rec),1,f);
        cout << "x= " << r.x << "y= " << r.y << "z= " << r.z << endl;
    }
    fclose(f);
    cout << "Registros leídos" << endl;
    cout << "Presione una tecla para continuar con la lectura inversa" << endl;
    getch();
    /* CON FSEEK PODEMOS UBICARNOS COMO QUISIERAMOS, INCLUSO PODEMOS LEER AL REVES*/
    f=fopen("PRUEBA","rb");
    for (i=9; i>=0; i--)
    {
        fseek(f,sizeof(rec)*i,SEEK_SET);
        fread(&r,sizeof(rec),1,f);
        cout << "x= " << r.x << "y= " << r.y << "z= " << r.z << endl;
    }
    fclose(f);
    cout << "Registros leídos" << endl;
    cout << "Presione una tecla para leer los primeros 5 registros" << endl;
    getch();
    /* TAMBIEN PODEMOS LEER CUALQUIER OTRO REGISTRO */
    f=fopen("PRUEBA","rb");
    //fseek(f,0,SEEK_SET);
    for (i=0;i<5; i++)
    {
        fread(&r,sizeof(rec),1,f);
        cout << "x= " << r.x << "y= " << r.y << "z= " << r.z << endl;
        fseek(f,sizeof(rec),SEEK_CUR);
    }
    fclose(f);
    /* IMPRIÓ LOS PRIMEROS 5? POR QUÉ? */

    cout << "Registros leídos" << endl;
    cout << "Ahora cambiamos el valor x del 5to elemento: Presione una tecla para continuar:" << endl;
    getch();
    f=fopen("PRUEBA","rb+");
    fseek(f,sizeof(rec)*4,SEEK_SET);
    fread(&r,sizeof(rec),1,f);
    r.x+=100;
    //fseek(f,sizeof(rec)*4,SEEK_SET);
    fseek(f,-sizeof(rec),SEEK_CUR);
    fwrite(&r,sizeof(rec),1,f);
    fclose(f);
    cout << endl;
    /* VOLVEMOS A MOSTRAR LOS REGISTROS PARA VER QUE EL 5TO CAMBIO*/
    f=fopen("PRUEBA","r");
    for (i=1;i<=10; i++)
    {
        fread(&r,sizeof(rec),1,f);
        cout << "x= " << r.x << "y= " << r.y << "z= " << r.z << endl;
    }
    fclose(f);
    return 0;
}

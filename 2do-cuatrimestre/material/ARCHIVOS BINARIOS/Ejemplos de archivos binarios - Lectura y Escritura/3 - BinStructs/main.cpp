#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <conio.h>
#define NOMBREARCHIVO "miarchivo.ayed"

using namespace std;
struct persona
{
    char DNI[10];
    char nombre[20];
    char apellido[20];
    int edad;
};


bool guardarregistro(void)
{
    FILE *f;
    persona p;
    if (f=fopen(NOMBREARCHIVO,"ab"))
    {
        cout << "Ingrese DNI:" << endl;
        cin >>  p.DNI;
        cout << "Ingrese nombre:" << endl;
        cin >> p.nombre;
        cout << "Ingrese apellido:" << endl;
        cin >> p.apellido;
        cout << "Ingrese edad:" << endl;
        cin >> p.edad;
        fwrite(&p, sizeof(persona),1,f);
        fclose(f);
        return true;
    }
    return false;
}

int mostrartodo(void)
{
    FILE *f;
    persona p;
    if (f=fopen(NOMBREARCHIVO,"rb"))
    {
        fread(&p,sizeof(persona),1,f);
        while(!feof(f))
        {
            cout << "****** Datos de la persona *******" << endl;
            cout << "DNI " << p.DNI << endl;
            cout << "Nombre: " << p.nombre << endl;
            cout << "Apellido: " << p.apellido << endl;
            cout << "Edad: " << p.edad << endl;
            fread(&p,sizeof(struct persona),1,f);
        }
        fclose(f);
        return 1;
    }
    return 0;
}

int buscar(char DNI[])
{
    FILE *f;
    int encontrado =0;
    struct persona p;
    if (f=fopen(NOMBREARCHIVO,"rb"))
    {
        while(!feof(f) && !encontrado)
        {
            fread(&p,sizeof(struct persona),1,f);
            if (strcmp(DNI, p.DNI)==0)
            {
                encontrado = 1;
                            cout << "****** Datos de la persona *******" << endl;
            cout << "DNI " << p.DNI << endl;
            cout << "Nombre: " << p.nombre << endl;
            cout << "Apellido: " << p.apellido << endl;
            cout << "Edad: " << p.edad << endl;
            }
        }
        if (!encontrado)
            printf("No se encontro la persona buscada.\n");
        fclose(f);
        return 1;
    }
    return 0;
}


char menu()
{
    char opcion;
    cout << "Seleccione una opcion:" << endl;
    cout << "1 - Ingresar un nuevo registro" << endl;
    cout << "2 - Mostrar todo"<< endl;
    cout << "3 - Buscar un registro por DNI"<< endl;
    cout << "Esc - Salir" << endl;
    do
        opcion = getch();
    while (opcion != '1' && opcion != '2' && opcion != '3' && opcion != 27);
    char dnibuscado[10];
    switch (opcion)
    {
        case '1':
            if (guardarregistro())
                cout << "El registro se ha guardado con exito." << endl;
            else
                cout << "Error al intentar abrir el archivo." << endl;
        break;
        case '2':
            if (!mostrartodo())
                cout << "Error al intentar abrir el archivo." << endl;

        break;
        case '3':
            cout << "Ingrese el DNI de la persona buscada" << endl;
            cin >> dnibuscado;
            if (!buscar(dnibuscado))
                cout << "Error al intentar abrir el archivo." << endl;
        break;
    }
    return opcion;
}

int main()

{
    char out;
    do
        out = menu();
    while (out != 27);
  return 0;
}

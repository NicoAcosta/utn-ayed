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
    bool borrado = false;
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
            cout << "Borrado: " << p.borrado << endl;
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
            cout << "Borrada: " << p.borrado<< endl;
            }
        }
        if (!encontrado)
            printf("No se encontro la persona buscada.\n");
        fclose(f);
        return 1;
    }
    return 0;
}

int borrar (char DNI[])
{
    FILE *f;
    int encontrado =0;
    persona p;
    if (f=fopen(NOMBREARCHIVO,"rb+"))
    {
        while(!feof(f) && !encontrado)
        {
            fread(&p,sizeof(persona),1,f);
            if (strcmp(DNI, p.DNI)==0)
            {
                encontrado = 1;
                p.borrado = 1;
                fseek(f,-sizeof(persona), SEEK_CUR);
                fwrite(&p,sizeof(persona),1,f);
            }
        }
        if (!encontrado)
            cout << "No se encontro la persona a borrar." << endl;
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
    cout << "4 - Borrado lógicamente un registro por DNI"<< endl;
    cout << "5 - Limpiar archivo (borrado físico)"<< endl;
    cout << "Esc - Salir" << endl;
    do
        opcion = getch();
    while (!(opcion > '0' && opcion < '6') && (opcion != 27));
    char dnibuscado[10];
    switch (opcion)
    {
        case '1':
            if (guardarregistro())
                printf("El registro se ha guardado con exito.\n");
            else
                printf("Error al intentar abrir el archivo.\n");
        break;
        case '2':
            if (!mostrartodo())
                printf("Error al intentar abrir el archivo.\n");

        break;
        case '3':
            printf("Ingrese el DNI de la persona buscada\n");
            scanf("%s", dnibuscado);
            if (!buscar(dnibuscado))
                printf("Error al intentar abrir el archivo.\n");
        break;
        case '4':
            cout << "Ingrese el DNI de la persona a borrar" << endl;
            cin >> dnibuscado;
            borrar(dnibuscado);
        break;
        case '5':
            FILE *faux;
            FILE *f;
            persona p;
            faux = fopen("auxiliar","wb");
            if (f=fopen(NOMBREARCHIVO,"rb"))
            {
                while(!feof(f))
                {
                    fread(&p,sizeof(persona),1,f);
                    if (!p.borrado && !feof(f))
                    {
                        fwrite(&p, sizeof(persona),1,faux);
                    }
                }
                fclose(f);
            }
            fclose(faux);
            if (!remove(NOMBREARCHIVO))
            {
                if(!rename("auxiliar",NOMBREARCHIVO))
                    cout << "Archivo renombrado exitosamente" << endl;
                else
                    cout << "No se pudo renombrar el archivo" << endl;
            }
            else
                cout << "No se pudo borrar el viejo archivo" << endl;

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

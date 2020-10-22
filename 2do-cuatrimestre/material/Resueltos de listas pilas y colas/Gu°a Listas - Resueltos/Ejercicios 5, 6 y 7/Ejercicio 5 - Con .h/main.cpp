/* EJERCICIO 5 */
#include <stdio.h> //Se agrega para poder usar archivos
#include <iostream>
#include <conio.h>
#include <cstring>
#include "listaAlumnos.h"
using namespace std;



/*CARGARDATOSPRUEBA: Función que agrega 4 alumnos en un archivo (sobreescribe si ya existe)
para poder probar el programa rápidamente */
void CargarDatosPrueba(void)
{
    FILE *f;
    f=fopen("archivoalumnos.data","wb");
    Alumno x;
    if (f)
    {
        /*SE CARGAN 4 ALUMNOS DE PRUEBA */
        strcpy(x.apellido,"HERRERA");
        strcpy(x.nombre,"FLORENCIA");
        strcpy(x.dni,"35678321");
        x.codcarrera=10;
        x.legajo=190263;
        fwrite(&x, sizeof(Alumno),1,f);

        strcpy(x.apellido,"MAXIMILIANO");
        strcpy(x.nombre,"MENDEZ");
        strcpy(x.dni,"36432128");
        x.codcarrera=10;
        x.legajo=126211;
        fwrite(&x, sizeof(Alumno),1,f);

        strcpy(x.apellido,"JIMENA");
        strcpy(x.nombre,"REY");
        strcpy(x.dni,"30623943");
        x.codcarrera=10;
        x.legajo=190263;
        fwrite(&x, sizeof(Alumno),1,f);

        strcpy(x.apellido,"WALLACE");
        strcpy(x.nombre,"ESTHER");
        strcpy(x.dni,"12321543");
        x.codcarrera=10;
        x.legajo=71432;
        fwrite(&x, sizeof(Alumno),1,f);

        fclose(f);
        cout << "El archivo ha sido cargado con exito" << endl;
    }
    else
        cout << "Error: no se pudo crear el archivo" << endl;
    return;
}

int main()
{
    FILE *f;
    NodoListaSEAlumno *lAlumnos=NULL;
    Alumno r;
    CargarDatosPrueba();
    f=fopen("archivoalumnos.data","rb");
    fread(&r,sizeof(Alumno),1,f);
    while (!feof(f))
    {
        ListaAlumnoInsertarSiguiente(lAlumnos,r);
        fread(&r,sizeof(Alumno),1,f);
    }
    fclose(f);
    ListaAlumnoListar(lAlumnos);
    ListaAlumnoborrarLista(lAlumnos);
    char c = getch();
    return 0;
}

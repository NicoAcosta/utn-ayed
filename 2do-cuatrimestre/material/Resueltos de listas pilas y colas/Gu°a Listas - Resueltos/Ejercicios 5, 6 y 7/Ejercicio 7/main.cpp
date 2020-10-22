/* EJERCICIO 6*/
#include <stdio.h> //Se agrega para poder usar archivos
#include <iostream>
#include <conio.h>
#include <cstring>
#include "listaAlumnos.h"

#define RUTA_ALUMNOS "archivoalumnos.data"
#define RUTA_MATERIAS "archivomaterias.data"
using namespace std;



/*CARGARDATOSPRUEBA: Función que agrega 4 alumnos en un archivo (sobreescribe si ya existe)
para poder probar el programa rápidamente */
void CargarAlumnosPrueba(void)
{
    FILE *f;
    f=fopen(RUTA_ALUMNOS,"wb");
    Alumno x;
    if (f)
    {
        /*SE CARGAN 4 ALUMNOS DE PRUEBA */
        strcpy(x.apellido,"HERRERA");
        strcpy(x.nombre,"FLORENCIA");
        strcpy(x.dni,"35678321");
        x.codcarrera=10;
        x.legajo=117764;
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
void CargarMateriasPrueba(void)
{
    FILE *f;
    f=fopen(RUTA_MATERIAS,"w");
    Materia x;
    if (f)
    {

        strcpy(x.nombreMateria,"Algoritmos y Estructura de Datos");
        strcpy(x.fechaAprobacion,"1995-06-28");
        x.libro=10;
        x.folio=114;
        x.nota= 8;
        x.legajo=71432;
        fwrite(&x, sizeof(Materia),1,f);

        strcpy(x.nombreMateria,"Algoritmos y Estructura de Datos");
        strcpy(x.fechaAprobacion,"2014-11-28");
        x.libro=41;
        x.folio=19;
        x.nota= 9;
        x.legajo=190263;
        fwrite(&x, sizeof(Materia),1,f);

        strcpy(x.nombreMateria,"Fisica I");
        strcpy(x.fechaAprobacion,"1997-03-15");
        x.libro=21;
        x.folio=711;
        x.nota= 7;
        x.legajo=71432;
        fwrite(&x, sizeof(Materia),1,f);
        fclose(f);

        cout << "El archivo ha sido cargado con exito" << endl;
    }
    else
        cout << "Error: no se pudo crear el archivo" << endl;
    return;
}


char mostrarmenu()
{
    cout << "Ingrese una opcion: " << endl;
    cout << "0 - Levantar archivos de prueba (borra archivos anteriores)" << endl;
    cout << "1 - Buscar alumno por legajo" << endl;
    cout << "2 - Listar materias aprobadas de un alumno" << endl;
    cout << "3 - Listar promedio" << endl;
    cout << "4 - Agregar un alumno" << endl;
    cout << "5 - Agregar una materia" << endl;
    cout << "6 - Listar todos los alumnos" << endl;
    cout << "esc - Salir" << endl;
    char opcion;
    do
    {
       opcion=getch();
    } while ((opcion!='6') && (opcion!='0') &&(opcion!='1') && (opcion!='2') && (opcion!='3') && (opcion!='4') && (opcion!='5') && (opcion!=27));
    return opcion;
}

void levantarArchivos(NodoListaSEAlumno *&a)
{
    FILE *f;
    Alumno r;
    Materia m;
    f=fopen(RUTA_ALUMNOS,"r");
    fread(&r,sizeof(Alumno),1,f);
    while (!feof(f))
    {
        ListaAlumnoInsertarSiguiente(a,r);
        fread(&r,sizeof(Alumno),1,f);
    }
    fclose(f);
    /* levanta archivo de materias */
    f=fopen(RUTA_MATERIAS,"r");
    fread(&m,sizeof(Materia),1,f);
    while (!feof(f))
    {
        NodoListaSEAlumno *aux= BuscarAlumnoPorLegajo(a, m.legajo);
        if (aux)
        {
                    ListaMateriaInsertarSiguiente(aux->info.listaMaterias,m);
        }
        fread(&m,sizeof(Materia),1,f);
    }
    fclose(f);
    return;
}



void mostrarDatosAlumno(Alumno al)
{
        cout << "======== DATOS DEL ALUMNO " << al.apellido << "========" << endl;
        cout << "Apellido y nombre: " << al.apellido << ", " << al.nombre << endl;
        cout << "DNI: " << al.dni << endl;
        cout << "Legajo: " << al.legajo << endl;
        cout << "Carrera: " << al.codcarrera<< endl;
        return;
}

void guardarAlumnosDisco(NodoListaSEAlumno *la)
{
    FILE *arch_alumnos;
    FILE *arch_materias;
    NodoListaSEAlumno *auxAlu=NULL;
    NodoListaSEMateria *auxMat=NULL;
    if (arch_alumnos= fopen(RUTA_ALUMNOS,"wb"))
    {
        if (arch_materias= fopen(RUTA_MATERIAS,"wb"))
        {
            auxAlu= la;
            while (auxAlu)
            {
                fwrite(&(auxAlu->info), sizeof(Alumno),1,arch_alumnos);
                auxMat= auxAlu->info.listaMaterias;
                while(auxMat)
                {
                    fwrite(&(auxMat->info), sizeof(Materia),1,arch_materias);
                    auxMat= ListaMateriaObtenerSiguiente(auxMat);
                }
                auxAlu= ListaAlumnoObtenerSiguiente(auxAlu);
            }
            fclose(arch_materias);
        }
        else
            cout << "ERROR AL INTENTAR GRABAR ARCHIVO DE MATERIAS" << endl;
        fclose(arch_alumnos);
    }
    else
        cout << "ERROR AL INTENTAR GRABAR ARCHIVO DE ALUMNOS" << endl;
    return;
}

int main()
{
    NodoListaSEAlumno *lAlumnos=NULL;
    NodoListaSEAlumno *x=NULL;
    levantarArchivos(lAlumnos);
    char elegida;
    int legajo;
    do
    {
        elegida= mostrarmenu();
        switch (elegida)
        {
            case '0':
                ListaAlumnoborrarLista(lAlumnos);
                CargarAlumnosPrueba();
                CargarMateriasPrueba();
                levantarArchivos(lAlumnos);
                cout << "Archivos levantados correctamente" << endl;
            break;
            case '1':
                cout << "Ingrese legajo:" << endl;
                cin >> legajo;
                x= BuscarAlumnoPorLegajo(lAlumnos,legajo);
                if (x)
                    mostrarDatosAlumno(x->info);
                else
                    cout << "No se ha encontrado el alumno" << endl;
            break;
            case '2':
                cout << "Ingrese legajo:" << endl;
                cin >> legajo;
                x= BuscarAlumnoPorLegajo(lAlumnos,legajo);
                if (x)
                {
                    ListaMateriaListar(x->info.listaMaterias);
                }
                else
                    cout << "No se ha encontrado el alumno" << endl;
            break;
            case '3':
                cout << "Ingrese legajo:" << endl;
                cin >> legajo;
                x= BuscarAlumnoPorLegajo(lAlumnos,legajo);
                if (x)
                {
                    NodoListaSEMateria *materias= x->info.listaMaterias;
                    int acum=0;
                    int cont=0;
                    while (materias)
                    {
                        acum+= materias->info.nota;
                        cont++;
                        materias= ListaMateriaObtenerSiguiente(materias);
                    }
                    if (cont>0)
                        cout << "El promedio es:" << acum/cont << endl;
                    else
                        cout << "El alumno no tiene materias cargadas" << endl;
                }
                else
                    cout << "No se ha encontrado el alumno" << endl;
            break;
            case '4':
                Alumno nuevoAlumno;
                cout << "Ingrese los datos del alumno:" << endl;
                cout << "Legajo: ";
                cin >> nuevoAlumno.legajo;
                if (BuscarAlumnoPorLegajo(lAlumnos,nuevoAlumno.legajo))
                {
                    cout << "ERROR: YA EXISTE UN ALUMNO CON EL LEGAJO QUE INTENTA INGRESAR" << endl;
                }
                else
                {
                        cout << "DNI: ";
                        cin >> nuevoAlumno.dni;
                        if (BuscarAlumnoPorDNI(lAlumnos, nuevoAlumno.dni))
                        {
                            cout << "ERROR: YA EXISTE UN ALUMNO CON EL DNI QUE INTENTA INGRESAR" << endl;
                        }
                        else
                        {
                            cout << "Apellido: ";
                            cin >> nuevoAlumno.apellido;
                            cout << "Nombre: ";
                            cin >> nuevoAlumno.nombre;
                            cout << "Codigo de carrera: ";
                            cin >> nuevoAlumno.codcarrera;
                            ListaAlumnosInsertarAlFinal(lAlumnos,nuevoAlumno);
                            cout << "El alumno ha sido cargado con éxito" << endl;
                        }
                }
            break;
            case '5':
                cout << "Ingrese legajo:" << endl;
                cin >> legajo;
                x= BuscarAlumnoPorLegajo(lAlumnos,legajo);
                if (x)
                {
                    Materia nuevamateria;
                    cout << "Nombre de la materia: ";
                    cin >> nuevamateria.nombreMateria;
                    cout << "Fecha: ";
                    cin >> nuevamateria.fechaAprobacion;
                    cout << "Libro: ";
                    cin >> nuevamateria.libro;
                    cout << "Folio: ";
                    cin >> nuevamateria.folio;
                    cout << "Nota: ";
                    cin >> nuevamateria.nota;
                    nuevamateria.legajo= x->info.legajo;
                    ListaMateriasInsertarAlFinal(x->info.listaMaterias,nuevamateria);
                    cout << "Se ha agregado la materia al alumno." << endl;
                }
                else
                    cout << "ERROR: No se ha encontrado el alumno ingresado" << endl;
            break;
            case '6':
                x= lAlumnos;

                while (x)
                {
                    mostrarDatosAlumno(x->info);
                    x= x->sgte;
                }
            break;
        }
    } while (elegida!=27);
    guardarAlumnosDisco(lAlumnos);
    ListaAlumnoborrarLista(lAlumnos);
    return 0;
}

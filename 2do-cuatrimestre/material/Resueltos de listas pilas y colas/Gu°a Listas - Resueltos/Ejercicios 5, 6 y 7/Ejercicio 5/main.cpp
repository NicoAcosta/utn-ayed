/* EJERCICIO 5 */
#include <stdio.h> //Se agrega para poder usar archivos
#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;

struct Alumno
{
    char nombre[50];
    char apellido[50];
    char dni[11];
    int legajo;
    int codcarrera;
};

struct NodoListaSEAlumno
{
    Alumno info;             // Datos de el nodo
    NodoListaSEAlumno*sgte;  // Puntero al siguiente nodo

};


void ListaAlumnoInsertarSiguiente (NodoListaSEAlumno  *&n, Alumno x)
{
    NodoListaSEAlumno *nuevo= new NodoListaSEAlumno();
    nuevo->info=x;
    if (n!=NULL)
    {
        nuevo->sgte= n->sgte;
        n->sgte = nuevo;
    }
    else
    {
        nuevo->sgte= n;
        n= nuevo;
    }

    return;
}

void ListaAlumnoBorrarSiguiente(NodoListaSEAlumno  *n)
{
    NodoListaSEAlumno  *aborrar = n->sgte;
    NodoListaSEAlumno  *sgteaborrar;
    if (aborrar)
        sgteaborrar= aborrar->sgte;
    else
        sgteaborrar = NULL;
    n->sgte = sgteaborrar;
    delete aborrar;
    return;
}

NodoListaSEAlumno *ListaAlumnoObtenerSiguiente(NodoListaSEAlumno  *n)
{
    if (n)
        return n->sgte;
    else
        return NULL;
}

NodoListaSEAlumno *ObtenerUltimoAlumno(NodoListaSEAlumno * p)
{
    if (p)
    {
        while (p->sgte)
        {
            p = p->sgte;
        }
    }
    return p;

}

NodoListaSEAlumno* BuscarAlumnoPorDNI(NodoListaSEAlumno * raiz, char dnibuscado[])
{
    NodoListaSEAlumno *p=raiz;
    while (p && (strcmp(p->info.dni,dnibuscado)))
    {
        p = p->sgte;
    }
    return p;
}


NodoListaSEAlumno* ListaAlumnoBuscarNodoAnterior(NodoListaSEAlumno * raiz, NodoListaSEAlumno * anterior_a)
{
    NodoListaSEAlumno *p =NULL;
    if (raiz != anterior_a)
    {
        p = raiz;
        while (p && (p->sgte!= anterior_a) )
        {
            p = p->sgte;
        }
        return p;
    }
    else
        return NULL;
}

/*
BorrarNodo: recibe por parámetro lista y el puntero a borrar
*/
void borrarNodoAlumno(NodoListaSEAlumno *& raiz, NodoListaSEAlumno * aborrar)
{
    if (raiz && aborrar)
    {
        if (aborrar=raiz)
        {
            raiz = raiz->sgte;
            delete aborrar;
        }
        else
        {
            NodoListaSEAlumno *x = ListaAlumnoBuscarNodoAnterior(raiz,aborrar);
            ListaAlumnoBorrarSiguiente(x);
        }
    }
    return;
}


void ListaAlumnoborrarLista(NodoListaSEAlumno *&lista)
{
    NodoListaSEAlumno *anterior;
    NodoListaSEAlumno *paux;
    while (lista!=NULL)
    {
        anterior=NULL;
        paux= lista;
        while (paux && paux->sgte)
        {
            anterior = paux;
            paux= paux->sgte;
        }
        if (paux)
        {
            delete paux;
            if (anterior!=NULL)
                anterior->sgte=NULL;
            else
                lista =NULL;
        }
    }
    return;
}

void ListaAlumnoListar(NodoListaSEAlumno *lista)
{
    while (lista)
    {
        cout << "======== DATOS DEL ALUMNO " << lista->info.apellido << "========" << endl;
        cout << "Apellido y nombre: " << lista->info.apellido << ", " << lista->info.nombre << endl;
        cout << "DNI: " << lista->info.dni << endl;
        cout << "Legajo: " << lista->info.legajo << endl;
        cout << "Carrera: " << lista->info.codcarrera<< endl << endl;
        lista = lista->sgte;
    }
}

/*CARGARDATOSPRUEBA: Función que agrega 4 alumnos en un archivo (sobreescribe si ya existe)
para poder probar el programa rápidamente */
void CargarDatosPrueba(void)
{
    FILE *f;
    f=fopen("archivoalumnos.data","w");
    Alumno x;
    if (f)
    {
        /*SE CARGAN 4 ALUMNOS DE PRUEBA */
        x.codcarrera=10;
        x.legajo=190263;
        strcpy(x.apellido,"HERRERA");
        strcpy(x.nombre,"FLORENCIA");
        strcpy(x.dni,"35678321");

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
    if (f=fopen("archivoalumnos.data","r"))
    {
        fread(&r,sizeof(Alumno),1,f);
        while (!feof(f))
        {
            ListaAlumnoInsertarSiguiente(lAlumnos,r);
            fread(&r,sizeof(Alumno),1,f);
        }
        fclose(f);
    }
    ListaAlumnoListar(lAlumnos);
    ListaAlumnoborrarLista(lAlumnos);
    char c = getch();
    return 0;
}

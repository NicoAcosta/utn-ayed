#ifndef LISTAALUMNOS_H_INCLUDED
#define LISTAALUMNOS_H_INCLUDED

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

void ListaAlumnoInsertarSiguiente (NodoListaSEAlumno  *&n, Alumno x);
void ListaAlumnoBorrarSiguiente(NodoListaSEAlumno  *n);
NodoListaSEAlumno *ListaAlumnoObtenerSiguiente(NodoListaSEAlumno  *n);
NodoListaSEAlumno *ObtenerUltimoAlumno(NodoListaSEAlumno * p);
NodoListaSEAlumno* BuscarAlumnoPorDNI(NodoListaSEAlumno * raiz, char dnibuscado[]);
NodoListaSEAlumno* ListaAlumnoBuscarNodoAnterior(NodoListaSEAlumno * raiz, NodoListaSEAlumno * anterior_a);
void borrarNodoAlumno(NodoListaSEAlumno *& raiz, NodoListaSEAlumno * aborrar);
void ListaAlumnoborrarLista(NodoListaSEAlumno *&lista);
void ListaAlumnoListar(NodoListaSEAlumno *lista);


#endif // LISTAALUMNOS_H_INCLUDED

#ifndef LISTAMATERIAS_H_INCLUDED
#define LISTAMATERIAS_H_INCLUDED
struct Materia
{
    char nombreMateria[50];
    char fechaAprobacion[11];
    int legajo;
    int nota;
    int libro;
    int folio;
};

struct NodoListaSEMateria
{
    Materia info;             // Datos de el nodo
    NodoListaSEMateria*sgte;  // Puntero al siguiente nodo

};

void ListaMateriaInsertarSiguiente (NodoListaSEMateria  *&n, Materia x);
void ListaMateriaBorrarSiguiente(NodoListaSEMateria  *n);
NodoListaSEMateria *ListaMateriaObtenerSiguiente(NodoListaSEMateria  *n);
NodoListaSEMateria *ObtenerUltimoMateria(NodoListaSEMateria * p);
NodoListaSEMateria* ListaMateriaBuscarNodoAnterior(NodoListaSEMateria * raiz, NodoListaSEMateria * anterior_a);
void borrarNodoMateria(NodoListaSEMateria *& raiz, NodoListaSEMateria * aborrar);
void ListaMateriasInsertarAlFinal(NodoListaSEMateria *&lista, Materia x);
void ListaMateriaborrarLista(NodoListaSEMateria *&lista);
void ListaMateriaListar(NodoListaSEMateria *lista);




#endif // LISTAMATERIAS_H_INCLUDED

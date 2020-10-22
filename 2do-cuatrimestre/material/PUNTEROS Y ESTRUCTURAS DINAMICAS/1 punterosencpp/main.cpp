#include <iostream>
#include <conio.h>
using namespace std;
struct alumno
{
    char nombre[20];
    char apellido[20];
    int edad;
};
int main()
{
    /*Declaraciones*/
    int n;
    /* vamos a declarar una referencia a una variable, estas deben ser inicializadas en el momento */
    int& x = n;
    /* El siguiente es un puntero a un entero: */
    int *p;
    n= 2;
    cout << "n: " << n << " x: " << x << endl;
    cout << "Direccion de memoria de n: " << &n << endl;
    cout << "Direccion de memoria de x: " << &x << endl;
    getch();
    /* Por defecto los punteros deben inicializarse en nulo, o cero en el caso de c++ */
    p = NULL;
    /* El puntero puede guardar una dirección de memoria, por lo tanto la siguiente sentencia es válida: */
    p = &n;
    cout << "Un puntero pesa " << sizeof(int *) << " bytes" << endl;
    cout << "Lo apuntado por p es *p: " << *p << " y lo que tiene adentro p es: " << p << endl;
    cout << "La direccion de p (es decir &p) es: " << &p << endl;
    getch();
    /* Puntero a puntero */
    int **pp;
    pp= &p;
    cout << "Lo apuntado por pp es *pp: " << *pp << " lo apuntado por lo apuntado por pp es **pp: " << **pp << endl;
    cout << "La dirección de pp es (&pp):" << &pp << endl;
    /* creación de espacio en el heap (memoria dinámica)*/
    p = new int();
    *p = 27;
    cout << "p =" << p << "(en el heap), *p =" << *p << endl;
    delete p;
    cout << "Despues de hacer delete de p = " << p << " y *p= " << *p << endl;
    p= NULL;
    /* Aritmética de punteros, acceder a un array con punteros */
    int vector[10] = {21,43,543,2,123,782,128,64,91,196};
    p = vector;
    cout << "El vector (imprimiendo vector) es:" << vector  << endl;
    cout << "El vector (imprimiendo p) es:" << p  << endl;
    cout << "Ahora, lo apuntado por p es *p: " << *p << " y lo que tiene adentro p es: " << p << endl;
    cout << "p=" << p << "       *p=" << *p << endl;
    cout << "p+1=" << p+1 << "       *(p+1)=" << *(p+1) << endl;
    cout << "p+2=" << p+2 << "       *(p+2)=" << *(p+2) << endl;
    cout << "p+3=" << p+3 << "       *(p+3)=" << *(p+3) << endl;
    cout << "p+4=" << p+4 << "       *(p+4)=" << *(p+4) << endl;
    cout << "p+5=" << p+5 << "       *(p+5)=" << *(p+5) << endl;
    cout << "p+6=" << p+6 << "       *(p+6)=" << *(p+6) << endl;
    cout << "La direccion del elemento 5 del vector es: " << &(vector[5]) << endl;
    cout << "En la posicion 5 del vector está el elemento: " << *(p+5) << endl;
    /* asignación dinámica de memoria */
    alumno *ptr_alumno;
    int cant_alumnos;
    cout << "Cuántos alumnos tiene su curso?: " << endl;
    cin >> cant_alumnos;
    ptr_alumno= new alumno[cant_alumnos];
    cout << "New me devolvio la direccion: " << ptr_alumno << endl;
    for (int i=0; i< cant_alumnos;i++)
    {
        cout << "Ingrese nombre " << endl;
        cin >> ptr_alumno[i].nombre ;
        cout << "Ingrese apellido" << endl;
        cin >> ptr_alumno[i].apellido;
        cout << "Ingrese edad " << endl;
        cin >> ptr_alumno[i].edad ;
    }
    cout << "Listado utilizando notacion clasica (  (*(ptr_alumno+i)).nombre_atributo ):" << endl;
    for (int i=0; i< cant_alumnos;i++)
    {
        cout << "***************" << endl << endl;
        cout << (*(ptr_alumno+i)).nombre << endl;
        cout << (*(ptr_alumno+i)).apellido << endl;
        cout << (*(ptr_alumno+i)).edad << endl;
    }
    cout << "Listado utilizando notacion mejorada (  (ptr_alumno+i)->nombre_atributo ):" << endl;
    for (int i=0; i< cant_alumnos;i++)
    {
        cout << "***************" << endl << endl;
        cout << (ptr_alumno+i) -> nombre << endl;
        cout << (ptr_alumno+i) -> apellido << endl;
        cout << (ptr_alumno+i) -> edad << endl;
    }
    cout << "Listado utilizando accediendo a lo apuntado indexando (arit. de punteros)" << endl;
    for (int i=0; i< cant_alumnos;i++)
    {
        cout << "***************" << endl << endl;
        cout << ptr_alumno[i].nombre << endl;
        cout << ptr_alumno[i].apellido << endl;
        cout << ptr_alumno[i].edad << endl;
    }
    delete [] ptr_alumno;
    return 0;
}

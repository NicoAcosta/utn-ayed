#include <iostream>
#include <conio.h>
using namespace std;

/*
asignaValor: Asgina un valor al espacio en memoria apuntado por x
Precondición: x debe estar apuntando a un espacio en memoria válido
PostCOndición: El valor de *x es alterado, el valor de x no.
*/
void asignaValor(int *x)
{
    *x= 5;
}

/*
reservaMemYAsignaValor: Crea un espacio en memoria para su puntero parmámetro y
le asigna un valor
Precondición: no hay
PostCOndición: El valor de *x es alterado, el valor de x también.
*/
void reservaMemYAsignaValor(int *&x)
{
    x= new int();
    *x= 5;
}

/**** FUNCIONES PARA PRUEBA DE COMPORTAMIENTO ****/
/* Qué pasa si pasamos un puntero por referencia y lo
hacemos a puntar a una variable local de un subprograma?*/
void apuntaaLocal(int *&x)
{
    int i;
    cout << "La dir. de la local i es: " << &i << endl;
    x= &i;
    *x= 5;
}

void otrafuncion(int z)
{
    int v,m,n;
    cout << "La dir. de la local v es: " << &v << endl;
    cout << "La dir. de la local m es: " << &m << endl;
    cout << "La dir. de la local n es: " << &n << endl;
    cout << "La dir. de la local z es: " << &z << endl;
    v=12;
    m=13;
    n=14;
}
/**************************************************/

int main()
{
    int y;
    int *ptr=NULL;
    cout << "Dir de y: " << &y << endl;
    cout << "Dir de ptr: " << &ptr << endl;
    /* La siguiente sería una invocación inválida, ya que *ptr
    no tiene espacio reservado en memoria para guardar un valor*/
    //asignaValor(ptr);
    /*** Invocación correcta a asignaValor: ***/
    //NOTAR: No hace falta pasar el puntero por referencia para
    //modificar lo apuntado
    ptr= new int();
    cout << "Se reservó memoria en: " << ptr << endl;
    asignaValor(ptr);
    cout << *ptr << endl;
    delete ptr;
    getch();
    //Luego de hacer delete es conveniente asignar NULL
    //ptr = NULL;
    cout << "Se libera ptr" << endl;
    cout << "ptr = " << ptr << endl;
    cout << "*ptr = " << *ptr << endl;
    getch();
    /******************************************/
    /*** Otra ASIGNACION correcta: ***/
    ptr = &y;
    asignaValor(ptr);
    cout << "Lo apuntado por ptr es: "<< *ptr << endl;
    cout << "*ptr = y = "<< y << endl;
    ptr= NULL;/*No se hace delete para liberar,apuntaaLocal(ptr);
    ya que la memoria no ha sido asociada dinámicamente*/
    /******************************************/

    getch();
    reservaMemYAsignaValor(ptr);
    cout << "Luego de reservaMemYAsignavalor(ptr), ptr = " << ptr << " *ptr = " << *ptr << endl;
    delete ptr;
    /******************************************/
    getch();//Pruebas de comportamiento errático, qué está sucediento?
    apuntaaLocal(ptr);
    cout << "*ptr:" << *ptr << endl;
    otrafuncion(84);
    cout << "*ptr:" << *ptr << endl;
    getch();
    return 0;
}

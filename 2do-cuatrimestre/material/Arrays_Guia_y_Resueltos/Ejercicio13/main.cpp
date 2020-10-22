#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define LONG 5
#define VACIO -1
using namespace std;



struct Empleado
{
    long DNI=VACIO;
    string nombre;
    char estadocivil; //S: soltero/a, C:Casado/a, V:Viudo/a
    char sexo; //M: masc, F:Fem
    string direccion;
    string telefono;
    int edad;
}



typedef  Empleado mi_tdato;

void mostrarEmpleado(mi_tdato e)
{
    if (e.DNI != VACIO)
    {
        cout << endl << "***Datos del EMPLEADO***" << endl;
        cout << "DNI:" << e.DNI<< endl;
        cout << "nombre:" << e.nombre << endl;
        cout << "Sexo:" << e.sexo << endl;
        cout << "Edad:" << e.edad<< endl;
        cout << "Estado civil:" << e.estadocivil << endl;
        cout << "Direccion:" << e.direccion<< endl;
    }
    return;
}


mi_tdato leerEmpleado(mi_tdato &e)
{
    cout << "Ingrese DNI" << endl;
    cin >> e.DNI;
    cout << "Ingrese nombre" << endl;
    cin >> e.nombre;
    cout << "Ingrese sexo M/F" << endl;
    cin >> e.sexo;
    cout << "Ingrese edad" << endl;
    cin >> e.edad;
    cout << "Ingrese direccion" << endl;
    cin >> e.direccion;
    cout << "Ingrese telefono" << endl;
    cin >> e.telefono;
    cout << "Ingrese estado civil C: casado/a, S: soltero/a y V: Viudo/a." << endl;
    cin >> e.estadocivil;
    return e;
}


void inicializar(mi_tdato v[])
{
    for (int i = 0; i < LONG; i++)
    {
            v[i].DNI = VACIO;
    }
    return;
}


void mostrar(const mi_tdato v[])
{
    int i = 0;
    while (( i < LONG ) && (v[i].DNI != VACIO))
    {
        mostrarEmpleado(v[i]);
        i++;
    }
    return;
}



int insertar(mi_tdato dato, mi_tdato v[])
{
    int i = 0;
    int error=0;
    while (i< LONG && v[i].DNI!=VACIO)
        i++;
    if (i < LONG)
    {
        v[i] = dato;
    }

    else
        error = 1;
    return error;
}

int cantElementos(const mi_tdato vec[])
{
    int i = 0;
    while ( i < LONG && vec[i].DNI!= VACIO)
        i++;
    return i;

}


/*Ordenamiento por burbujeo mejorado, ordena según el año de ingreso
*/
void burbuja(mi_tdato v[])
{
    mi_tdato aux;
    int j = 0;
    for (int i = 0; i < LONG - 1; i++)
    {
        j=0;
       while (v[j+1].DNI != -1 && j < LONG - 1 - i)
       {
           if (v[j+1].nombre < v[j].nombre)
           {
               aux = v[j];
               v[j] = v[j+1];
               v[j+1] = aux;
           }
           j++;
       }
    }
}
void burbujaXDNI(mi_tdato v[])
{
    mi_tdato aux;
    int j = 0;
    for (int i = 0; i < LONG - 1; i++)
    {
        j=0;
       while (v[j+1].DNI != -1 && j < LONG - 1 - i)
       {
           if (v[j+1].DNI < v[j].DNI)
           {
               aux = v[j];
               v[j] = v[j+1];
               v[j+1] = aux;
           }
           j++;
       }
    }
}

int busquedaBinaria(const mi_tdato vec[], int DNIbuscado)
{
  bool encontrado = false;
  int Iarriba = cantElementos(vec)-1;
  int Iabajo = 0;
  int Icentro;
  int result = -1;
  while (Iabajo <= Iarriba && !encontrado)
  {
      Icentro = (Iarriba + Iabajo)/2;
      if (vec[Icentro].DNI == DNIbuscado)
      {
          result= Icentro;
          encontrado= true;
      }
      else
      {
        if (DNIbuscado < vec[Icentro].DNI)
            Iarriba=Icentro-1;
        else
            Iabajo=Icentro+1;
      }
  }
  return result; // si no encontrado devuelve -1
}


void mostrarmenu()
{
    cout << "Ingrese una opción:" << endl;
    cout << "a - Ingresar un valor" << endl;
    cout << "b - Mostrar proximos a jubilarse ordenados alfab." << endl;
    cout << "c - Edad promedio de los empleados" << endl;
    cout << "d - Todos los datos de un empleado" << endl;
    cout << "Esc - Salir" << endl;
}

int main()
{
    int i =0;
    int cont =0;
    float sumedades;
    mi_tdato vec[LONG];
    mi_tdato dato;
    inicializar(vec);
    char opcion;
    do
    {
        mostrarmenu();
        do
        {
                opcion=getch();
        } while (opcion!=27 &&
                 !(opcion>='A' && opcion<='D') &&
                 !(opcion>='a' && opcion<='d')
                 );
        switch (opcion)
        {
            case 'a':
            case 'A':
                    cout << "Ingrese los datos del empleado" << endl;
                    leerEmpleado(dato);
                    if (insertar(dato, vec)!= 0)
                        cout << "Error al intentar ingresar el dato. Vector lleno" << endl;
                    else
                        cout << "Dato ingresado correctamnte" << endl;
                break;
            case 'b':
            case 'B':
                    burbuja(vec);
                    i =0;
                    while(i < LONG && vec[i].DNI!=VACIO)
                    {
                        if ((vec[i].sexo=='F' && vec[i].edad==59) || (vec[i].sexo=='M' && vec[i].edad==64))
                            cout << vec[i].nombre << ", " << vec[i].DNI << "." << endl;
                        i++;
                    }
                break;
            case 'c':
            case 'C':
                    sumedades =0;
                    cont=0;
                    while(cont < LONG && vec[cont].DNI!=VACIO)
                    {
                        sumedades += vec[cont].edad;
                        cont++;
                    }

                    if (cont>0)
                        cout << "El promedio de edad es: " << sumedades/cont << endl;
                    else
                        cout << "No hay empleados cargados" << endl;
                    getch();
                break;
            case 'd':
            case 'D':
                    int dnibuscado;
                    cout << "Ingrese el DNI del empleado a buscar: " << endl;
                    cin >> dnibuscado;
                    int posicion;
                    burbujaXDNI(vec);
                    posicion = busquedaBinaria(vec, dnibuscado);
                    if (posicion != -1)
                        mostrarEmpleado(vec[posicion]);
                    else
                        cout << "No se encuentra el elemento." << endl;
                break;
        }
        cout << "Presione una tecla para continuar" << endl;
        getch();
        system("cls");

    } while ((int)opcion != 27); //27 es el código ascii de la tecla Esc. Tengo que convertirlo a int para obtener su código en tabla
    return 0;
}

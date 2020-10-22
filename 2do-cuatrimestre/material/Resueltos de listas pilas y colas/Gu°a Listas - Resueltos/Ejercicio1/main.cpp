/* LISTAS SE */

#include <iostream>
#include <conio.h>
using namespace std;


struct NodoListaSE
{
    int info;             // Datos de el nodo
    NodoListaSE   *sgte;  // Puntero al siguiente nodo

};

void InsertarSiguiente (NodoListaSE  *&n, int x)
{
    NodoListaSE *nuevo= new NodoListaSE();
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


NodoListaSE *ObtenerUltimo(NodoListaSE * p)
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

void InsertarAlFinal (NodoListaSE  *&n, int x)
{
    NodoListaSE *nuevo= new NodoListaSE();
    NodoListaSE *ultimo= NULL;
    nuevo->info=x;
    nuevo->sgte= NULL;
	if (n!=NULL)
    {

        ultimo = ObtenerUltimo(n);
        ultimo->sgte = nuevo;
    }
    else
    {
        n= nuevo;
    }
    return;
}


void BorrarSiguiente(NodoListaSE  *n)
{
    NodoListaSE  *aborrar = n->sgte;
    NodoListaSE  *sgteaborrar;
    if (aborrar)
        sgteaborrar= aborrar->sgte;
    else
        sgteaborrar = NULL;
    n->sgte = sgteaborrar;
    delete aborrar;
    return;
}

NodoListaSE *ObtenerSiguiente(NodoListaSE  *n)
{
    if (n)
        return n->sgte;
    else
        return NULL;
}

NodoListaSE* BuscarNodo(NodoListaSE * raiz, int infobuscada)
{
    NodoListaSE *p=raiz;
    while (p && (p->info != infobuscada))
    {
        p = p->sgte;
    }
    return p;
}


NodoListaSE* BuscarNodoAnterior(NodoListaSE * raiz, NodoListaSE * anterior_a)
{
    NodoListaSE *p =NULL;
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
void borrarNodo(NodoListaSE *& raiz, NodoListaSE * aborrar)
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
            NodoListaSE *x = BuscarNodoAnterior(raiz,aborrar);
            BorrarSiguiente(x);
        }
    }
    return;
}

void MostrarLista(NodoListaSE *lista)
{
    while (lista)
    {
        cout << lista->info << " | ";
        lista = ObtenerSiguiente(lista);
    }
    cout << endl;
}
/******* SUBPROGRAMAS ESPECIFICOS PARA ESTE EJERCICIO: ********/
void InsertarPrimero(NodoListaSE *&lista, int elemento)
{
    NodoListaSE *nuevo = new NodoListaSE();
    NodoListaSE *aux = lista;
    nuevo->info=elemento;
    lista= nuevo;
    nuevo->sgte= aux;
    return;
}

void InsertarOrdenado(NodoListaSE *&lista, int elemento)
{
    NodoListaSE *anterior= NULL;
	NodoListaSE *aux = lista;
    while (aux && aux->info< elemento)
        aux = aux->sgte;
    if (aux && aux!=lista)
    {
            anterior = BuscarNodoAnterior(lista,aux);
            InsertarSiguiente(anterior,elemento);
    }
    else
    {
       /*Si aux==NULL entonces el elemnto a insertar es el mayor */
       if (aux==NULL)
            InsertarAlFinal(lista,elemento);
       else if (aux==lista)
            InsertarPrimero(lista,elemento);

    }
    return;
}


char mostrarmenu()
{
    cout << "Ingrese una opcion: " << endl;
    cout << "1 - Ingresar un nuevo elemento" << endl;
    cout << "2 - Mostrar lista" << endl;
    cout << "3 - Buscar mayor" << endl;
    cout << "4 - Calcular promedio" << endl;
    cout << "esc - Salir" << endl;
    char opcion;
    do
    {
       opcion=getch();
    } while ((opcion!='1') && (opcion!='2') && (opcion!='3') && (opcion!='4') && (opcion!=27));
    return opcion;
}

int main()
{

    NodoListaSE *listaOrdenada =NULL;
    NodoListaSE *aux = NULL;
    char elegida;
    int num;
    do
    {
        elegida= mostrarmenu();
        switch (elegida)
        {
            case '1':
                    cout << "Ingrese un nro" << endl;
                    cin>> num;
                    InsertarOrdenado(listaOrdenada,num);
            break;
            case '2':
                MostrarLista(listaOrdenada);
            break;
            case '3':
                    aux= listaOrdenada;
                    while (aux && aux->sgte)
                        aux= ObtenerSiguiente(aux);
                    if (aux)
                        cout << "El mayor es: " << aux->info <<endl;
                    else
                        cout << "Lista vacía" << endl;
            break;
            case '4':
                float sum =0, cont=0;
                aux= listaOrdenada;
                if (!aux)
                    cout << "La lista está vacía" << endl;
                else
                {
                    while (aux)
                    {
                        sum+= aux->info;
                        cont++;
                        aux= ObtenerSiguiente(aux);
                    }
                    cout << "Promedio es " << sum/cont<< endl;
                }

            break;
        }
        getch();
    } while (elegida!=27);

    return 0;
}

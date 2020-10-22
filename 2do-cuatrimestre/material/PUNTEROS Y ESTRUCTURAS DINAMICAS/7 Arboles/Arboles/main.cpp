#include <iostream>

using namespace std;

struct NodoArbol
{
    int info;
    NodoArbol *izq;
    NodoArbol *der;
};

void insertar(NodoArbol *&raiz, int dato)
{
    if (raiz==NULL)
    {
        raiz = new NodoArbol();
        raiz->info= dato;
        raiz->izq= NULL;
        raiz->der= NULL;
    }
    else
    {
        if (dato < raiz->info)
            insertar(raiz->izq,dato);
        else
            insertar(raiz->der,dato);
    }
    return;
}

void visitar(NodoArbol *ptr)
{
    cout << ptr->info << endl;
    return;
}

void preorden(NodoArbol *ptr)
{
    if (ptr)
    {
        visitar(ptr);
        preorden(ptr->izq);
        preorden(ptr->der);
    }
    return;
}

void preordeninverso(NodoArbol *ptr)
{
    if (ptr)
    {
        visitar(ptr);
        preordeninverso(ptr->der);
        preordeninverso(ptr->izq);
    }
    return;
}

void postorden(NodoArbol *ptr)
{
    if (ptr)
    {
        postorden(ptr->izq);
        postorden(ptr->der);
        visitar(ptr);
    }
    return;
}
void postordeninverso(NodoArbol *ptr)
{
    if (ptr)
    {
        postordeninverso(ptr->der);
        postordeninverso(ptr->izq);
        visitar(ptr);
    }
    return;
}

void enorden(NodoArbol *ptr)
{
    if (ptr)
    {
        enorden(ptr->izq);
        visitar(ptr);
        enorden(ptr->der);
    }
    return;

}


void enordeninverso(NodoArbol *ptr)
{
    if (ptr)
    {
        enordeninverso(ptr->der);
        visitar(ptr);
        enordeninverso(ptr->izq);
    }
    return;

}

int main()
{
    NodoArbol *raiz = NULL;
    insertar(raiz,6);
    insertar(raiz,3);
    insertar(raiz,5);
    insertar(raiz,2);
    insertar(raiz,10);
    insertar(raiz,8);
    insertar(raiz,14);
    cout << "************* PREORDEN **********" << endl;
    preorden(raiz);
    cout << "************* PREORDEN INVERSO **********" << endl;
    preordeninverso(raiz);
    cout << "************* POSTORDEN **********" << endl;
    postorden(raiz);
    cout << "************* POSTORDENINVERSO **********" << endl;
    postordeninverso(raiz);
    cout << "************* ENORDEN **********" << endl;
    enorden(raiz);
    cout << "************* ENORDENINVERSO **********" << endl;
    enordeninverso(raiz);
    return 0;
}

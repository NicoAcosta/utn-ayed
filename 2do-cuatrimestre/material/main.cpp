#include <iostream>

using namespace std;

bool cargarelementos(float mi_vec[], int tam, int pos, float elemento)
{
    if (pos >= tam)
        return false;
    mi_vec[pos] = elemento;
    return true;
    
}

void mostrarelementos(float v[], int tam)
{
    for (int i = 0; i<10; i++)
        cout << "v[" << i << "]= " << v[i] << endl;
    return;
}

int buscarelemento(float v[], int tam, float e)
{
    for (int i = 0; i<10; i++)
     {
            if (v[i]==e)
                return i;
         
     }
    return -1;
 
    
}

void burbuja(float v[], int tam)
{
    float aux;
    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = 0; j < tam - 1 - i; j++)
        {
            if (v[j+1] < v[j])
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
    return;
}

int main(int argc, const char * argv[]) {
    float v[10],e;
    int pos;
    for (int i = 0; i<10; i++)
    {
        cout << "v[" << i << "]= ";
        cin >> e;
        if (!cargarelementos(v, 10, i, e))
            cout << "Error!";
        cout << endl;
    }
    mostrarelementos(v, 10);
    cout << "Buscamos elemento:" << endl;
    pos = buscarelemento(v, 10, 72);
    if (pos == -1)
        cout << "No se encuentra el elemento." << endl;
    else
        cout << "El elemento está en la posición: " << pos << endl;
    cout << endl << endl;
    cout << "Ordenamiento..." << endl;
    burbuja(v, 10);
    mostrarelementos(v, 10);
    
    return 0;
}

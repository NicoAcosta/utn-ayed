#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>
using namespace std;

int main()
{
    int cantidad;
    //colores: cadena de caracteres donde iremos guardando r, n o v de cada tiro, separando cada tiro por un .
    //numeros: cadena de caracteres donde guardaremos el numero que haya salido en cada tiro, 0 a 36
    string colores="", numeros="";
    string color="", numero="";

    /*********** LECTURA DE DATOS ***************/
    cout << "Ingrese la cantidad de tiros de la ruleta" << endl;
    cin >> cantidad;
    for (int i=1;i<=cantidad;i++)
    {
        cout << "Ingrese los valores del juego (r=rojo, n=negro, si sale cero el color es v=verde): " << endl;
        cout << "Color: ";
        cin >> color;
        cout << "Num: ";
        cin >> numero;
        cout << endl;
        colores +=  color + ".";
        numeros += numero + ".";
    }
    /* Agregamos la marca de fin de cadena */
    colores += '\0';
    numeros += '\0';
    /* Lectura tiro por tiro */
    int contnum=0, contcolor=0;
    int contcero=0, contrepitenegro=0, contrepitenum=0, maxrepitenum=0, contalternado=0, maxalternado=0,
    contniegasegunda, maxniegasegunda=0;
    int int_numleido;
    string anteriores_cero = "";
    bool senegosegunda=false;
    /*Variables colorleído y númeroleído que utilizaremos para ir recorriendo todos los leídos de a un tiro por vez,
    se podría utilizar las mismas que se usaron para la lectura */
    char colorleido, coloranterior;
    string numeroleido="", numanterior="", nummax="";
    colorleido= colores[contcolor];
    /* Mientras encuentre un color, busca el número y
    analiza la jugada, sino fin de lectura.
    es más facil leer el color para saber si hay un tiro ya
    que es un sólo caracter, el número puede ser 1 o 2
    caracteres */
    while (colorleido!='\0')
    {
        numeroleido= numeros[contnum];
        contnum++;
        //Se fija si el número es de dos caracteres:
        if (numeros[contnum]!='.')
        {
            numeroleido+=numeros[contnum];
            contnum++;
        }
        contnum++;
        //Veces que salio cero y por cada vez su número anterior
        if (numeroleido=="0")
        {
            contcero++;
            if (numanterior.length()>0)
                anteriores_cero+= numanterior + ", ";
        }
        //Cuantas veces llego a repetirse el color negro
        if (colorleido=='n' && coloranterior=='n')
                contrepitenegro++;
        //max cant veces se repitio un num y cual fue
        if (numanterior==numeroleido)
        {
            contrepitenum++;
            if (contrepitenum>maxrepitenum)
            {
                maxrepitenum= contrepitenum;
                nummax= numeroleido;
            }
        }
        else
            contrepitenum=0;
        //max cant veces alternados negro y rojo
        if ((coloranterior=='n' && colorleido=='r') || (coloranterior=='r' && colorleido=='n'))
        {
            contalternado++;
            if (contalternado>maxalternado)
            {
                maxalternado=contalternado;
            }
        }
        else
            contalternado=0;

        //int_numleido= stoi(numeroleido); las funciones  de conversion no funcionan en el compilador MinGW
        int_numleido=  atoi(numeroleido.c_str());
        if (int_numleido <= 12 || int_numleido > 24)
        {
            if (senegosegunda==true)
            {
                contniegasegunda++;
                if (contniegasegunda>maxniegasegunda)
                    maxniegasegunda= contniegasegunda;
            }
            else
            {
                senegosegunda=true; //Para la primera vez que se niega
                contniegasegunda=1;
            }

        }
        else
        {
            senegosegunda=false;
            contniegasegunda=0;
        }

        //cout << colorleido << endl;
        //cout << numeroleido << endl;
        numanterior= numeroleido;
        coloranterior= colorleido;
        contcolor+=2;
        colorleido= colores[contcolor];

    }
    cout << "1. El cero salio " << contcero << " y los numeros anteriores fueron " << anteriores_cero << endl;
    cout << "2. El color negro se repitio " << contrepitenegro << endl;
    cout << "3. El número que se repitió más veces seguidas fue el " << nummax << " se repitio " << maxrepitenum << endl;
    cout << "4. Mayor cantidad de veces que se alternaron rojo y negro " << maxalternado << endl;
    cout << "5. Mayor cantidad de veces seguidas que se nego la segunda docena " << maxniegasegunda << endl;
    getch();
    return 0;
}

#include <iostream>

using namespace std;

int nuevaHora(int hora, int tiempo)
{
    int result = 0;
    int hh = hora / 10000;
    int mm = (hora / 100) % 100;
    int ss = hora % 100;
    int th = tiempo / 10000;
    int tm = (tiempo / 100) % 100;
    int ts = tiempo % 100;
    /*
    cout << "Nuevos sgundos: " << (ss + ts) % 60 << endl;
    cout << "Nuevos minutos: " << ((mm + tm + (ss + ts) / 60  ) % 60 ) << endl;
    cout << "Nueva hora: " << (((hh + th) + (mm + tm + (ss + ts) / 60  ) / 60 ) % 24) << endl;
    */
    result =
        (ss + ts) % 60  +
        ((mm + tm + (ss + ts) / 60  ) % 60 ) * 100+
        (((hh + th) + (mm + tm + (ss + ts) / 60  ) / 60 ) % 24) * 10000;
    return result;
}

int main()
{
    cout.width(6);
    cout.fill('0');
    cout.left;
    cout <<   nuevaHora(235534,000530);

    return 0;
}

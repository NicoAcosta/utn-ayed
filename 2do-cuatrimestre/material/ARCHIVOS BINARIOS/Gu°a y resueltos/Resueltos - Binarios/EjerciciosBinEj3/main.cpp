#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    FILE *f1;
    FILE *f2;
    /* Creamos datros de prueba en el archivo */
    f1 = fopen("arch1.data","wb");
    int v[] = {2,5,64,20,31};
    fwrite(v, sizeof(int),5,f1);
    fclose(f1);
    f2 = fopen("arch2.data","wb");
    int w[] = {12,3,7};
    fwrite(w, sizeof(int),3,f2);
    fclose(f2);
    /* Comienza el algoritmo */
    FILE *output;
    f1 = fopen("arch1.data","rb");
    f2 = fopen("arch2.data","rb");
    output = fopen("out.data","wb");
    int x1,x2;
    while(fread(&x1,sizeof(int),1,f1) && fread(&x2,sizeof(int),1,f2))
    {
        fwrite(&x1,sizeof(int),1,output);
        fwrite(&x2,sizeof(int),1,output);
    }
    while (!feof(f1))
    {
        fwrite(&x1,sizeof(int),1,output);
        fread(&x1,sizeof(int),1,f1);
    }

    while (!feof(f2))
    {
        fwrite(&x2,sizeof(int),1,output);
        fread(&x2,sizeof(int),1,f2);
    }
    fclose(f1);
    fclose(f2);
    fclose(output);
    /*corroboramos */
    f1= fopen("out.data","rb");
    while (fread(&x1,sizeof(int),1,f1))
    {
        cout << x1 << endl;
    }
    fclose(f1);
    return 0;
}

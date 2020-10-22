#include <iostream>
#include <stdio.h>

using namespace std;

void apareo(char namefile1[], char namefile2[], char namefileout[])
{
    FILE *f1,*f2,*output;
    f1 = fopen(namefile1,"rb");
    f2 = fopen(namefile2,"rb");
    output = fopen(namefileout,"wb");
    int x1,x2;
        /* Comienza el algoritmo */
    while(fread(&x1,sizeof(int),1,f1) && fread(&x2,sizeof(int),1,f2))
    {
        if (x1 < x2)
        {
            fwrite(&x1,sizeof(int),1,output);
            fseek(f2,(-1)*sizeof(int),SEEK_CUR);
        }
        else
        {
            fwrite(&x2,sizeof(int),1,output);
            fseek(f1,(-1)*sizeof(int),SEEK_CUR);
        }
    }
    if (!feof(f1))
    {
        while (fread(&x1,sizeof(int),1,f1))
        {
            fwrite(&x1,sizeof(int),1,output);
        }

    }

    if (!feof(f2))
    {
        while (fread(&x2,sizeof(int),1,f2))
        {
            fwrite(&x2,sizeof(int),1,output);
        }

    }
    fclose(f1);
    fclose(f2);
    fclose(output);
    return;
}

int main()
{
    FILE *f1;
    FILE *f2;
    int x1,x2;
    /* Creamos datros de prueba en el archivo */
    int v[] = {18,27,81,264};
    int w[] = {5,7,62,420,500};
    f1 = fopen("arch1.data","wb");
    fwrite(v, sizeof(int),4,f2);
    fclose(f1);
    f2 = fopen("arch2.data","wb");
    fwrite(w, sizeof(int),5,f1);
    fclose(f2);
    apareo("arch1.data","arch2.data","output.data");
    /*corroboramos */
    f1= fopen("output.data","rb");
    while (fread(&x1,sizeof(int),1,f1))
    {
        cout << x1 << endl;
    }
    fclose(f1);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

int abrir_archivo(FILE **fp, char *modo, char *ruta, int msg)
{
    *fp = fopen( ruta, modo);
    if( *fp == NULL)
    {
        fprintf(stderr, "\n ** ERROR ** No existe el archivo \n");
        return 0;
    }//End_if

    return 1;
}//End_abri_archivo

int Recorrer_archivo(FILE *fp, int (*mostrar)(const t_empleado *, const unsigned int *))
{
    int i = 0;
    long posini = ftell(fp); //Guardo OFFSET
    t_empleado emp;

        rewind(fp);

        fread(&emp, sizeof(t_empleado), 1, fp);

        while(  !feof(fp))
        {
            i++;
            mostrar(&emp, &i);
            fread(&emp, sizeof(t_empleado), 1, fp);
        }//End_while

    fseek(fp, posini, SEEK_SET); //Restauro OFFSET

    return i;
}//End_func


// Apareamiento:
// 1 = Fusion. Une el universo completo de dos archivos con repetidos.
// De menor a mayor (ascendente)
// Devuelve la cantidad total de elementos copiados.
// AVISO: Usa funciones de la biblioteca "empleados.h"
int fusionar_archivos (FILE *fa, FILE *fb, FILE *fp)
{
    t_empleado empa,
               empb;

    int i = 0, // Contador total de registros en datos3
        flag = 0; // Corte de control para final de un archivo
    long set = 0; // Cual archivo grabo en datos3

        rewind(fa);
        rewind(fb);
        rewind(fp);

        while( !feof(fa) || !feof(fb))
        {

            if( (!feof(fa)) && set <= 0)
                fread(&empa, sizeof(t_empleado), 1, fa);

            if( (!feof(fb)) && set >= 0)
                fread(&empb, sizeof(t_empleado), 1 ,fb);


            if(!feof(fa) && !feof(fb))
                set = comparar_DNI(&empa, &empb);
            else
            {
                if(feof(fa)) //Si termino fa, seteo para que lea fb
                    set = 1;
                else
                    set = -1; //Inversa de la anterior
            }

            if( set < 0)
            {
                fwrite(&empa, sizeof(t_empleado), 1, fp);
                fseek(fp, 0L, SEEK_CUR);
                i++;
            }
            else
            {
                if(set > 0)
                {
                    fwrite(&empb, sizeof(t_empleado), 1, fp);
                    fseek(fp, 0L, SEEK_CUR);
                    i++;
                }
                else
                {
                    if (set == 0)
                    {
                        fwrite(&empa, sizeof(t_empleado), 1, fp);
                        fseek(fp, 0L, SEEK_CUR);

                        fwrite(&empb, sizeof(t_empleado), 1, fp);
                        fseek(fp, 0L, SEEK_CUR);

                        i += 2;
                    }
                }//End_else2
            }//End_else1
        }//End_while

    return i;
}//End_fusion



#include <stdio.h>
#include <stdlib.h>

#include "empleado.h"
#include "fecha.h"

#define TAM_LOTE_A 5
#define TAM_LOTE_B 7

/// DIRECCIONES.
#define file1 "C:\\Users\\leito\\Desktop\\Apareamiento\\file\\datos1.emp"
#define file2 "C:\\Users\\leito\\Desktop\\Apareamiento\\file\\datos2.emp"
#define file3 "C:\\Users\\leito\\Desktop\\Apareamiento\\file\\datos3.emp"


/// Genera lote de prueba para reseteo de archivos
void generar_lote_a()
{
    FILE *fp;
    const t_empleado empa[TAM_LOTE_A] = {
                          { 10000001,   "Leandro Vitale",   'M', {3,7,1989}, 9080.56  },
                          { 10000002,   "Mara Laura",       'F', {10,11,1989}, 10100.80 },
                          { 10000003,   "Alejandro Magno",  'M', {1,5,1980}, 22504.98 },
                          { 20000001,   "Graciela DaGorda", 'F', {22,04,1984}, 7500.98  },
                          { 20000002,   "Abel Pintos",      'M', {16,03,1999}, 13500.05 },
                         };
        fp = fopen (file1, "wb");
        fwrite( empa, sizeof(t_empleado), TAM_LOTE_A, fp);
        fclose(fp);

}//End_gen_a


void generar_lote_b()
{
    FILE *fp;
    const t_empleado empb[TAM_LOTE_B] = {
                          { 20000001,   "Graciela DaGorda", 'F', {22,04,1984}, 8500.98  },
                          { 20000002,   "Abel Pintos",      'M', {16,03,1999}, 12540.05 },
                          { 30000001,   "Roberta fefe",     'F', {25,7,2000}, 18654.56  },
                          { 30000002,   "Giuliano MsPobre", 'F', {31,10,1970}, 1200.80  },
                          { 30000003,   "Tina lala",        'M', {9,4,1955}, 80504.98   },
                          { 50000001,   "Inodoro Pereyra",  'M', {27,12,1999}, 6258.05  },
                          { 50000002,   "Gil La Gorda",     'M', {3,7,1989}, 10100.80   },
                         };

        fp = fopen (file2, "wb");
        fwrite( empb, sizeof(t_empleado), TAM_LOTE_A, fp);
        fclose(fp);

}//End_gen_b

void mostrar_empleadoU (const t_empleado *emp)
{
    printf(" \n** Mostrar empleado **************************\n");
    printf("Nombre: %s \n", emp->apyn);
    printf("DNI:    %ld \n", emp->DNI);
    printf("Sexo:   %c \n", emp->sexo);
    printf("Fecha:  %02d/%02d/%02d \n", emp->fec.di, emp->fec.me, emp->fec.an);
    printf("Sueldo: $%.2f \n", emp->sueldo);

    getch();
}//End_mostar_uno

// Para mostrar varios en fila
void mostrar_empleado (const t_empleado *emp, const int *i)
{
    printf(" \n Nro. %d ****************\n", *i);
    printf("Nombre: %s \n", emp->apyn);
    printf("DNI:    %ld \n", emp->DNI);
    printf("Sexo:   %c \n", emp->sexo);
    printf("Fecha:  %02d/%02d/%02d \n", emp->fec.di, emp->fec.me, emp->fec.an);
    printf("Sueldo: $%.2f \n", emp->sueldo);

}//End_mostrar_emp

void mostrar_resumen (const t_empleado *emp, const int *i)
{
    printf("%03d  %ld %s \n", *i, emp->DNI, emp->apyn);
}//End_resumen



/// FUNCIONES DE COMPARACION:
long comparar_DNI( const t_empleado *empa, const t_empleado *empb)
{
    return (empa->DNI - empb->DNI);
}//End_func

int comparar_NOMBRE( const t_empleado *empa, const t_empleado *empb)
{
     unsigned char *p1 = empa->apyn,
                   *p2 = empb->apyn;

        while( *p1 && (*p1 == p2))
        {
              p1++; p2++;
        }

        return (*p1 - *p2);
}//End_func

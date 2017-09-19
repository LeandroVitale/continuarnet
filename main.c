#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"

#define CON_MSG 1
#define SIN_MSG 0

#define file1 "D:\\aUNLAM\\Programacion\\AAProgra\\GUIA 1\\Apareamiento\\file\\datos1.emp"
#define file2 "D:\\aUNLAM\\Programacion\\AAProgra\\GUIA 1\\Apareamiento\\file\\datos2.emp"
#define file3 "D:\\aUNLAM\\Programacion\\AAProgra\\GUIA 1\\Apareamiento\\file\\datos3.emp"


/// 1 Aparear *******************************************************************************
void menu_aparear (FILE *fa, FILE *fb, FILE *fp)
{
    int opta = 0,
        i = 0;

        do
        {
            system("cls");
            printf(" : ARCHIVOS.v2 -> Apareamiento ********* \n");
            printf(" 1 - Fusion \n"
                   " 9 - Revisar archivo resultado \n"
                   " 0 - Salir \n"
                   "     Opcion: ");
            fflush(stdin);
            scanf("%d", &opta);

            switch(opta)
            {
                case 1:
                    i = fusionar_archivos( fa, fb, fp);
                    printf("\n ** Se han copiado %d elementos en datos3.emp \n", i);
                    getch();
                break; // Case 1

                case 9:
                   i = Recorrer_archivo(fp);
                   getch();
                break; // Case 2
            }//End_switch
        }while(opta != 0);
}//End_Menu_Aparear


/// 1 Recorrer *******************************************************************************
void menu_recorrer (FILE *fa, FILE *fb, FILE *fp)
{
    int opta = 0,
        i = 0;

        do
        {
            system("cls");
            printf(" : ARCHIVOS.v2 -> Recorrer ********* \n");
            printf(" 1 - Contenido datos 1 \n"
                   " 2 - Contenido archivo datos 2 \n"
                   " 3 - Contenido archivo datos 3 \n"
                   " 4 - Resumen archivo datos 3 \n"
                   " 0 - Salir \n"
                   "          Opcion: ");

            fflush(stdin);
            scanf("%d", &opta);

            switch(opta)
            {
                case 1:
                    i = Recorrer_archivo(fa, mostrar_empleado);
                    getch();
                break; // Case 1


                case 2:
                    i = Recorrer_archivo(fb, mostrar_empleado);
                    getch();
                break; // Case 2


                case 3:
                    i = Recorrer_archivo(fp, mostrar_empleado);
                    getch();
                break; // Case 3


                case 4:
                    printf("Nro  DNI      Nombre/s Apellido/s \n"
                           "===  ======== ======================= \n");
                    i = Recorrer_archivo(fp, mostrar_resumen);
                    getch();
                break; // Case 3

            }//End_switch
        }while(opta != 0);


}//End_menu_recorrer
///******************************************************************************************
int main()
{
    FILE *fa,
         *fb,
         *fp;

    int i = 0,
        opta = 0;

        printf(" : ARCHIVOS.v2 **************************** ");
        // Abrir archivo A, si falla reseteamos el lote
        i = abrir_archivo(&fa, "r+b", file1, CON_MSG);
        if (i == 0)
        {
            generar_lote_a();
            printf(" Archivo generado: Abriendo \n");
            abrir_archivo(&fa, "r+b", file1, CON_MSG);
        }//End_if

        // Abrir archivo B, si falla reseteamos el lote
        i = abrir_archivo(&fb, "r+b", file2, CON_MSG);
        if (i == 0)
        {
            generar_lote_b();
            printf(" Archivo generado: Abriendo \n");
            abrir_archivo(&fb, "r+b", file2, CON_MSG);
        }//End_if

        // Abrir archivo C, si no esta, creo uno en limpio
        i = abrir_archivo(&fp, "r+b", file3, CON_MSG);
        if (i == 0)
        {
            printf(" Generando arhivo resultado \n");

            abrir_archivo(&fp, "wb", file3, CON_MSG);
            fclose(fp);

            abrir_archivo(&fp, "r+b", file3, CON_MSG);

        }//End_if

       // i = Recorrer_archivo(fp);
       // getch();

       /// ******************** MENU ***************************

        do
        {
            system("cls");
            printf(" : ARCHIVOS.v2 -> Menu **************** \n");
            printf("1 - Apareamiento \n"
                   "9 - Ver archivos \n"
                   "0 - Salir \n"
                   "    Opcion: ");

            fflush(stdin);
            scanf("%d", &opta);

            // Menu ::::::::::::::
            switch(opta)
            {
                case 1:
                    menu_aparear( fa, fb, fp);

                break;

                case 9:
                    menu_recorrer(fa, fb, fp);
                break;
            }//End_switch
        }while(opta != 0);


        fclose(fa);
        fclose(fb);
        fclose(fp);
    return 0;
}

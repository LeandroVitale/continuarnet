#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"

#define EsBisiesto(x) ( (((x)%4 == 0 ) && ((x)%100 != 0 )) || ( (x)%400 == 0 ) ? 1:0 )

//Valida fecha: 0 = Fecha NO valida, 1 = Fecha valida
int Fecha_valida (t_fecha *fec)
{
    const static int ctrl[2][13] = { //   en  fe  mar ab  may jun jul ago sep oct nov dic
                                    { 0, 31, 28, 31, 30, 31, 31, 31, 31, 30, 31, 30, 31},
                                    { 0, 31, 29, 31, 30, 31, 31, 31, 31, 30, 31, 30, 31}
                                   };


        if( fec->an <= 0 ||
            fec->an >=2100 ||
            fec->me < 1 ||
            fec->me > 12 ||
            fec->di < 1 ||
            fec->di > ctrl[EsBisiesto(fec->an)][fec->me])
                return 0;
            else
                return 1;

}//End_func

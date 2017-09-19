#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#include "fecha.h"

typedef struct
{
    long  DNI;
    char  apyn[35],
          sexo;
    t_fecha  fec;
    float sueldo;
}t_empleado;

// Para comparar
long comparar_DNI (const t_empleado *empa, const t_empleado *empb);
int comparar_NOMBRE (const t_empleado *empa, const t_empleado *empb);

void mostrar_resumen(const t_empleado *empa, const int *i);
void mostrar_empleado(const t_empleado *emp, const int *i);
void mostrar_empleadoU (const t_empleado *emp);

#endif // EMPLEADO_H_INCLUDED

#include <stdio.h>
#include "general.h"
#include "operaciones.h"

int suma(float op1,float op2,float* rta){
    *rta = op1 + op2;
    return SIN_ERROR;
}
int resta(float op1,float op2,float* rta){
    *rta = op1 - op2;
    return SIN_ERROR;
}
int division(float op1,float op2,float* rta){
    if(op2 == 0){
        printf("division: ERROR: division por 0\nACASO QUIERES QUE EXPLOTE EL UNIVERSO?!\n");
        return ERROR;
    }
    *rta = op1 / op2;
    return SIN_ERROR;
}
int multiplicacion(float op1,float op2,float* rta){
    *rta = op1 * op2;
    return SIN_ERROR;
}
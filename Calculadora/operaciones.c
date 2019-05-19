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

int potencia_entera(float op1,float op2,float* rta){

    int exponente = ( (op2<0)? (int) -op2 : (int) op2 );
    int signo = ( (op2<0)? NEGATIVO : POSITIVO );
    int i;
    float aux=1.0;
    
    if(op1 == 0. && signo == NEGATIVO){
        printf("potencia: ERROR: base 0 y exponente negativo\nC program: Am I a joke to you?\n");
        return ERROR;
    }
    
    for(i=0;i<exponente;i++){
        aux *= op1;
    }
    if (signo==NEGATIVO){
        aux = 1./aux;
    }
    
    *rta = aux;
    return SIN_ERROR;
}
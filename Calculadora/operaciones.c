#include <stdio.h>
#include "general.h"
#include "operaciones.h"

int suma(float op1,float op2,float* rta){//suma dos numeros
    *rta = op1 + op2;
    return SIN_ERROR;
}
int resta(float op1,float op2,float* rta){//resta dos numeros
    *rta = op1 - op2;
    return SIN_ERROR;
}
int division(float op1,float op2,float* rta){//divide dos numeros
    if(op2 == 0){//si el divisor es 0, informa el error
        printf("division: ERROR: division por 0\nACASO QUIERES QUE EXPLOTE EL UNIVERSO?!\n");
        return ERROR;
    }
    *rta = op1 / op2;
    return SIN_ERROR;
}
int multiplicacion(float op1,float op2,float* rta){//multiplica dos numeros
    *rta = op1 * op2;
    return SIN_ERROR;
}

int potencia_entera(float op1,float op2,float* rta){//eleva un nùmero float a un exponente entero (casteado)

    int exponente = ( (op2<0)? (int) -op2 : (int) op2 );//valor absoluto del exponente (casteado)
    int signo = ( (op2<0)? NEGATIVO : POSITIVO );//signo del exponente
    int i;//contador auxiliar
    float aux=1.0;//variable auxiliar para los calculos
    
    if(op1 == 0. && signo == NEGATIVO){//Si se elevò 0 a una potencia negativa, informa el error
        printf("potencia: ERROR: base 0 y exponente negativo\nC program: Am I a joke to you?\n");
        return ERROR;
    }
    
    for(i=0;i<exponente;i++){//multiplica la base tantas veces como indica el exponente
        aux *= op1;
    }
    if (signo==NEGATIVO){//si el exponente era negativo, invierte el nùmero
        aux = 1./aux;
    }
    
    *rta = aux;//guarda la respuesta
    return SIN_ERROR;//programa exitoso
}
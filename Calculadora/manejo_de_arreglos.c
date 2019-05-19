#include <stdio.h>
#include "general.h"
#include "manejo_de_arreglos.h"

#define MAX 50  //cantidad maxima de operaciones añadibles

//NOTA: se opto que los arreglos sean locales a este archivo, dado que son las unicas funciones
//que los manipulan
//Se añade un espacio extra por cada arreglo, para colocar el terminador correspondiente ('\0' o NULL)

static char operators [MAX+1] = {'\0'};
static int (*actions[MAX+1])(float,float,float*) = {NULL};

int add_op(char simbolo, int(*funcion)(float,float,float*) ){
    
    static int indice=0; // Apunta a la proxima posicion libre de los arreglos
    int i;
    
    if(indice>=MAX){
        printf("AddOp: ERROR: Se excedió el número máximo de operaciones agregables\0");
        return ERROR;
    }

    for(i=0;i<indice;i++){
        if(simbolo==operators[i]){
            printf("AddOp: ERROR: Simbolo de operación repetido\n");
            return ERROR;
        }
    }
    
    operators[indice]=simbolo;
    actions[indice]=funcion;
    
    indice++;
    
    operators[indice]='\0';
    actions[indice]=NULL;
    
    return SIN_ERROR;
    
}

int existe_op(char simbolo){
    int i;

    for(i=0;operators[i]!='\0';i++){
        if(operators[i]==simbolo){
            return VERDAD;
        }
    }
    return FALSO;
}

int operador(float op1,float op2,char simbolo,float* rta){
    int i;
    int error=SIN_ERROR;
    
    for(i=0;operators[i]!='\0';i++){
        if(operators[i]==simbolo){
            error = (*actions[i])(op1,op2,rta);
            return error;
        }
    }
    printf("Operador: ERROR: Operación desconocida\n");
    return ERROR;
}



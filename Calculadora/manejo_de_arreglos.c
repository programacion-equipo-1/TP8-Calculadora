#include <stdio.h>
#include "general.h"
#include "manejo_de_arreglos.h"

#define MAX 50  //cantidad maxima de operaciones añadibles

//NOTA: se opto que los arreglos sean locales a este archivo, dado que son las unicas funciones
//que los manipulan
//Se añade un espacio extra por cada arreglo, para colocar el terminador correspondiente ('\0' o NULL)

static char operators [MAX+1] = {'\0'}; //Arreglo de símbolos de las operaciones
static int (*actions[MAX+1])(float,float,float*) = {NULL}; //Arreglo de punteros a las funciones que
                                                            //realizan dichas operaciones

int add_op(char simbolo, int(*funcion)(float,float,float*) ){ //Añade una nueva operacion a los arreglos
    
    static int indice=0; // Apunta a la proxima posicion libre de los arreglos
    int i; //Contador auxiliar
    
    if(indice>=MAX){ //Si los arreglos estan llenos, informa el error
        printf("AddOp: ERROR: Se excedió el número máximo de operaciones agregables\n");
        return ERROR;
    }

    for(i=0;i<indice;i++){ //Si el sìmbolo ingresado ya existe en los arreglos, informa el error
        if(simbolo==operators[i]){
            printf("AddOp: ERROR: Simbolo de operación repetido\n");
            return ERROR;
        }
    }
    //Si no ocurrio ningun error...
    operators[indice]=simbolo; //Ingresa el nuevo símbolo y el puntero a la funcion correspondiente
    actions[indice]=funcion;
    
    indice++; //Avanza el índice a la próxima posición libre
    
    operators[indice]='\0'; //Y coloca allí los terminadores
    actions[indice]=NULL;
    
    return SIN_ERROR; //Fin exitoso del programa
    
}

int existe_op(char simbolo){ //Testea si un determinado símbolo de operación ya fue ingresado
    int i; //contador auxiliar

    for(i=0;operators[i]!='\0';i++){ //Si encuentra el símbolo en el arreglo, lo informa
        if(operators[i]==simbolo){
            return VERDAD;
        }
    }
    return FALSO; //Si llegó hasta el terminador, entonces no existe dicha operación
}

int operador(float op1,float op2,char simbolo,float* rta){//Deriva a la función que realiza la
                                                            //operacion correspondiente
    int i;//Contador auxiliar
    int error=SIN_ERROR;//Indicador de error auxiliar
    
    for(i=0;operators[i]!='\0';i++){//Recorre el arreglo de operaciones
        if(operators[i]==simbolo){//Si encuentra la operacion a realizar
            error = (*actions[i])(op1,op2,rta);//La ejecuta...
            return error;//...y segun si ocurrió un error (como dividir por 0), informa el error en dicho caso
        }
    }
    printf("Operador: ERROR: Operación desconocida\n");//Si no existe tal operacion, informa el error
    return ERROR;
}



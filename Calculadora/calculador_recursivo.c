#include <stdio.h>
#include "general.h"
#include "calculador_recursivo.h"
#include "manejo_de_arreglos.h"
#include "numeros_y_cadenas.h"

//ACLARACION

// next: direccion del puntero que apunta al arreglo de punteros, cada uno de los cuales apunta a un argumento
// *next: puntero que apunta a un elemento arreglo de punteros
// (*next)++: avanza el puntero al proximo elemento del arreglo de punteros, es decir, al proximo argumento
// **next: puntero, dentro del arreglo, que apunta a un argumento especifico (cadena de caracteres)
// ***next: primer caracter del argumento apuntado actualmente

//Idealmente, *next, o el puntero que apunta al arreglo de punteros, se encuentra definido como una variable
// en la funcion que llama a este modulo

/*                                              char* argv[]
 *      char*** next      char** argumento       __________
 *       __________        ___________          |__________| -------> "calculadora"
 *      |___next___| ---> |___*next___| ------> |__**next__| -------> "+"
 *                                              |__________| -------> "27"
 *      Manipulada          Creada en           |__________| -------> "42"
 *      por la              el main             |___NULL___|
 *      calculadora
 *      recursiva
 * 
 * 
 */

int calculador_recursivo(char*** next,float* rta){
    
    float operando1;
    float operando2;
    char operacion;
    int error=FALSO;
    
    if(**next == NULL){
        printf("Calc: ERROR: FALTA ARGUMENTO - Se esperaba una operación\n");
        return ERROR;
    }
    if(is_a_number(**next)==VERDAD){
        printf("Calc: ERROR: Se esperaba una operación - Se encontró un número\n");
        return ERROR;
    }
    if( (**next)[1] != '\0' || existe_op(***next) == FALSO ){
        printf("Calc: ERROR: Operación inválida/desconocida\n");
        return ERROR;
    }
    operacion = ***next;
    (*next)++;
    
    
    if(**next == NULL){
        printf("Calc: ERROR: FALTA ARGUMENTO - Se esperaba un número\n");
        return ERROR;
    }
    if(is_a_number(**next)==VERDAD){
        str2float(**next,&operando1);
    }else{
        error = calculador_recursivo(next,&operando1);
        if (error==VERDAD){
            return ERROR;
        }
    }
    (*next)++;
    
    if(**next == NULL){
        printf("Calc: ERROR: FALTA ARGUMENTO - Se esperaba un número\n");
        return ERROR;
    }
    if(is_a_number(**next)==VERDAD){
        str2float(**next,&operando2);
    }else{
        error = calculador_recursivo(next,&operando2);
        if (error==VERDAD){
            return ERROR;
        }
    }
    
    
    error = operador(operando1,operando2,operacion,rta);
    if (error==VERDAD){
        printf("Calc: ERROR: error durante la operación");
        return ERROR;
    }
    return SIN_ERROR;
    
}
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
    
    //Nota: los argumentos son leidos empleando la notación polaca
    
    // BUSQUEDA DE LA OPERACION
    
    if(**next == NULL){ //Si el argumento actual es NULL, notifica el error
        printf("Calc: ERROR: FALTA ARGUMENTO - Se esperaba una operación\n");
        return ERROR;
    }
    if(is_a_number(**next)==VERDAD){ //Si es un número, notifica el error
        printf("Calc: ERROR: Se esperaba una operación - Se encontró un número\n");
        return ERROR;
    }
    if( (**next)[1] != '\0' || existe_op(***next) == FALSO ){
        // Si no es una operación presente en el arreglo de operaciones válidas,
        //o la misma está compuesta por más de un caracter, notifica el error
        printf("Calc: ERROR: Operación inválida/desconocida\n");
        return ERROR;
    }
    operacion = ***next; //Si no hubo error, el argumento es una operación válida
    (*next)++; //avanza al siguiente argumento
    
    // BUSQUEDA DEL PRIMER OPERANDO
    
    if(**next == NULL){ //Si el argumento actual es NULL, notifica el error
        printf("Calc: ERROR: FALTA ARGUMENTO - Se esperaba un número\n");
        return ERROR;
    }
    if(is_a_number(**next)==VERDAD){ //Si es un número (con formato válido)
        str2float(**next,&operando1); //...lo transforma en float
    }else{ //Si no es un número, debe ser una nueva operación.
        //En dicho caso, se derivará de manera recursiva a una nueva instancia del calculador
        error = calculador_recursivo(next,&operando1); //Se pregunta si dicha instancia no tuvo errores
        if (error==VERDAD){ //Si hubo un error...
            return ERROR; //...lo informa y sale inmediatamente
        }
    }
    (*next)++;//Avanza al próximo argumento
    
    // BUSQUEDA DEL SEGUNDO OPERANDO
    // Se realiza del mismo modo que con el primer operando...
    
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
    //...excepto porque no se avanza el ìndice al próximo argumento. Así, todas las intancias del
    //calculador acaban apuntando al último argumento empleado
    
    
    //realiza la operación deseada, y se pregunta si hubo un error durante la operación
    error = operador(operando1,operando2,operacion,rta);//al mismo tiempo, se escribe la respuesta en *rta
    if (error==VERDAD){ //Si hubo un error durante la operación, lo notifica
        printf("Calc: ERROR: error durante la operación\n");
        return ERROR;
    }
    return SIN_ERROR; //Si el programa se ejecuto sin errores, finaliza aqui
    
}
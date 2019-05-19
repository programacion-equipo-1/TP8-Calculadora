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
    
    if(){
        
    }
    
    
    
}
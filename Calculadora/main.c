/* 
 * File:   main.c
 * Author: tefi
 *
 * Created on May 18, 2019, 7:15 PM
 */

#include <stdio.h>
#include "general.h"
#include "operaciones.h"
#include "manejo_de_arreglos.h"
#include "calculador_recursivo.h"


#define agregar(simbolo,funcion) (error = error || add_op(simbolo,funcion))

int main(int argc, char* argv[]) {
    
    char** argumento = argv+1;
    int error = FALSO;
    float resultado;
    
    
    agregar('+',&suma);
    agregar('-',&resta);
    agregar('x',&multiplicacion);
    agregar('/',&division);
    if (error == VERDAD){
        printf("Main: ERROR DE INICIALIZACIÓN - Programa abortado\n");
        return 0;
    }
    
    error = calculador_recursivo(&argumento,&resultado);
    if (error == VERDAD){
        printf("Main: ERROR DE OPERACIÓN - Programa abortado\n");
        return 0;
    }
    
    printf("RESULTADO:\n\t%f\n",resultado);
    printf("Que tenga un maravilloso día ♡ ♡ ♡\n");

    return 0;
}
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
    int error = FALSO;
    agregar('+',&suma);
    agregar('-',&resta);
    agregar('*',&multiplicacion);
    agregar('/',&division);
    if (error == VERDAD){
        printf("Main: ERROR DE INICIALIZACIÓN - Programa abortado\n");
        return 0;
    }
    
    
    
    
    return 0;
}


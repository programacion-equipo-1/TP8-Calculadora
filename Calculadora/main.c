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

void test(void);

#define agregar(simbolo,funcion) (error = error || add_op(simbolo,funcion))

int main(int argc, char* argv[]) {
    
    char** argumento = argv+1;
    int error = FALSO;
    float resultado;
    
    
    agregar('+',&suma);
    agregar('-',&resta);
    agregar('*',&multiplicacion);
    agregar('/',&division);
    if (error == VERDAD){
        printf("Main: ERROR DE INICIALIZACIÓN - Programa abortado\n");
        return 0;
    }
    
    test();
    
//    error = calculador_recursivo(&argumento,&resultado);
//    if (error == VERDAD){
//        printf("Main: ERROR DE OPERACIÓN - Programa abortado\n");
//        return 0;
//    }
    
//    printf("RESULTADO:\n\t%f\n",resultado);
//    printf("Que tenga un maravilloso día ♡ ♡ ♡\n");

//    return 0;
}

void test (void){
    
    float f;
    if (str2float("2e20",&f) == SIN_ERROR){
        printf("%g\n",f);
    }
    if (str2float("+.2e-0",&f) == SIN_ERROR){
        printf("%g\n",f);
    }
    if (str2float("00000024.100000",&f) == SIN_ERROR){
        printf("%g\n",f);
    }
    if (str2float("17e+",&f) == SIN_ERROR){
        printf("%g\n",f);
    }
    if (str2float("2e0004",&f) == SIN_ERROR){
        printf("%g\n",f);
    }
    
    printf("%i\n",is_a_number("24e"));
}
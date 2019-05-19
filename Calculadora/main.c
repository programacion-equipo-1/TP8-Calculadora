/* 
 * File:   main.c
 * Author: tefi
 *
 * Created on May 18, 2019, 7:15 PM
 */

/*
 *          IMPORTANTE
 * 
 *  La calculadora funciona con notacion polaca
 *  Actualmente se encuentran disponibles las operaciones
 *  + suma
 *  - resta
 *  x producto
 *  / division
 *  ^ potencia (de exponente entero; el exponente sera casteado a INT antes de operar)
 * 
 *  Las funciones son incluidas en los arreglos del modulo MANEJO DE ARREGLOS cada vez que
 * se inicia el programa (siguiendo con la consigna)
 *  La diferencia es que dichos arreglos no son globales a todos los modulos, sino internos
 * al modulo MANEJO DE ARREGLOS, puesto a que es el unico modulo que los emplea
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
    agregar('^',&potencia_entera);
    if (error == VERDAD){
        printf("Main: ERROR DE INICIALIZACIÓN - Programa abortado\n");
        return 0;
    }
    
    error = calculador_recursivo(&argumento,&resultado);
    if (error == VERDAD){
        printf("Main: ERROR DE OPERACIÓN - Programa abortado\n");
        return 0;
    }
    
    printf("RESULTADO:\n\t%g\n",resultado);
    printf("Que tenga un maravilloso día ♡ ♡ ♡\n");

    return 0;
}
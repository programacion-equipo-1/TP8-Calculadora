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

// EJEMPLO DE USO: ./calculadora + x - 4 2 3 / ^ 3 2 3

#include <stdio.h>
#include "general.h"
#include "operaciones.h"
#include "manejo_de_arreglos.h"
#include "calculador_recursivo.h"

//Esta macro facilita la incializaciòn de las operaciones realizables por la calculadora
#define agregar(simbolo,funcion) (error = error || add_op(simbolo,funcion))

int main(int argc, char* argv[]) {
    
    char** argumento = argv+1;//Apunta, dentro del arreglo argv, al primer argumento despues del nombre del programa
    int error = FALSO;//indicador de error auxiliar
    float resultado;//resultado de las operaciones
    
    //Agrega las operaciones que puede realizar la  calculadora
    agregar('+',&suma);
    agregar('-',&resta);
    agregar('x',&multiplicacion);
    agregar('/',&division);
    agregar('^',&potencia_entera);
    
    if (error == VERDAD){//Si ocurrio un error durante esta inicializacion, lo informa
        printf("Main: ERROR DE INICIALIZACIÓN - Programa abortado\n");
        return 0;
    }
    
    error = calculador_recursivo(&argumento,&resultado);//llama al calculador recursivo para que
                                                        //realice las operaciones ingresadas
    
    if (error == VERDAD){//Si ocurrio un error de operacion (ej, dividir por 0) lo informa
        printf("Main: ERROR DE OPERACIÓN - Programa abortado\n");
        return 0;
    }
    
    printf("RESULTADO:\n\t%g\n",resultado);//Si no ocurrio ningun error, imprime el resultado
    printf("Que tenga un maravilloso día ♡ ♡ ♡\n"); //Aww que tierno...

    return 0;
}
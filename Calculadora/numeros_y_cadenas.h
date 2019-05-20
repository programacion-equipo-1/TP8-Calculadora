/* 
 * File:   numeros_y_cadenas.h
 * Author: tefi
 *
 * Created on May 18, 2019, 7:23 PM
 */

//Funciones encargadas de manipular cadenas de caracteres que representan números
//NOTA: son altamente reutilizables en futuros proyectos

#ifndef NUMEROS_Y_CADENAS_H
#define NUMEROS_Y_CADENAS_H

//  STR2FLOAT (string to float)
//  Recibe
//  -Puntero a una cadena de caracteres
//  -Puntero a un float donde guardar el resultado
//  Entrega
//  -Indicador de error
//  Funcion
//  -Transforma el contenido de la cadena de caracteres en un número float.
//  Se acepta el siguiente formato
//
//  [+/-] [num] [.] [num] [e/E] [+/-] [num]
//
//  Ejemplos válidos:
//      5
//      .2
//      7e-4
//      +25
//      -.05E+2
//  Ejemplos inválidos:
//      .
//      --8
//      25E
//      +.E5
int str2float(char* cadena,float* numero);

//  IS A NUMBER
//  Recibe:
//  -Puntero a una cadena de caracteres
//  Devuelve:
//  -Indicador que informa si la cadena de caracteres tiene el formato adecuado para
//   ser transformado a un float. Es decir, si es un número válido
int is_a_number(char* cadena);

#endif /* NUMEROS_Y_CADENAS_H */


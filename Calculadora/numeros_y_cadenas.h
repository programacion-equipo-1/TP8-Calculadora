/* 
 * File:   numeros_y_cadenas.h
 * Author: tefi
 *
 * Created on May 18, 2019, 7:23 PM
 */

/* NICO: completar el .c y comentar el .h 
 
 Funcion: is_a_number:
 * Toma un puntero a char y devuelve si el string es un numero. Admite numeros negativos y con coma.
 * Para la validacion, de ser un numero devuelve un 1 o un 0 si no lo es. 
 
 Funcion str2float
 * Toma como parametros un puntero a char, es decir un strimg y un puntero a float
 * Recorre el string armando un numero float.
 * Coloca en la direccion de memoria del puntero a float el numero y retorna 1.
 * De no ser valido no se modifica la memoria que aplunta el float y se retorna 0.
 * 
 * 
 
 
 */

#ifndef NUMEROS_Y_CADENAS_H
#define NUMEROS_Y_CADENAS_H

int str2float(char* cadena,float* numero);
int is_a_number(char* cadena);

#endif /* NUMEROS_Y_CADENAS_H */

